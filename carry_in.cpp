#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
char A[1005], B[1005];
    while(scanf("%s %s", A, B)!=EOF)
    {
        int A_index,B_index, ans = 0, carry = 0;
        A_index = strlen(A) - 1;    //O(n)
        B_index = strlen(B) - 1;    //O(n)
        while( (A_index >= 0 && B_index >= 0) || carry > 0){
            int a = (A_index >= 0) ? (A[A_index] - '0') : 0;
            int b = (B_index >= 0) ? (B[B_index] - '0') : 0;
            int c = a + b + carry;
            A_index--;
            B_index--;
            carry = c / 10;
            if(carry > 0) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
