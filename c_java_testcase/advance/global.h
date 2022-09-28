#ifndef global_h_included
#define global_h_included

struct S {
  int *p;
};

extern int  aob_assign(int*, int);
extern void dbf_free_1(void*);
extern void dbf_free_2(void*);
extern void msf_free(struct S*);
extern int  npd_assign(int*);
extern void uaf_free(void*);
extern int  uiv_assign(int*);

extern void test_aob();
extern void test_dbf();
extern void test_msf();
extern void test_npd();
extern void test_uaf();
extern void test_uiv();

#endif /* global_h_included */
