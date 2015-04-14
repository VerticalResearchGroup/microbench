#include <stdio.h>
#include "common.h"

#define ASIZE 2048
#define STEP   128
#define ITERS 4096

__attribute__ ((noinline))
int loop(int zero) {
  int t1 = 1;
  int t2 = 89;
  int t3 = 3;
  int t4 = 21;
  int t5 = 2;
  int t6 = 7;
  int t7 = 2;
  int t8 = 3;
  int t9 = 1;
  int t10 = 89;
  int t11 = 3;
  int t12 = 21;
  int t13 = 2;
  int t14 = 7;
  int t15 = 2;
  int t16 = 3;

  int i;

  for(i=zero; i < ITERS; i+=1) {
    t1+=i;
    t2+=i;
    t3+=i;
    t4+=i;
    t5+=i;
    t6+=i;
    t7+=i;
    t8+=i;
    t9+=i;
    t10+=i;
    t11+=i;
    t12+=i;
    t13+=i;
    t14+=i;
    t15+=i;
    t16+=i;
  }
  return t1+t2+t3+t4+t5+t6+t7+t8*t9+t10+t11+t12+t13+t14+t15+t16;
}

int main(int argc, char* argv[]) {
   argc&=10000;
   ROI_BEGIN(); 
   int t=loop(argc); 
   ROI_END();
   volatile int a = t;
}
