#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1e6+10;
int v[MAXN];
int ans[MAXN];
int cnt;
int fun(int x){
    int res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int tot=0;
    rep(i,1,n){
        int now=i%5000;
        if(v[now]==0){
            ans[++cnt]=i;
            tot++;
        }
        v[now]=0;
        int w=i+fun(i);
        w%=5000;
        v[w]=1;
    }
    printf("%d\n",tot);
    rep(i,1,k){
        int x;
        scanf("%d",&x);
        printf("%d ",ans[x]);
    }
    return 0;
}
