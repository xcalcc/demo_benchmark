//False positive 1
struct s {
  int data[2];
};

int  memmodel_clang1(struct s buf)
{
  int i = 3;
  int *q;
  struct s* p;

  if (buf.data[1] == 1) {
    q = &i;
  }
  p = &buf;
  // if (buf.data[1] == 1) // if use this form, Clang is fine
  if (p->data[1] == 1)
    p->data[0] = *q;   // not null pointer deref (false positive for Clang)

  return p->data[0];
}

//False positive 2

int  memmodel_clang2(struct s buf)
{
  int i = 3;
  int *q;
  struct s* p;

  if (buf.data[1] == 1) {
    q = &i;
  }
  p = &buf;
  // if (buf.data[1] == 1) // if use this form, Clang is fine
  if (buf.data[1] == 1)
    p->data[0] = *q;   // not null pointer deref (false positive for Clang)

  return p->data[0];
}

