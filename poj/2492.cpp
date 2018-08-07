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
const int MAXN=2e3+5;
int n,m,a,b,p[MAXN],w[MAXN];
int findp(int x){
    if(x==p[x])return x;
    int xx=findp(p[x]);
    w[x]=(w[x]+w[p[x]])%2;
    return p[x]=xx;
}
int work(){
    int T;
    scanf("%d",&T);
    rep(kase,1,T){
        bool f=0;
        scanf("%d%d",&n,&m);
        rep(i,1,n){
            p[i]=i;
            w[i]=0;
        }
        while(m--){
            scanf("%d%d",&a,&b);
            if(f)continue;
            int aa=findp(a),bb=findp(b);
            if(aa==bb){
                if(w[a]==w[b])f=1;
            }else{
                w[bb]=(w[a]+1-w[b]+2)%2;
                p[bb]=aa;
            }
        }
        printf("Scenario #%d:\n%s\n\n",kase,f?"Suspicious bugs found!":"No suspicious bugs found!");
    }
    return 0;
}
int main(){
    work();
    return 0;
}
