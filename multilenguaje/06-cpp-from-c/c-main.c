#include <stdio.h>

#define NUM 200

extern _Z7sum_absPKii(int *data, int num);

int main(int argc, char **argv)
{
    int data[NUM], num, i;
    
    num = NUM;
    for (i=0; i < num; i++) {
        data[i] = i - 100 + 1; /* NOTE: difference in array numbering */  
    }
    int sum;
    sum = _Z7sum_absPKii(data, num);
    printf("sum=%d\n",sum);
    return 0;
}
