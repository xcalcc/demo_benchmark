// EXP61-CPP. A lambda object must not outlive any of its reference captured objects 
#include <iostream>

auto g() {
  int i = 12;
  return [&] {
    i = 100;
    return i;
  };
}

void f() {
  int j = g()();
  std::cout<<"f():"<<j<<std::endl;
}

/*Compliant Solution:
  auto g() {
  int i = 12;
  return [=] () mutable {
    i = 100;
    return i;
  };
}
 
void f() {
  int j = g()();
}
*/

auto g1(int val) {
  auto outer = [val] {
    int i = val;
    auto inner = [&] {
      i += 30;
      return i;
    };
    return inner;
  };
  return outer();
}

void f1() {
  auto fn = g1(12);
  int j = fn();
  std::cout<<"f1():"<<j<<std::endl;
}

int main() {
  f();
  f1();
  return 0;
}

/* Compliant Solution: 
 auto g(int val) {
  auto outer = [val] {
    int i = val;
    auto inner = [i] {
      return i + 30;
    };
    return inner;
  };
  return outer();
}
 
void f() {
  auto fn = g(12);
  int j = fn();
}
*/
