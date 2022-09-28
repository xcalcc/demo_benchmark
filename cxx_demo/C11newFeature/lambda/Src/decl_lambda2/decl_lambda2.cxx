extern "C" int printf(const char*, ...);
// declaring_lambda_expressions2.cpp
int test_decl_lambda2()
{
   int i = 3;
   int *j = nullptr;

   // The following lambda expression captures i by value and
   // j by reference.
   auto f1 = [i, j] { return i + *j; };

   // Change the values of i and j.
   i = 22;

   // Call f and print its result.
   printf("f1=%d\n",f1());  // NPD
   return 0;  
}

int main() {
   return test_decl_lambda2();
}

/* output
47
*/
