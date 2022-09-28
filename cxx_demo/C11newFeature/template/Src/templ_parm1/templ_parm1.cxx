extern "C" int printf(const char*, ...);
namespace test {
  template<typename _Value>
    struct S1
    {
      static const _Value __max;
      static const _Value __min;
    };

  template<typename _Value>
    const _Value S1 <_Value>::__max = 10;
  template<typename _Value>
    const _Value S1 <_Value>::__min = 0;

} //namespace test
using namespace test;
int test_templ_parm1() {
  // instantiation
  S1<int> myInt;
  int a = S1<int>::__max;
  int b = S1<int>::__min;
  printf("%d\n", a/b);
  return 0;
}

int main() {
  return test_templ_parm1();
}

