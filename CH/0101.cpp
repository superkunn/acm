#include<bits/stdc++.h>
using namespace std;
int pow_mod(int a,int b,int mod){
    int res=1%mod;//!!
    while(b){
        if(b&1)res=1LL*res*a%mod;
        a=1LL*a*a%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d",pow_mod(a,b,c));
    return 0;
}
