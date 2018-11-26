#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <bitset>
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
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
int dp[35][35][35];
int bt[35];
int dfs(int pos,int cnt0,int cnt1,bool limit,bool lead){
    if(pos==0)return cnt0>=cnt1;
    if(!limit&&!lead&&dp[pos][cnt0][cnt1]!=-1)return dp[pos][cnt0][cnt1];
    int u=limit?bt[pos]:1;
    int res=0;
    rep(i,0,u){
        if(lead){
            if(i==0){
                res+=dfs(pos-1,cnt0,cnt1,limit&&i==bt[pos],true);
            }else{
                res+=dfs(pos-1,cnt0,cnt1+1,limit&&i==bt[pos],false);
            }
        }else{
            if(i==0){
                res+=dfs(pos-1,cnt0+1,cnt1,limit&&i==bt[pos],false);
            }else{
                res+=dfs(pos-1,cnt0,cnt1+1,limit&&i==bt[pos],false);
            }
        }
    }
    if(!limit&&!lead)dp[pos][cnt0][cnt1]=res;
    return res;
}
int gao(int x){
    int pos=0;
    while(x){
        bt[++pos]=x&1;
        x>>=1;
    }
    return dfs(pos,0,0,true,true);
}
int main(){
    clr(dp,-1);
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d",gao(y)-gao(x-1));
    return 0;
}
