extern "C" int printf(const char*, ...);
// test parameter reference
// declaring_lambda_expressions2.cpp
int test_decl_lambda3()
{
   int i = 3;
   int *j = nullptr;

   // The following lambda expression captures i by value and
   // j by reference.
   auto f1 = [i, j] { return i + *j; };
   auto f2 = [i, &j] { return i + *j; };

   // Change the values of i and j.
   i = 22;

   // Call f and print its result.
   printf("%d\n",f1() );  // NPD
   printf("%d\n",f2() );  // NPD

   j = &i;

   // Call f and print its result.
   printf("%d\n",f1() );  // NPD
   printf("%d\n",f2() );
  
   return 0;
}

int main() {
   return test_decl_lambda3();
}

/* output
47
52
33
22
*/
