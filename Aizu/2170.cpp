
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
const int MAXN=1e5+5;
int N,Q;
int p[MAXN],t[MAXN],q[MAXN];
int now,k;
char op[5];
void init(int n){
    p[1]=1;
    rep(i,2,n){
        scanf("%d",&p[i]);
    }
    memset(t,-1,sizeof(t));
}
int findp(int x,int i){
    if(t[x]!=-1&&t[x]<i)return x;
    else return p[x]=findp(p[x],i);
}
int work(){
    while(~scanf("%d%d",&N,&Q)){
        if(N==0&&Q==0)break;
        init(N);
        now=0;
        t[1]=0;
        while(Q--){
            scanf("%s%d",op,&k); 
            if(op[0]=='M'){
                if(t[k]==-1)t[k]=now;
            }else{
                q[++now]=k;
            }
        }
        ll ans=0;
        per(i,now,1){
            ans+=findp(q[i],i);
        }
        printf("%lld\n",ans);
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
