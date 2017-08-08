#include<cstdio>
#include<cmath>
#include<cstring>

int main(){
    char A[1005], B[1005], C[1005];
    while(scanf("%s %s", A, B)!=EOF)
    {
        int A_index,B_index, C_index = 1004,ans = 0, carry = 0;
        A_index = strlen(A) - 1;    //O(n)
        B_index = strlen(B) - 1;    //O(n)
        C[C_index--] = '\0';
        while( (A_index >= 0 || B_index >= 0) || carry > 0){
            int a = (A_index >= 0) ? (A[A_index] - '0') : 0;
            int b = (B_index >= 0) ? (B[B_index] - '0') : 0;
            int c = a + b + carry;
            carry = c / 10;
            char tmp = c % 10 + '0';
            C[C_index] = tmp;
            A_index--;
            B_index--;
            C_index--;
            if(carry > 0) ans++;
        }
        for(int i = C_index+1; i < 1004; i++) printf("%c", C[i]);
        printf(" %d\n",ans);
        memset(C, 0, sizeof(C));
    }
    return 0;
}
