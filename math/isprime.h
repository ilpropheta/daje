/*
  simple function to check if an int number is prime
*/
bool is_prime(int num) 
{
    if (num <= 3) 
    {
        return num > 1;
    }
    if (num % 2 == 0 || num % 3 == 0) 
    {
        return false;
    } 
    else 
    {
        for (int i = 5; i * i <= num; i += 6) 
        {
            if (num % i == 0 || num % (i + 2) == 0) 
            {
                return false;
            }
        }
        return true;
    }
}
