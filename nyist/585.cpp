#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int m;
        scanf("%d",&m);
        int ans=0;
        while(m--){
            int x;
            scanf("%d",&x);
            ans^=x;
        }
        if(ans)puts("PIAOYI");
        else puts("HRDV");
    }
    return 0;
}
