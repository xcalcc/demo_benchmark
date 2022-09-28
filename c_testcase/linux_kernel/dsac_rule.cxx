//
// file for side effect marking & assertion placing
//

#include "dsac_poc.h"
#include "rbc_base.h"

#ifdef __cplusplus
extern "C" {
#endif

extern RBC_ENGINE rbc;


void *dma_pool_alloc(struct dma_pool *pool, gfp_t mem_flags, dma_addr_t *handle)
{
  rbc.Model_decl(rbc.Set_func_may_sleep(rbc.Get_arg(2))); // set dma_pool_alloc may sleep according to mem_flags
  return NULL;
}


void spin_lock_irqsave(spinlock_t *lock, unsigned long flags)
{
  rbc.Model_decl(rbc.Set_atomic_region_begin()); // marking start of an atomic context.

  rbc.Rbc_assert(rbc.Do_not_call_sleep_in_atm(), "SAC");

  rbc.Rbc_declare_rule_info("SAC", "DSAC_POC", "Call may sleep function in atomic context.");
  return;
}


void spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags)
{
  rbc.Model_decl(rbc.Set_atomic_region_end()); // marking end of an atomic context
  return;
}


int vte_intr(void *arg)
{
  rbc.Model_decl(rbc.Set_func_atomic()); // marking function in atomic context

  rbc.Rbc_apply_rule("SAC"); // reuse rule "SAC" defined in spin_lock_irqsave
  return 0;
}


int bus_dmamap_load_mbuf(int flags)
{
  rbc.Model_decl(rbc.Set_func_may_sleep(rbc.Get_arg(1))); // set bus_dmamap_load_mbuf may sleep according to flags

  return 0;
}


#ifdef __cplusplus
} // extern C
#endif
