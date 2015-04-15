#include <stdio.h>
#include "common.h"
#define ASIZE 2048
#define STEP   128
#define ITERS   32

int arr[ASIZE];

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    for(i=zero; i < 2048; i+=8) {
      t += arr[i+0];
      t += arr[i+1];
      t += arr[i+2];
      t += arr[i+3];
      t += arr[i+4];
      t += arr[i+5];
      t += arr[i+6];
      t += arr[i+7];
      t += i; //cause the paper said so!
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
