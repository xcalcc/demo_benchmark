// function template II
extern "C" int printf(const char*, ...);

template <class T>
T GetMax (T a, T b) {
  if(a>b)
    return a;
  else
    return b;
}

int templ_fun2 () {
  int i=5, j=6, k;
  long l=10, m=5, n;
  long o;
  k=GetMax(i,j);
  n=GetMax(l,m);
  o=GetMax(m,l);
  printf("%d\n", k);
  printf("%ld\n", n);
  printf("%ld\n", o);
  return 0;
}

int main() {
  return templ_fun2();
}
