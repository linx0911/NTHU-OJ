/*Linx*/
/*Qsort : Increasing*/
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
int comp(const void *a,const void *b){
    return *(int*)a - *(int*)b;
}
int main(){
    int a[10] = {-100,5,0,9,7,6,8,4,1,30};
    qsort(a,sizeof(a)/sizeof(a[0]),sizeof(a[0]),comp);
    for(int i = 0; i < 10; i++) printf("%d ",a[i]);
    return 0;
}
