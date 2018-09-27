#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=105;
int a[MAXN];
int main(){
    int n;
    while(scanf("%d",&n),n){
        memset(a,0,sizeof(a));
        rep(i,1,n){
            int x;
            scanf("%d",&x);
            a[x]++;
        }
        bool f=0;
        rep(i,1,100){
            if(a[i]&1){
                f=1;
                break;
            }
        }
        if(f)puts("Win");
        else puts("Lose");
    }
    return 0;
}
