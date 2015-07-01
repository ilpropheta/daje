
// classical xor-swap idiom
void xor_swap(int *x, int *y) 
{
     *x=*x^*y^(*y=*x);
}
