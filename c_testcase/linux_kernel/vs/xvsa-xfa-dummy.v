{
 "scanFile":[
  { "id": 1, "name": "/benchmark/testcase/demo_benchmark/c_testcase/linux_kernel/mv_udc_core.c" },
  { "id": 2, "name": "/usr/include/bits/stdio.h" },
  { "id": 3, "name": "/usr/include/libio.h" },
  { "id": 4, "name": "/benchmark/testcase/demo_benchmark/c_testcase/linux_kernel/dsac_poc.h" },
  { "id": 5, "name": "/usr/include/bits/sys_errlist.h" },
  { "id": 6, "name": "/benchmark/testcase/demo_benchmark/c_testcase/linux_kernel/if_vte.c" },
  { "id": 7, "name": "/usr/include/bits/stdio.h" },
  { "id": 8, "name": "/usr/include/libio.h" },
  { "id": 9, "name": "/benchmark/testcase/demo_benchmark/c_testcase/linux_kernel/dsac_poc.h" },
  { "id": 10, "name": "/usr/include/bits/sys_errlist.h" },
  { "id": 11, "name": "/benchmark/testcase/demo_benchmark/c_testcase/linux_kernel/dsac_rule.cxx" },
  { "id": 12, "name": "/home/xcalibyte/xvsa/include/rbc_base.h" },
  { "id": 13, "name": "/usr/include/bits/sys_errlist.h" },
  { "id": 14, "name": "/usr/include/stdio.h" },
  { "id": 15, "name": "/usr/include/libio.h" }
 ],
 "issue":[
  { "fileno":1, "lineno":47, "colno":0, "key":"/benchmark/testcase/demo_benchmark/c_testcase/linux_kernel/mv_udc_core.c@mv_ep_queue@dma_pool_alloc@RBC@USER@SAC@ffffffe6", "category":"Vul", "severity":"D", "vulname":"RBC", "errcode":"SAC", "varname":"dma_pool_alloc", "funcname":"mv_ep_queue",
   "path": [
    { "fileno":1, "lineno":47, "message":"Vulnerable spot" },
    { "fileno":1, "lineno":50, "message":"Function call" },
    { "fileno":1, "lineno":34, "message":"Function call" },
    { "fileno":1, "lineno":17, "message":"Rule base check spot" },
    { "fileno":1, "lineno":47, "message":""}
   ]
  }  { "fileno":6, "lineno":49, "colno":0, "key":"/benchmark/testcase/demo_benchmark/c_testcase/linux_kernel/if_vte.c@vte_attach@bus_dmamap_load_mbuf@RBC@USER@SAC@ffffffe0", "category":"Vul", "severity":"D", "vulname":"RBC", "errcode":"SAC", "varname":"bus_dmamap_load_mbuf", "funcname":"vte_attach",
   "path": [
    { "fileno":6, "lineno":49, "message":"Vulnerable spot" },
    { "fileno":6, "lineno":49, "message":"Function call" },
    { "fileno":6, "lineno":40, "message":"Function call" },
    { "fileno":6, "lineno":28, "message":"Function call" },
    { "fileno":6, "lineno":15, "message":"Rule base check spot" },
    { "fileno":6, "lineno":49, "message":""}
   ]
  }
 ],
 "mvsaRecord": {
  "message": "@@MESSAGE@@",
  "vcsTool": "@@VCSTOOL@@",
  "vcsRepo": "@@VCSREPO@@",
  "vcsVersion": "@@VCSVERSION@@",
  "engine": "xcalibyte",
  "engineVersion": "1.0",
  "scanMode": "cfa",
  "scanParameter": "UIV:1,AOB:1,NPD:1,RBC:1,UBF:1,UAF:1,MSF:1,DBF:1,DDV:0,RAL:1,RVSA:0,MUCHI:1,NOT_MUCHI:1,HOR:1,JSON:1",
  "environment": "HOME=/root,HOSTNAME=40332522297e,LANG=C.UTF-8,LD_LIBRARY_PATH=/home/xcalibyte/xvsa/bin/../i686-pc-linux-gnu/x86_64-linux/lib:/home/xcalibyte/xvsa/lib/1.0,PATH=/home/xcalibyte/xvsa/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin,PWD=/benchmark/testcase/demo_benchmark/c_testcase/linux_kernel/objects,",
  "logPath": "xvsa-xfa-dummy.v",
  "cmdLine": "be -VSA:json=1 -TARG:abi=n64 -VSA:certc=1 xvsa-xfa-dummy.c",
  "scanStarted": 1556459500503900,
  "scanEnded": 1556459500717568,
  "reservedK1": "reservedV1",
  "reservedK2": "reservedV2",
  "reservedK3": "reservedV3",
  "reservedK4": "reservedV4",
  "reservedK5": "reservedV5"
 }
}
