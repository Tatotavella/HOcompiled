#include <stdio.h>

#define NUM 301

extern sum_abs_(int *data, int *num, int *sum);

int main(int argc, char **argv)
{
    int data[NUM+1], num, i;

    num = NUM;
    for (i=0; i < num; i++) {
        //*(data+i) = i - 100 + 1;  /* NOTE: difference in array numbering */
	data[i] = i - 100 + 1;  
    }
    int *sum;
    sum_abs_(data, &num,sum);
    printf("sum=%d\n",*(sum));
    return 0;
}
