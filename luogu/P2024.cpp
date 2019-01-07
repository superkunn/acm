#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define what_is(x) cerr<<#x<<" is "<<x<<endl;
const int MAXN=1e5+233;
int p[MAXN],d[MAXN];
int findp(int x){
    if(x==p[x])return x;
    int xx=findp(p[x]);
    d[x]=(d[x]+d[p[x]])%3;
    return p[x]=xx;
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    rep(i,1,n){
        p[i]=i;
    }
    int ans=0;
    while(q--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(x>n||y>n){
            ans++;
            continue;
        }
        if(op==1){
            if(findp(x)==findp(y)){
                if(d[x]!=d[y]){
                    ans++;
                }
            }else{
                d[p[y]]=(d[x]-d[y]+3)%3;
                p[p[y]]=p[x];
            }
        }else{
            if(x==y){
                ans++;
                continue;
            }
            if(findp(x)==findp(y)){
                if(((d[x]+1)%3)!=d[y]){
                    ans++;
                }
            }else{
                d[p[y]]=(d[x]+1-d[y]+3)%3;
                p[p[y]]=p[x];
            }
        }
    }
    printf("%d",ans);
    return 0;
}
