#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int grade;
    char name[20];
    int coming;
}student;
student st[1000002];
int compare(const void *a,const void *b){
    student c = *(student*)a;
    student d = *(student*)b;
    if(c.grade > d.grade) return 1;
    else if(c.grade < d.grade) return -1;
    else{
        if(c.coming > d.coming) return 1;
        else if(c.coming < d.coming) return -1;
    }
}
int main(){
    int i,n;
    while(scanf("%d",&n)!= EOF){
        for(i = 0; i < n; i++){
            scanf("%s %d",st[i].name,&st[i].grade);
            st[i].coming = i;
        }
        qsort(st,n,sizeof(student),compare);//array , length, sizeof(element), compare function
        for(i = 0; i < n; i++) printf("%s %d\n",st[i].name,st[i].grade);
    }
    return 0;
}
