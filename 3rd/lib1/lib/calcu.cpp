int add_i(int x, int y)
{
  return x+y;
}

int sub_i(int x, int y)
{
  return x-y;
}

int mul_i(int x, int y)
{
  return x*y;
}

int div_i(int x, int y)
{
  if(y)
  return x/y;
  else
  return -1;
}