// template specialization
extern "C" int printf(const char*, ...);
// class template:
template <class T>
class mycontainer {
    T element;
  public:
    mycontainer (T arg) {element=arg;}
    T increase () {return ++element;}
};

// class template specialization:
template <>
class mycontainer <char> {
    char element;
  public:
    mycontainer (char arg) {element=arg;}
    char uppercase ()
    {
      if ((element>='a')&&(element<='z'))
      element+='A'-'a';
      return element;
    }
};

int test_templ_spec1 () {
  mycontainer<int> myint (7);
  mycontainer<char> mychar ('j');
  printf("%d\n", myint.increase());
  printf("%c\n", mychar.uppercase());
  return 0;
}

int main() {
  return test_templ_spec1();
}

