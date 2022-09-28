#include <stdexcept>
extern "C" int printf(const char*, ...);
 
// C++11 constexpr functions use recursion rather than iteration
// (C++14 constexpr functions may use local variables and loops)
constexpr int factorial(int n)
{
    return n <= 1 ? 1 : (n * factorial(n - 1));
}
 
// literal class
class conststr {
    const char* p;
    std::size_t sz;
public:
    template<std::size_t N>
    constexpr conststr(const char(&a)[N]) noexcept : p(a), sz(N - 1) {}
 
    // constexpr functions signal errors by throwing exceptions
    // in C++11, they must do so from the conditional operator ?:
    constexpr char operator[](std::size_t n) const
    {
        return n < sz ? p[n] : throw std::out_of_range("");
    }
    constexpr std::size_t size() const { return sz; }
};
 
// C++11 constexpr functions had to put everything in a single return statement
// (C++14 doesn't have that requirement)
static constexpr std::size_t countlower(conststr s, std::size_t n = 0,
                                             std::size_t c = 0)
{
    return n == s.size() ? c :
           'a' <= s[n] && s[n] <= 'z' ? countlower(s, n + 1, c + 1) :
                                       countlower(s, n + 1, c);
}
 
// output function that requires a compile-time constant, for testing
template<int n>
struct constN
{
    constN() { printf("\n"); }
};

//C++ overloaded function
void fun(int i){ printf("Call fun(int i): %d\n", i); };
void fun(int *p){ printf("Call fun(int *p): %d\n", *p); };
 
int test_nullptr_constexpr()
{
    printf("4! = ");
    constN<factorial(4)> out1; // computed at compile time
 
    int k = 8; // disallow optimization using volatile
    printf("%d! = %d\n", k, factorial(k));
 
    printf("the number of lowercase letters in \"Hello, world!\" is ");
    constN<countlower("Hello, world!")> out2; // implicitly converted to conststr
    
    int *p0 = NULL;
    const int *p1 = nullptr;  //p1是指向整形常量的指针
    constexpr int *p2 = nullptr; //p2是指向整形的常量指针

    fun(10);
    fun(&k);   // no NPD
    
    printf("%d\n", *p0); // NPD, one function
    fun(*p0);            // NPD, cross function
    fun(*p1);            // NPD
    fun(*p2);            // NPD

    if (p2 != nullptr)
        fun(*p2);    //no NPD; control sensitive

    p1 = &k;
    fun(*p1);            //no NPD; data sensitive
}

int main() {
    return test_nullptr_constexpr();
}
