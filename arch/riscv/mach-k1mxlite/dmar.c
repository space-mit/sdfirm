#include <target/dma.h>
#include <target/iommu.h>

iommu_t k1mxlite_dmac_iommus[NR_DMAC_DMAS] = {
	IOMMU_DMA_TBU0,
	IOMMU_DMA_TBU1,
	IOMMU_DMA_TBU2,
	IOMMU_DMA_TBU3,
};

iommu_grp_t k1mxlite_dmac_iommu;

dma_addr_t dma_hw_map_single(dma_t dma, phys_addr_t ptr,
			     size_t size, dma_dir_t dir)
{
	__unused iommu_dom_t dom, sdom;
	dma_addr_t iova;
	int prot, ret;

	dom = iommu_get_domain(k1mxlite_dmac_iommus[dma]);

	sdom = iommu_domain_save(dom);
	prot = dma_info_to_prot(dma_direction(dma),
				dma_is_coherent(dma), 0);
	iova = iommu_iova_alloc(dom, size);
	ret = iommu_map(iova, ptr, size, prot);
	iommu_domain_restore(sdom);
	return ret == 0 ? (dma_addr_t)iova : 0;
}

void dma_hw_unmap_single(dma_t dma, dma_addr_t addr,
			 size_t size, dma_dir_t dir)
{
}

void dmac_hw_ctrl_init(void)
{
	dma_t dma;

	for (dma = 0; dma < NR_DMAS; dma++) {
		dma_register_channel(dma, SVT_DMAC_CAPS);
		dma_clr_direct(dma);
	}
	iommu_register_dma(ARRAY_SIZE(k1mxlite_dmac_iommus),
				      k1mxlite_dmac_iommus);
}
