#include <stdio.h>
#include "common.h"

#define ASIZE 2048
#define STEP   128
#define ITERS 4096


__attribute__((optimize("no-unroll-loops")))
float loop(int zero) {
  float  t1 = 1.1f;
  float  t2 = 89.0f;
  float  t3 = 3.2f;
  float  t4 = 21.0f;
  float  t5 = 2.0f;
  float  t6 = 7.0f;
  float  t7 = 2.5f;
  float  t8 = 3.0f;

  int i;
  for(i=0; i < ITERS; i+=1) {
    t1*=0.2f;
    t2*=0.4f;
    t3*=1.2f;
    t4*= 0.12f;
    t5*= 0.13f;
    t6*= 0.14f;
    t7*= 0.15f;
    t8*= 0.16f;
  }
  return t1+t2+t3+t4+t5+t6+t7+t8;
}

int main(int argc, char* argv[]) {
   argc&=10000;
   ROI_BEGIN(); 
   int t=loop(argc); 
   ROI_END();
   volatile float a = t;
}
