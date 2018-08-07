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
const int MAXN=4e4+5;
const int MAXM=1e4+5;
map<char,int> mmp;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,q,a,b,d,ans,p[MAXN],x[MAXN],y[MAXN];
char op[5];
struct node1{
    int a,b,d,c;
    node1(){}
    node1(int a,int b,int d,int c):a(a),b(b),d(d),c(c){}
}no1[MAXN];
int findp(int a){
    if(a==p[a])return a;
    int aa=findp(p[a]);
    x[a]+=x[p[a]];
    y[a]+=y[p[a]];
    return p[a]=aa;
}
void update(int pos){
    node1 kk=no1[pos];
    int aa=findp(kk.a);
    int bb=findp(kk.b);
    if(aa==bb)return;
    p[bb]=aa;
    x[bb]=x[kk.a]+dx[kk.c]*kk.d-x[kk.b];
    y[bb]=y[kk.a]+dy[kk.c]*kk.d-y[kk.b];
}
int fun(int x1,int y1,int x2,int y2){
    return abs(x1-x2)+abs(y1-y2);
}
int main(){
    mmp['N']=0;
    mmp['E']=1;
    mmp['S']=2;
    mmp['W']=3;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        p[i]=i;
        x[i]=y[i]=0;
    }
    rep(i,1,m){
        scanf("%d%d%d%s",&a,&b,&d,op);
        no1[i]=node1(a,b,d,mmp[op[0]]);
    }
    scanf("%d",&q);
    int now=0;
    rep(i,1,q){
        scanf("%d%d%d",&a,&b,&d);
        while(now<d)update(++now);
        int aa=findp(a);
        int bb=findp(b);
        if(aa!=bb)ans=-1;
        else ans=fun(x[a],y[a],x[b],y[b]);
        printf("%d\n",ans);
    }
    return 0;
}
