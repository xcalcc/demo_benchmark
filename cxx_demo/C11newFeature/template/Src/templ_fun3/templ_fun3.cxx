// function template II
extern "C" int printf(const char*, ...);

template <class T, class U>
T GetArg1 (T a, U b) {
    return a;
}
template <class T, class U>
U GetArg2 (T a, U b) {
    return b;
}
int test_templ_fun3 () {
  int i=5, j=6, k;
  long l=10, m=5, n;
  k=GetArg1(i,j);
  printf("%d\n", k);
  k=GetArg2(i,j);
  printf("%d\n", k);
  n=GetArg1(l,m);
  printf("%ld\n", n);
  n=GetArg2(l,m);
  printf("%ld\n", n);
  k=GetArg1(i,l);
  printf("%d\n", k);
  n=GetArg2(i,l);
  printf("%ld\n", n);
  return 0;
}

int main() {
  return test_templ_fun3();
}

// output:
/*
5
6
10
5
5
10
*/
