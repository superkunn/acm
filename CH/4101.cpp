#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
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
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=3e4+10;
char op[5];
struct DSU{
    int p[MAXN];
    int d[MAXN];
    int sum[MAXN];
    void init(int n){
        for(int i=1;i<=n;i++){
            p[i]=i;
            d[i]=0;
            sum[i]=1;
        }
    }
    int findp(int x){
        if(x==p[x])return x;
        int xx=findp(p[x]);
        d[x]+=d[p[x]];
        return p[x]=xx;
    }
    void unite(int x,int y){
        int xx=findp(x);
        int yy=findp(y);
        if(xx==yy)return;
        p[xx]=yy;
        d[xx]=sum[yy];
        sum[yy]+=sum[xx];
    }
    bool same(int x,int y){
        return findp(x)==findp(y);
    }
    int gao(int x,int y){
        findp(x);
        findp(y);
        return abs(d[x]-d[y])-1;
    }
}dsu;
int main(){
    int T;
    scanf("%d",&T);
    dsu.init(30000);
    while(T--){
        scanf("%s",op);
        int x,y;
        scanf("%d%d",&x,&y);
        if(op[0]=='M'){
            dsu.unite(x,y);
        }else{
            if(!dsu.same(x,y)){
                puts("-1");
            }else{
                printf("%d\n",dsu.gao(x,y));
            }
        }
    }
    return 0;
}
