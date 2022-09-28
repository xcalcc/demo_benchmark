extern "C" int printf(const char*, ...);
struct A { double x; };
const A* a;
 
decltype(a->x) y;       // type of y is double (declared type)
decltype((a->x)) z = y; // type of z is const double& (lvalue expression)
 
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) // return type depends on template parameters
                                      // return type can be deduced since C++14
{
    return t+u;
}
 
int test_decl_type1() 
{
    int i = 33;
    decltype(i) j = i * 2;
    auto k = add(i, j);
     
    printf("i=%d, j=%d, k=%d\n", i, j,k);  // i=33, j=66, k=99
    y=3;
    printf("y=%f, z=%f\n", y, z);
}

int main() {
    return test_decl_type1();
}

