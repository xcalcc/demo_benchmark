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
 
int test_decl_type() 
{
    int i = 33, k;
    decltype(i) j = i * 2;
    printf("i=%d, j=%d\n", i, j);  // i=33, j=66
    auto f = [](int a, int b) -> int
    {
        return a * b;
    };
 
    decltype(f) g = f; // the type of a lambda function is unique and unnamed
    i = f(2, 2);
    j = g(3, 3);
    k = k / f(0, 0);   // UIV on k, DBZ for f
 
    printf("i=%d, j=%d, k=%d\n", i, j, k); //i=4, j=9
}

int main() {
    return test_decl_type();
}

