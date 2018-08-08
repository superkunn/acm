#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <cstdio>
#include    <vector>
#include     <stack>
#include     <queue>
#include     <cmath>
#include       <set>
#include       <map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=5e3+5;
char op[10];
struct node{
    int v,id;
}no[MAXN<<1];
bool cmp(node x,node y){
    return x.v<y.v;
}
int noo[MAXN<<1];
int eo[MAXN];
int n;
struct DSU{
    int p[MAXN<<1],w[MAXN<<1];
    void init(int n){
        rep(i,0,n)p[i]=i,w[i]=0;
    }
    int findp(int x){
        if(x==p[x])return x;
        int xx=findp(p[x]);
        w[x]=(w[x]+w[p[x]])%2;
        return p[x]=findp(p[x]);
    }
    bool unite(int x,int y,int o){
        int xx=findp(x);
        int yy=findp(y);
        if(xx==yy){
            if(o==0){
                return w[x]==w[y];
            }else{
                return w[x]!=w[y];
            }
        }
        p[yy]=xx;
        w[yy]=(w[x]+o-w[y]+2)%2;
        return true;
    }
}dsu;
int work(){
    scanf("%*d%d",&n);
    rep(i,1,n){
        scanf("%d%d%s",&no[i].v,&no[i+n].v,op);
        no[i].id=i;
        no[i+n].id=i+n;
        if(op[0]=='e')eo[i]=0;
        else eo[i]=1;
    }
    sort(no+1,no+1+2*n,cmp);
    int index=1;
    noo[no[1].id]=index;
    rep(i,2,2*n){
        if(no[i].v!=no[i-1].v)index++;
        noo[no[i].id]=index;
    }
    dsu.init(2*n);
    int ans=0;
    while(dsu.unite(noo[ans+1]-1,noo[ans+1+n],eo[ans+1])&&ans<n){
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
