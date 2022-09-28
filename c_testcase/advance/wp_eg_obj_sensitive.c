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
  if (p->data[1] == 1)
    p->data[0] = *q;   // null pointer deref

  return p->data[0];
}
