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
const int MAXN=2e4+10;
int w[MAXN];
struct node{
    int v,id;
}no[MAXN<<1];
int x[MAXN<<1];
bool cmp(node x,node y){
    return x.v<y.v;
}
struct node2{
    int l,r,w;
}no2[MAXN<<1];
bool cmp2(node2 x,node2 y){
    return x.l<y.l;
}
int dp[MAXN];
int work(){
    int N,M,R;
    scanf("%d%d%d",&N,&M,&R);
    rep(i,1,M){
        scanf("%d%d%d",&no[i].v,&no[i+M].v,&w[i]);
        no[i+M].v+=R;
        no[i].id=i;
        no[i+M].id=i+M;
    }
    sort(no+1,no+1+2*M,cmp);
    int index=1;
    x[no[1].id]=index;
    rep(i,2,2*M){
        if(no[i].v!=no[i-1].v)index++;
        x[no[i].id]=index;
    }
    rep(i,1,M){
        no2[i].l=x[i];
        no2[i].r=x[i+M];
        no2[i].w=w[i];
    }
    sort(no2+1,no2+1+M,cmp2);
    int now=1;
    rep(i,1,M){
        while(now<=no2[i].l){
            dp[now]=max(dp[now],dp[now-1]);
            now++;
        }
        dp[no2[i].r]=max(dp[no2[i].r],dp[no2[i].l]+no2[i].w);
        rep(j,no2[i].r,index+1)dp[j]=max(dp[j],dp[j-1]);
//        rep(j,0,index+1)printf("%d%c",dp[j]," \n"[j==index+1]);
    }
    while(now<=index+1){
        dp[now]=max(dp[now],dp[now-1]);
        now++;
    }
    printf("%d",dp[index+1]);
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
