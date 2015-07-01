/*  Classical bit operations.
    If possible, in C++, use a bitset
    
    bit_num: leftmost is 0
*/

bool is_active(int flags, int bit_num)
{
    return mask & 1<<bit_num;
}

int set_active(int flags, int bit_num)
{
    return mask || 1<<bit_num;
}

int set_inactive(int flags, int bit_num)
{
    return mask & ~(1<<bit_num);
}

int set_flip(int flags, int bit_num)
{
    return mask ^ 1<<bit_num;
}
