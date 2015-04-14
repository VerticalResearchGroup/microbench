#include <stdio.h>
#include "common.h"

#define ASIZE 2048
#define STEP   128
#define ITERS 4096

__attribute__ ((noinline))
int loop(int zero) {
  int t1 = 1 +zero;
  int t2 = 89+zero;
  int t3 = 3 +zero;
  int t4 = 21+zero;
  int t5 = 2 +zero;
  int t6 = 7 +zero;
  int t7 = 2+zero;
  int t8 = 3+zero;
  int t9 = 1+zero;
  int t10 = 8+zero;
  int t11 = 3+zero;
  int t12 = 21+zero;
  int t13 = 2+zero;
  int t14 = 7+zero;
  int t15 = 2+zero;
  int t16 = 3+zero;

  int i;

  for(i=zero; i < ITERS; i+=1) {
    t1*=t1;
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
