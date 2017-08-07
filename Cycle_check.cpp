#include <cstdio>
#include <string.h>
int adj[1001][1001], set_s[1001], tag, record[10000], r, n, m;
//adj: record links, set_s: record if start at this point
//record: record points passed this time, r: record the length of record
int DFS(int s){
    for(int i = 0; i < r; i++)
        if(record[i] == s) return 1;
    if(set_s[s] == tag) return 0;
    record[r++] = s;
    set_s[s] = tag;
    for(int i = 1; i <= n; i++){
        if(adj[s][i] == tag && s != i){
            int ans = DFS(i);
            if(ans == 1) return 1;
        }
    }
    r -= 1;
    return 0;
}
int main(){
    memset(adj, -1, sizeof(adj));
    memset(record, 0, sizeof(record));
    memset(set_s, 0, sizeof(set_s));
    tag = 0;
    while(scanf("%d%d", &n, &m) != EOF){
        r = 0;
        tag++;
        int check = 1;
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d%d", &u, &v);
            adj[u][v] = tag;
        }
        for(int i = 1; i <= n && check == 1; i++){
            if(set_s[i] != tag){
                int ans = DFS(i);
                if(ans == 1) check = 0;
            }
        }
        if(check == 0) printf("YES\n");
        else printf("NO\n");

    }
}
