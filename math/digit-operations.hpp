
int sum_of_digits(int n)
{
    auto sum = 0;
    while (n)
    {
        sum += n%10;
        n/=10;
    }    
    return sum;
}