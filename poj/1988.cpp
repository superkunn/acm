
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
const int MAXN=3e4+5;
int p[MAXN],num[MAXN],sum[MAXN];
void init(int n){
    rep(i,1,n){
        p[i]=i;
        num[i]=0;
        sum[i]=1;
    }
}
int findp(int x){
    int xxx=p[x];
    if(x==p[x]){
        return x;
    }else{
        int xx=findp(p[x]);
        num[x]+=num[p[x]];
        return p[x]=xx;
    }
}
void unite(int x,int y){
    x=findp(x);
    y=findp(y);
    num[x]=sum[y];
    sum[y]+=sum[x];
    p[x]=y;
}
char op[5];
int a,b;
int work(){
    init(30000);
    int P;
    scanf("%d",&P);
    while(P--){
        scanf("%s",op);
        if(op[0]=='M'){
            scanf("%d%d",&a,&b);
            unite(a,b);
        }else{
            scanf("%d",&a);
            findp(a);
            printf("%d\n",num[a]);
        }
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
