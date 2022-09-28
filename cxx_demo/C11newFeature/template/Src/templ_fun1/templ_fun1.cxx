// function template
extern "C" int printf(const char*, ...);
template <class T>
T GetMax (T a, T b) {
  T result;
  if(a>b)
   result = a;
  else
   result = b;
  return result;
}

template <class T>
T GetMin (T a, T b) {
  T result;
  if(a>b)
   result = b;
  else
   result = a;
  return result;
}

int templ_fun1 () {
  int i=5, j=0, k, n;
  k=GetMax<int>(i,j);
  n=GetMin<int>(j,j);
  printf("%d\n", k/n);
  return 0;
}

int main() {
  return templ_fun1();
}
