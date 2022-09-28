int npd_simple(int random_val, int *p, int offset)
{
    int *q = 0;

    p = q;
    return *p;
}


int global;

int npd_complex(int random_val, int *p, int offset)
{
    int *q = 0;
    int i;

    for (i=0; i<100; i++) {
        if (random_val != 10) {
          random_val++;
	  q = &global;
        }
    }
    p = q;
    return *p;
}


int *another_func1(int offset, int r)
{
  int *q = 0;
  int i;

  for (i=0; i<100; i++) {
    if (r != 10) {
      r++;
      q = &global;
    }
  }
  return q;
}


int npd_cross_func(int random_val, int *p, int offset)
{
  p = another_func1(offset, random_val);;
    return *p;
}


