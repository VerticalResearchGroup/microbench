#include <stdio.h>
#include <stdlib.h>     /* malloc, free, rand */

#include "common.h"

#define ASIZE 2048
#define STEP   128
#define ITERS    4
#define LEN   2048

int arr[ASIZE];

struct ll {
  int val;
  struct ll* _next;
};

__attribute__ ((noinline))
int loop(int zero,struct ll* n) {
  int t = 0,i,iter;
  for(iter=0; iter < ITERS; ++iter) {
    struct ll* cur =n;
    while(cur!=NULL) {
      t+=cur->val;
      cur=cur->_next;
    }
  }
  return t;
}

int main(int argc, char* argv[]) {
   argc&=10000;
   struct ll *n, *cur;

   int i;
   n=malloc(sizeof(struct ll));
   cur=n;
   for(i=0;i<LEN;++i) {
     cur->val=i;
     cur->_next=malloc(sizeof(struct ll));
     cur=cur->_next;
   }
   cur->val=100;
   cur->_next=NULL;

   ROI_BEGIN(); 
   int t=loop(argc,n);
   ROI_END();
   volatile int a = t;
}
