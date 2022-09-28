#include <stdio.h>

/* #define ___GFP_WAIT		0x10u */
/* #define ___GFP_IO		0x40u */
/* #define ___GFP_FS		0x80u */

/* #define GFP_KERNEL	(__GFP_WAIT | __GFP_IO | __GFP_FS) */

#define GFP_KERNEL (0x10u | 0x40u | 0x80u)

typedef int gfp_t;
typedef unsigned dma_addr_t;

struct dma_pool{
  // somthing we don't care
  int sth;
};

typedef struct {
  volatile unsigned int slock;
} arch_spinlock_t;

typedef struct {
  arch_spinlock_t raw_lock;
  void *owner;
} spinlock_t;

struct mv_dtd {
  // other things we don't care
  int others;
};

struct mv_udc{
  struct dma_pool *dtd_pool;
  spinlock_t lock;
};

struct mv_ep{
  struct mv_udc *udc;
};

struct mv_req{
  struct mv_ep *ep;
};

struct vte_softc{
  // something we don't care
  int sth;
};

struct vte_rxdesc{
  // something we don't care
  int sth;
};

struct mbuf{
  // something we don't care
  int sth;
};

#ifdef __cplusplus
extern "C" {
#endif

void *dma_pool_alloc(struct dma_pool *pool, gfp_t mem_flags,
                     dma_addr_t *handle);

void spin_lock_irqsave(spinlock_t *lock, unsigned long flags);
void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags);

int vte_intr(void *arg);
int bus_dmamap_load_mbuf(/*skip parms do not matter*/ int flags);

#ifdef __cplusplus
} // extern C
#endif
