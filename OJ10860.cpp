#include <stdio.h>
#include <string.h>
int main(){
    char name[100000][20],temp[10];
    int head = 0,tail = 0;
    while(scanf("%s",temp) != EOF){
        if(!strcmp(temp,"Push")){
            scanf("%s",name[(tail++)%100000]);
        }else if(!strcmp(temp,"Pop")){
            head = (head+1)%100000;
        }else{
            if(head != tail) printf("%s\n",name[head]);
            else printf("empty\n");
        }
    }
    return 0;
}
