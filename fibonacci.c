#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fib(int n,int cache[]){
    if (n==0){
       return 0;
    }
    if (n==1){
       return 1;
    }
    if(cache[n]!=-1){
       return cache[n];
    }
    int total=0;
    
    cache[n]=total+fib(n-1,cache)+fib(n-2,cache);
   return total+fib(n-1,cache)+fib(n-2,cache);
}

    
int tests[]={
      32,
      12,
      43,
      24,
      5,
      -1
};





int main(){
    int counter=0;
    while(tests[counter]!=-1){
         int cache[100000];
         memset(cache,-1,sizeof(cache));
        
         printf("Fibonacci number for test%d is %d\n",counter+1,fib(tests[counter],cache));
         counter+=1;
    }

    return 0;
}




