#include <stdio.h>
long long int gcd(long long int a,long long int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}
long long int lcm(long long int a,long long int b){
    long long int r = gcd(a,b);
    return a/r*b;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        long long int a,b,c,GCD,LCM;
        scanf("%lld%lld%lld",&a,&b,&c);
        GCD = gcd(gcd(a,b),c);
        LCM = lcm(lcm(a,b),c);
        printf("%lld %lld\n",GCD,LCM);
    }
    return 0;
}
