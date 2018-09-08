#include<cstdio>
#include<cstring>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define clr(a,x) memset(a,x,sizeof(a))
const int MAXN=105;
const int MAXM=1e5+10;
int x[MAXN];
int num[MAXN];
int cnt[MAXM];
bool vis[MAXM];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),n+m){
        rep(i,1,n)scanf("%d",&x[i]);
        rep(i,1,n)scanf("%d",&num[i]);
        clr(vis,0);
        vis[0]=1;
        int ans=0;
        rep(i,1,n){
            int step=x[i];
            clr(cnt,0);
            rep(j,0,m-step){
                if(vis[j]==1&&(!vis[j+step])&&cnt[j]<num[i]){
                    cnt[j+step]=cnt[j]+1;
                    vis[j+step]=1;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
