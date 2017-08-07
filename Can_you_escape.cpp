#include<cstdio>
#include<string.h>
#include<queue>

using namespace std;
typedef struct _stack{
    int x, y, len;
}BFS_state;

int R, C, v[1001][1001], tag;
char map[1001][1001];
BFS_state not_out;
int step[4][2] = {0,-1,
                  0,1,
                  -1,0,
                  1,0};
BFS_state new_state(int x, int y, int len){
    BFS_state t;
    t.x = x;
    t.y = y;
    t.len = len;
    return t;
}

bool state_q(BFS_state a, BFS_state b){
    return (a.x == b.x && a.y == b.y);
}

bool in_bound(int x, int y, int V){
    return (x >=0 && x < C && y >= 0 && y < R && v[y][x] != V && map[y][x] != 'w');
}

BFS_state BFS(BFS_state s, BFS_state e,int V){
    queue<BFS_state> que;
    que.push(s);
    while(!que.empty()){
        BFS_state tmp = que.front();
        que.pop();
        if(v[tmp.y][tmp.x] == V) continue;
        v[tmp.y][tmp.x] = V;

        if(state_q(e, tmp)){
            return tmp;
        }

        for(int i = 0; i < 4; i++){
            if(in_bound(tmp.x+step[i][1], tmp.y+step[i][0], V))
                que.push(new_state(tmp.x+step[i][1], tmp.y+step[i][0], tmp.len+1));
        }
    }
    return not_out;
}

int main(){
    char e;
    not_out = new_state(0,0,-1);
    tag = 1;
    memset(v, 0, sizeof(v));
    while(scanf("%d%d%c",&R, &C, &e) != EOF){
        BFS_state start, button, exit;
        for(int i = 0; i < R; i++){
            gets(map[i]);
            for(int j = 0; j < C; j++){
                if(map[i][j] == 's') start = new_state(j, i, 0);
                else if(map[i][j] == 'b') button = new_state(j, i, 0);
                else if(map[i][j] == 'e') exit = new_state(j, i, 0);
            }
        }
        BFS_state ans1 = BFS(start, button, tag++);
        if(ans1.len < 0) printf("No solution.\n");
        else{
            BFS_state ans2 = BFS(ans1, exit, tag++);
            if(ans2.len < 0) printf("No solution.\n");
            else{
                printf("Escape in %d steps.\n",ans2.len);
            }
        }
    }
    return 0;
}
