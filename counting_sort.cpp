#include <cstdio>
#include <cstring>
int main(){
    int num[10001], tag[10001], n, t = 0, tmp;
    memset(num, 0 , sizeof(num));
    memset(tag, 0 , sizeof(tag));
    while(scanf("%d", &n) != EOF){
        t++;
        int max = -1;
        for(int i = 0; i < n; i++){
            scanf("%d",&tmp);
            if(tmp > max) max = tmp;
            if(tag[tmp] != t) num[tmp] = 0;
            tag[tmp] = t;
            num[tmp]++;
        }
        for(int i = 0; i <= max; i++){
            if(tag[i] == t){
                printf("%d %d",num[i], i);
                if(i != max) printf(" ");
                else printf("\n");
            }
        }
    }
    return 0;
}
