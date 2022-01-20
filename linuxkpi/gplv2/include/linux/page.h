#ifndef	_LINUX_GPLV2_PAGE_H_
#define _LINUX_GPLV2_PAGE_H_

#include_next <linux/page.h>

#include <sys/param.h>
#if ((__FreeBSD_version <= 1400033) && (__FreeBSD_version >= 1400000) || \
     (__FreeBSD_version <= 1300516))
#define PAGE_KERNEL_IO  0x0000

/* XXX note that this is incomplete */
void *kmap(vm_page_t page);
void *kmap_atomic(vm_page_t page);
void *kmap_atomic_prot(vm_page_t page, pgprot_t prot);
void kunmap(vm_page_t page);
void kunmap_atomic(void *vaddr);

void iounmap_atomic(void *vaddr);
#endif

static inline int
page_count(vm_page_t page __unused)
{
	return (1);
}

int set_pages_array_wb(struct page **pages, int addrinarray);
int set_pages_array_uc(struct page **pages, int addrinarray);
int set_pages_array_wc(struct page **pages, int addrinarray);

int set_pages_wb(vm_page_t page, int numpages);
int set_pages_uc(vm_page_t page, int numpages);
int set_pages_wc(vm_page_t page, int numpages);

#if ((__FreeBSD_version <= 1400033) && (__FreeBSD_version >= 1400000) || \
     (__FreeBSD_version <= 1300516))
vm_paddr_t page_to_phys(vm_page_t page);

void unmap_mapping_range(void *obj, loff_t const holebegin,
    loff_t const holelen, int even_cows);

#define linux_clflushopt(arg) __linux_clflushopt((u_long)(arg))
extern void __linux_clflushopt(u_long addr);
#endif

#endif	/* _LINUX_PAGE_H_ */