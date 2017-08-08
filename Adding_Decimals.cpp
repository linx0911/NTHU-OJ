#include<cstdio>
#include<cstring>

int main(){
    char A[1005], B[1005], C[1005];
    while(scanf("%s %s", A, B)!=EOF){
        int A_index = strlen(A) - 1,B_index = strlen(B) - 1, C_index = 1004;
        int ans = 0, carry = 0, a, b, c;

        C[C_index--] = '\0';
        while( (A_index >= 0 || B_index >= 0) || carry > 0){
            a = (A_index >= 0) ? (A[A_index] - '0') : 0;
            b = (B_index >= 0) ? (B[B_index] - '0') : 0;
            c = a + b + carry;
            carry = c / 10;
            C[C_index] = c % 10 + '0';
            A_index--;  B_index--;  C_index--;
            if(carry > 0) ans++;
        }
        for(int i = C_index+1; i < 1004; i++) printf("%c", C[i]);
        printf(" %d\n",ans);
        memset(C, 0, sizeof(C));
    }
    return 0;
}
