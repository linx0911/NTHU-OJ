#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char name[1000000][12];
int main(){
    int front = 0,tail = 0;
    char str[6];
    while(scanf("%s",str) != EOF){
        if(!strcmp(str,"Push")){
            scanf("%s",name[(tail%1000000)]);
            tail++;
        }else if(!strcmp(str,"Pop")){
            if(tail > front) front++;
        }
        else if(!strcmp(str,"Front")){
            if(tail > front) printf("%s\n",name[(front%1000000)]);
            else printf("empty\n");
        }
    }
    return 0;
}
