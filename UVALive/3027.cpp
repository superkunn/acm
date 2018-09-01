#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=2e4+10;
int p[MAXN],d[MAXN];
int findp(int x){
    if(x==p[x])return x;
    int xx=findp(p[x]);
    d[x]+=d[p[x]];
    return p[x]=xx;
}
char op[3];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            p[i]=i;
            d[i]=0;
        }
        while(~scanf("%s",op)){
            if(op[0]=='O'){
                break;
            }else if(op[0]=='I'){
                int a,b;
                scanf("%d%d",&a,&b);
                p[a]=b;
                d[a]=abs(a-b)%1000;
            }else{
                int a;
                scanf("%d",&a);
                findp(a);
                printf("%d\n",d[a]);
            }
        }

    }
    return 0;
}
