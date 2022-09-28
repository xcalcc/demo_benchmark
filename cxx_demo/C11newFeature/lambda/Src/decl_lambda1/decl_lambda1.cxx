extern "C" int printf(const char*, ...);
// declaring_lambda_expressions1.cpp
// compile with: /EHsc /W4

int test_decl_lambda1()
{

    using namespace std;

    // Assign the lambda expression that adds two numbers to an auto variable.
    auto f1 = [](int x, int y) { return x + y; };

    printf("%d\n",f1(2, 3) );


    printf("%d\n",f1(3, 4) );
    return 0;
}

int main() {
    return test_decl_lambda1();
}

/* output
5
7
*/
