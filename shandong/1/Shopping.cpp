//Shopping
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n),n){
        if(n==1){
            puts("0");
            continue;
        }
        long long mi=1e8;
        long long ma=-1;
        while(n--){
            long long x;
            scanf("%lld",&x);
            mi=min(mi,x);
            ma=max(ma,x);
        }
        printf("%lld\n",(ma-mi)*2);
    }
    return 0;
}
