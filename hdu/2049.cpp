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
const int MAXN=25;
ll D[MAXN];
ll fac[MAXN];
ll C(int a,int b){
    return fac[b]/(fac[a]*fac[b-a]);
}
int work(){
    D[1]=0;
    D[2]=1;
    rep(i,3,20){
        D[i]=1LL*(i-1)*(D[i-1]+D[i-2]);
    }
    fac[0]=1;
    rep(i,1,20){
        fac[i]=fac[i-1]*i;
    }
    int T;
    scanf("%d",&T);
    while(T--){
        int N,M;
        scanf("%d%d",&N,&M);
        printf("%lld\n",1LL*D[M]*C(M,N));
    }
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
