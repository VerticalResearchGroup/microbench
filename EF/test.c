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
  float  t9 = 2.1f;
  float  t10 = 7.4f;
  float  t11 = 2.5f;
  float  t12 = 3.2f;
  float  t13 = 2.1f;
  float  t14 = 7.6f;
  float  t15 = 2.5f;
  float  t16 = 3.2f;

  int i;

  for(i=zero; i < ITERS; i+=1) {
    t1*=0.2f;
    t2*=0.4f;
    t3*=1.2f;
    t4*= 0.12f;
    t5*= 0.13f;
    t6*= 0.14f;
    t7*= 0.15f;
    t8*= 0.16f;
    t9*= 0.17f;
    t10*= 0.18f;
    t11*= 0.22f;
    t12*= 0.32f;
    t13*= 0.42f;
    t14*= 0.52f;
    t15*= 0.62f;
    t16*= 0.72f;
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
