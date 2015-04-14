#include <stdio.h>
#include "common.h"
#define ASIZE 65536
#define STEP   128
#define ITERS   32

int arr[ASIZE];

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=zero; iter < ITERS; ++iter) {
    for(i=iter; i < ASIZE; i+=1024) {
      t += arr[i+0];
      t += arr[i+1*128];
      t += arr[i+2*128];
      t += arr[i+3*128];
      t += arr[i+4*128];
      t += arr[i+5*128];
      t += arr[i+6*128];
      t += arr[i+7*128];
    }
  }
  return t;
}

int main(int argc, char* argv[]) {
   argc&=10000;
   ROI_BEGIN(); 
   int t=loop(argc); 
   ROI_END();
   volatile int a = t;
}
