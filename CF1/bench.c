#include <stdio.h>
#include "randArr.h"
#include "common.h"

#define ASIZE 2048
#define STEP   128
#define ITERS   48

__attribute__ ((noinline))
int loopy_helper(int i,int zero){
  return (i*2+zero)*3+(i+zero)*(i+zero);
}

__attribute__ ((noinline))
int func_loopy(int i,int zero){
  int l,k=i;
  if(i<16) {
    return loopy_helper(i+4,zero);
  }
  for(l=i-16; l < i+zero; ++l) {
    k+=(k+l+randArr[l])&0x10101;
    randArr[l]=loopy_helper(k,zero);
  }
  return k;
}

__attribute__ ((noinline))
int func_no_loopy(int i ){
  return (i+10+randArr[i])%16;
}

__attribute__ ((noinline))
int loop(int zero) {
  int t = 0,i,iter;
  ROI_BEGIN();
  for(iter=zero; iter < ITERS; ++iter) {
    //ROI_BEGIN();
    t+=func_loopy(iter,zero);
    //ROI_END();
  }
  ROI_END();


  //ROI_BEGIN();
  for(iter=zero; iter < ITERS; ++iter) {
    //ROI_BEGIN();
    t+=func_no_loopy(iter);
    //ROI_END();
  }
  //ROI_END();

  return t;
}

int main(int argc, char* argv[]) {
   argc&=10000;
   //ROI_BEGIN();
   int t=loop(argc); 
   //ROI_END();
   volatile int a = t;
}
