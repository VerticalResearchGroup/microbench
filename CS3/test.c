#include <stdio.h>
#include "common.h"

#define ASIZE 2048
#define STEP    30
#define ITERS  128

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS+zero; ++iter) {
    for(int i = zero; i < ITERS; ++i ) {
      switch(i) {
        case  0:case  1:case  2: t+=1; t|=2; break;
        case  3:case  4:case  5: t+=4; t|=4; break;
        case  6:case  7:case  8: t-=4; t|=3; break;
        case  9:case 10:case 11: t+=2; t|=4; break;
        case 12:case 13:case 14: t-=3; t|=5; break;
        case 15:case 16:case 17: t+=2; t|=3; break;
        case 18:case 19:case 20: t-=3; t|=2; break;
        case 21:case 22:case 23: t-=1; t|=2; break;
        case 24:case 25:case 26: t-=2; t|=3; break;
        case 27:case 28:case 29: t-=1; t|=1; break;
      }
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
