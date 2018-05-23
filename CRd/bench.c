#include <stdio.h>
#include "common.h"

#define ASIZE 2048
#define STEP   128
#define ITERS   20

__attribute__ ((noinline))
int rec(int i){
  if(i==0) return 0;
  if(i==1) return 1;
  if(i<1024) {
    return rec(i-1)+rec(i/2);
  } else {
    return 5;
  }
}

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    t+=rec(iter*8);
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
