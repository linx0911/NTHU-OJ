#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int supply[N], current = 1, index = 0;
        stack<int> arr;
        for(int i = 0; i < N; i++)
            scanf("%d",&supply[i]);
        while(current <= N){//success
            if(!arr.empty() && arr.top() == current){//pop
                current++;
                arr.pop();
            }
            else if(supply[index] == current){//out
                current++;
                index++;
            }
            else if(index < N){//push
                arr.push(supply[index++]);
            }
            if(index >= N && !arr.empty() && current != arr.top()) break;//fail
        }
        if(arr.empty()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
