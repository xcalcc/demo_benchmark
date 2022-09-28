// class templates
extern "C" int printf(const char*, ...);

template <class T>
class mypair {
    T a, b;
  public:
    mypair (T first, T second)
      {a=first; b=second;}
    T getmax ();
    T getmin ();
};

template <class T>
T mypair<T>::getmax ()
{
  T retval;
  if(a>b)
    retval=a;
  else
    retval=b;
  return retval;
}

template <class T>
T mypair<T>::getmin ()
{
  T retval;
  if(a>b)
    retval=b;
  else
    retval=a;
  return retval;
}

int test_templ_class1 () {
  mypair <int> myobject (100, 0);
  printf("%d\n", myobject.getmax() / myobject.getmin() ); // DBZ
  return 0;
}

int main() {
  return test_templ_class1();
}

