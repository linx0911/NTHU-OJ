#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
int main(){
    int n, tag = 1;
    char e;
    scanf("%d%c",&n,&e);
    while(n--){
        char input[10002];
        stack<char> arr;
        gets(input);
        int input_len = strlen(input), flag = 1;
        for(int i = 0; i < input_len && flag == 1; i++){
            if(input[i] == '{') arr.push(input[i]);
            else if(input[i] == '[') arr.push(input[i]);
            else if(input[i] == '(') arr.push(input[i]);
            else if(input[i] == '<') arr.push(input[i]);
            else if(input[i] == '}'){
                if(!arr.empty() && arr.top() == '{') arr.pop();
                else flag = 0;
            }
            else if(input[i] == ']'){
                if(!arr.empty() && arr.top() == '[') arr.pop();
                else flag = 0;
            }
            else if(input[i] == ')'){
                if(!arr.empty() && arr.top() == '(') arr.pop();
                else flag = 0;
            }
            else if(input[i] == '>'){
                if(!arr.empty() && arr.top() == '<') arr.pop();
                else flag = 0;
            }
        }
        if(arr.empty() && flag == 1) printf("Case %d: Yes\n", tag++);
        else printf("Case %d: No\n", tag++);
    }
    return 0;
}
