#include <stdlib.h>
#include "c-sum.h"

int sum_abs_(int *in, int *num, int *sum) {
   int i;
   int s=0;
   for (i=0; i < *(num); ++i) {
       s += abs(in[i]);
   }
   *(sum)=s;
   return 0;
}
 
