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

  int i;

  for(i=zero; i < ITERS; i+=1) {
    t1*=t2;
    t2*=t3;
    t3*=t4;
    t4*=t5;
    t5*=t1;
  }
  return t1+t2+t3+t4+t5;
}

int main(int argc, char* argv[]) {
   argc&=10000;
   ROI_BEGIN(); 
   int t=loop(argc); 
   ROI_END();
   volatile int a = t;
}
