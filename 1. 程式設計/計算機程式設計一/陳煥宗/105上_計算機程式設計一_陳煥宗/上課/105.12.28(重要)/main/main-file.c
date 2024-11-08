int val = 10000;
int get_var(void)
{
    static int var = 111;
    return ++var;
}
