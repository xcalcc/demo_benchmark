extern "C" int printf(const char*, ...);
// nesting_lambda_expressions.cpp

int test_nest_lambda1()
{
    using namespace std;

    // The following lambda expression contains a nested lambda
    // expression.
    int timestwoplusthree = [](int x) { return [](int y) { return y * 2; }(x) + 3; }(5);

    // Print the result.
    printf("%d\n",timestwoplusthree );
    return 0;
}

int main() {
    return test_nest_lambda1();
}
