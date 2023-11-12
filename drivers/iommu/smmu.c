#include <target/init.h>
#include <target/iommu.h>
#include <target/console.h>
#include <target/panic.h>

struct smmu_device smmu_devices[NR_IOMMU_DEVICES];
struct smmu_stream smmu_streams[NR_IOMMU_GROUPS];
struct smmu_context smmu_contexts[NR_IOMMU_DOMAINS];

void smmu_gr_restore(smmu_gr_t gr)
{
	smmu_device_ctrl.gr = gr;
}

smmu_gr_t smmu_gr_save(smmu_gr_t gr)
{
	smmu_gr_t sgr = smmu_device_ctrl.gr;

	smmu_gr_restore(gr);
	return sgr;
}

void smmu_group_select(void)
{
	smmu_sme_t sme = smmu_stream_ctrl.sme;
	smmu_gr_t gr = smmu_sme_gr(sme);

	BUG_ON(smmu_sme_dev(sme) != iommu_dev);
	smmu_gr_restore(gr);
}

void smmu_cb_restore(smmu_cb_t cb)
{
	smmu_device_ctrl.cb = cb;
}

smmu_cb_t smmu_cb_save(smmu_cb_t cb)
{
	smmu_cb_t scb = smmu_device_ctrl.cb;

	smmu_cb_restore(cb);
	return scb;
}

void smmu_domain_select(void)
{
	smmu_cb_restore(smmu_context_ctrl.cb);
}

smmu_cb_t smmu_alloc_cb(smmu_cb_t start, smmu_cb_t end)
{
	smmu_cb_t cb;

	cb = find_next_clear_bit(smmu_device_ctrl.context_map,
				 end, start);
	if (cb == end)
		return INVALID_SMMU_CB;
	test_bit(cb, smmu_device_ctrl.context_map);
	return cb;
}

void smmu_free_cb(smmu_cb_t cb)
{
	clear_bit(cb, smmu_device_ctrl.context_map);
}

iommu_grp_t smmu_find_sme(smmu_gr_t gr, smmu_gr_t sm)
{
	__unused iommu_grp_t grp = INVALID_IOMMU_GRP, sgrp;
	smmu_sme_t sme;
	smmu_gr_t sme_gr, sme_sm;

	sgrp = iommu_group_save(grp);
	for (grp = 0; grp < NR_IOMMU_GROUPS; ++grp) {
		iommu_group_restore(sgrp);
		sgrp = iommu_group_save(grp);

		/* Skip other SMMU devices */
		if (iommu_group_ctrl.dev != iommu_dev)
			continue;

		sme = smmu_stream_ctrl.sme;
		BUG_ON(smmu_sme_dev(sme) != iommu_dev);
		sme_gr = smmu_sme_gr(sme);
		sme_sm = smmu_sme_sm(sme);

		/* No harm to re-use matched existing stream mapping */
		if ((sm & sme_sm) == sm && !((gr ^ sme_gr) & ~sme_sm))
			break;

		/* Avoid conflict stream mapping */
		if (!((gr ^ sme_gr) & ~(sme_sm | sm))) {
			con_err("smmu: conflict stream: 0x%04x/0x%04x.",
				gr, sm);
			iommu_group_restore(sgrp);
			return INVALID_IOMMU_GRP;
		}
	}
	iommu_group_restore(sgrp);
	return grp == INVALID_IOMMU_GRP ? iommu_alloc_group() : grp;
}

void smmu_free_sme(iommu_grp_t grp)
{
	__unused iommu_grp_t sgrp;

	sgrp = iommu_group_save(grp);
	if (smmu_stream_ctrl.count > 0)
		smmu_stream_ctrl.count--;
	if (smmu_stream_ctrl.count == 0) {
		smmu_stream_ctrl.sme = INVALID_SMMU_SME;
		smmu_write_s2cr(SMMU_S2CR_TYPE_INIT, 0, 0, false);
		smmu_write_smr(0, 0, false);
		iommu_free_group(grp);
	}
	iommu_group_restore(sgrp);
}

iommu_grp_t smmu_alloc_sme(smmu_sme_t sme)
{
	__unused iommu_dev_t dev, sdev;
	__unused iommu_grp_t grp, sgrp;
	smmu_gr_t gr, sm;

	dev = smmu_sme_dev(sme);
	gr = smmu_sme_gr(sme);
	sm = smmu_sme_sm(sme);
	sdev = iommu_device_save(dev);
	grp = smmu_find_sme(gr, sm);
	if (grp != INVALID_IOMMU_GRP) {
		sgrp = iommu_group_save(grp);
		if (smmu_stream_ctrl.count == 0) {
			smmu_stream_ctrl.sme = sme;
			smmu_write_smr(gr, sm, true);
		}
		smmu_stream_ctrl.count++;
		iommu_group_restore(sgrp);
	}
	iommu_device_restore(sdev);
	return grp;
}

void smmu_device_exit(void)
{
	smmu_disable(iommu_dev);
}

void smmu_device_init(void)
{
	smmu_probe_ids();
	smmu_device_reset();
	smmu_test_smr_masks();
}
