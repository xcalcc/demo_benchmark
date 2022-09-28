//
//  case from DSAC paper Figure 1, codes extracted form
//    linux-2.6.38/drivers/usb/gadget/mv_udc_code,
//    identify may-sleep function in atomic context.
//

#include "dsac_poc.h"

struct mv_dtd *build_dtd(struct mv_req *req, unsigned *length,
                         dma_addr_t *dma, int *is_last)
{
  struct mv_dtd *dtd;
  struct mv_udc *udc;

  udc = req->ep->udc;

  dtd = (struct mv_dtd*)dma_pool_alloc(udc->dtd_pool, GFP_KERNEL, dma); // dma_pool_alloc may sleep due to GFP_KERNEL

  return dtd;
}

/* generate dTD linked list for a request */
int req_to_dtd(struct mv_req *req)
{
  unsigned count;
  int is_last = 1, is_first = 1;
  struct mv_dtd *dtd, *last_dtd = NULL;
  struct mv_udc *udc;
  dma_addr_t dma;

  udc = req->ep->udc;

  do {
    dtd = build_dtd(req, &count, &dma, &is_last);
  } while (!is_last);
  
  return 0;
}

/* queues (submits) an I/O request to an endpoint */
int
mv_ep_queue(struct mv_ep *ep, struct mv_req *req, gfp_t gfp_flags)
{
  struct mv_udc *udc = ep->udc;
  unsigned long flags = 0;
  
  spin_lock_irqsave(&udc->lock, flags); // atomic context starts
  
  /* build dtds and push them to device queue */
  if (!req_to_dtd(req)) {
  }

  spin_unlock_irqrestore(&udc->lock, flags); // atomic context ends

  // uncommented to verify false positive
  req_to_dtd(req);

  return 0;
}
