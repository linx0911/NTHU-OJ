#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int compare(const void *a,const void *b){
    return strcmp((char*)a, (char*)b);
}
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;
        char input[n][52];
        for(int i = 0; i < n; i++) scanf("%s",input[i]);
        qsort(input, n, sizeof(input[0]), compare);
        for(int i = 0; i < n; i++) printf("%s\n",input[i]);
        printf("\n");
    }
	return 0;
}
