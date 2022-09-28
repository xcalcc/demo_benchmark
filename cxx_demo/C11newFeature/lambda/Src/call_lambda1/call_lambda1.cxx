extern "C" int printf(const char*, ...);
// calling_lambda_expressions1.cpp

int test_call_lambda1()
{
   int n = [] (int x, int y) { return x + y; }(5, 4);
   printf("%d\n",n );
   int z = [] (int x, int y) { return x * y; }(4, 0);
   printf("%d\n", n/z);  // DBZ here
   return 0;
}

int main() {
   return test_call_lambda1();
}

