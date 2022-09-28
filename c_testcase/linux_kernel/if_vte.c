//
// case from DSAC paper Figure 6 (c), codes extracted from
//   netbsd-7.1/sys/dev/pic/if_vte.c,
//   identify may-sleep function in interrupt handler
//

#include "dsac_poc.h"

int
vte_newbuf(struct vte_softc *sc, struct vte_rxdesc *rxd)
{
  /* struct mbuf *m = NULL; */

  // bus_dmamap_load_mbfu may sleep due to last parameter "0"
  if (bus_dmamap_load_mbuf(/*sc->vte_dmatag, sc->vte_cdata.vte_rx_sparemap, m,*/ 0) != 0) {
    // ...
  }
  // ...

  return (0);
}

void
vte_rxeof(struct vte_softc *sc)
{
  struct vte_rxdesc *rxd = NULL;
  // ...
  if (vte_newbuf(sc, rxd) != 0) {
    // ...
  }
}

int
vte_intr(void *arg) // interrupt handler
{
  struct vte_softc *sc = (struct vte_softc *)arg;

  // ...
  if (sc != NULL)
    vte_rxeof(sc);
  // ...
  return 1;
}

void
vte_attach(void* arg)
{
  // somewhere calls vte_intr()
  if(!vte_intr(arg)) {
    printf("SOMETHING true!\n");
  }
  printf("ALL!\n");
}
