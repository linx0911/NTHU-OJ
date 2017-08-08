#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
struct str{
    char name[51];
};
int compare(const void *a,const void *b){
    return strcmp(((str*)a)->name, ((str*)b)->name);
}
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;
        str people[n];
        for(int i = 0; i < n; i++) scanf("%s",people[i].name);
        qsort(people, n, sizeof(str), compare);
        for(int i = 0; i < n; i++) printf("%s\n",people[i].name);
        printf("\n");
    }
	return 0;
}
