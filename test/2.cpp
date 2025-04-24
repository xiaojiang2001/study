#include <stdio.h>

#define A(x) x;x;x;x;x;x;x;x;x;x;


void before() __attribute__((constructor));
void after() __attribute__((destructor));


void before(){
    printf("this is function %s\n", __func__);
    return;
}


void after(){
    printf("this is function %s\n", __func__);
    return;
}


int main()
{
    printf("this is function %s\n", __func__);
    return 0;
}
static int a;

void set_bits3(void)
{
    a |= (0x01 << 3);
}

void clear_bits(void)
{
    a &= ~(0x01 << 3);
}