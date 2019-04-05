#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=100000+5;
int l[MAXN],r[MAXN];
bool vis[MAXN];
int main(){
    int h=0,t=100000+1;
    r[h]=1;
    l[1]=h;
    r[1]=t;
    l[t]=1;
    int n;
    scanf("%d",&n);

    rep(i,2,n){
        int x,p;
        scanf("%d%d",&x,&p);
        if(p==0){
            r[l[x]]=i;
            l[i]=l[x];
            l[x]=i;
            r[i]=x;
        }else{
            l[r[x]]=i;
            r[i]=r[x];
            r[x]=i;
            l[i]=x;
        }
    }
    int m;
    scanf("%d",&m);
    while(m--){
        int x;
        scanf("%d",&x);
        vis[x]=true;
    }
    for(int i=r[h];i!=t;i=r[i]){
        if(!vis[i]){
            printf("%d ",i);
        }
    }
    return 0;
}
