#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
const int MAXN=1e3+10;
int a[MAXN],b[MAXN],c[MAXN];
bool dp[MAXN][220];
int main(){
    int n,m,k,l;
    scanf("%d%d%d%d",&n,&m,&k,&l);
    rep(i,1,n){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
    clr(dp,0);
    rep(i,k+100,200){
        dp[n+1][i]=1;
    }
    per(i,n,1){
        if(i%2==1){
            rep(j,0,200){
                bool f=0;
                if(a[i]>0){
                    int w=j+a[i];
                    if(w>200)w=200;
                    if(dp[i+1][w])f=1;
                }
                if(b[i]>0){
                    int w=j-b[i];
                    if(w<0)w=0;
                    if(dp[i+1][w])f=1;
                }
                if(c[i]==1){
                    int w=j-100;
                    w=-w;
                    w+=100;
                    if(dp[i+1][w])f=1;
                }
                if(f)dp[i][j]=1;
            }
        }else{
            rep(j,0,200){
                bool f=0;
                bool fz=1;
                if(a[i]>0){
                    int w=j+a[i];
                    if(w>200)w=200;
                    if(dp[i+1][w])f=1;
                    else fz=0;
                }
                if(b[i]>0){
                    int w=j-b[i];
                    if(w<0)w=0;
                    if(dp[i+1][w])f=1;
                    else fz=0;
                }
                if(c[i]==1){
                    int w=j-100;
                    w=-w;
                    w+=100;
                    if(dp[i+1][w])f=1;
                    else fz=0;
                }
                if(f&&fz)dp[i][j]=1;
            }
        }
    }
    if(dp[1][m+100]){
        puts("Good Ending");
        return 0;
    }
    clr(dp,0);
    rep(i,0,100+l){
        dp[n+1][i]=1;
    }
    per(i,n,1){
        if(i%2==0){
            rep(j,0,200){
                bool f=0;
                if(a[i]>0){
                    int w=j+a[i];
                    if(w>200)w=200;
                    if(dp[i+1][w])f=1;
                }
                if(b[i]>0){
                    int w=j-b[i];
                    if(w<0)w=0;
                    if(dp[i+1][w])f=1;
                }
                if(c[i]==1){
                    int w=j-100;
                    w=-w;
                    w+=100;
                    if(dp[i+1][w])f=1;
                }
                if(f)dp[i][j]=1;
            }
        }else{
            rep(j,0,200){
                bool f=0;
                bool fz=1;
                if(a[i]>0){
                    int w=j+a[i];
                    if(w>200)w=200;
                    if(dp[i+1][w])f=1;
                    else fz=0;
                }
                if(b[i]>0){
                    int w=j-b[i];
                    if(w<0)w=0;
                    if(dp[i+1][w])f=1;
                    else fz=0;
                }
                if(c[i]==1){
                    int w=j-100;
                    w=-w;
                    w+=100;
                    if(dp[i+1][w])f=1;
                    else fz=0;
                }
                if(f&&fz)dp[i][j]=1;
            }
        }
    }
    if(dp[1][m+100]){
        puts("Bad Ending");
        return 0;
    }
    puts("Normal Ending");
    return 0;
}
