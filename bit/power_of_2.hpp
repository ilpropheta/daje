/*
  simple operations involving powers of two
*/

int pow_of_2(int power)
{
  return 1<<power;
}

int mult_by_pow_2(int number, int power)
{
  return number<<power;
}

int div_by_pow_2(int number, int power)
{
  return number>>power;
}

bool is_pow_2(int x)
{
  return !((x-1) & x);
}
