#include<iostream>
#include<cstdio>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=2000+10;
int n,m;
char s[MAXN];
int cost[26];
int dp[3][MAXN];
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    rep(i,0,n-1){
        char cc[2];
        int x,y;
        scanf("%s%d%d",cc,&x,&y);
        cost[cc[0]-'a']=min(x,y);
    }
    int now=0;
    for(int i=2;i<=m;i++){
        now=(now+1)%3;
        for(int j=1;j+i-1<=m;j++){
            dp[now][j]=min(dp[(now-1+3)%3][j]+cost[s[j+i-1]-'a'],cost[s[j]-'a']+dp[(now-1+3)%3][j+1]);
            if(s[j]==s[j+i-1]){
                dp[now][j]=min(dp[now][j],dp[(now-2+3)%3][j+1]);
            }
        }
    }
    printf("%d",dp[now][1]);
    return 0;
}
