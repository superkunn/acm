#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define clr(a,x) memset(a,x,sizeof(a))
const int MAXN=30;
const int INF=1e9;
int n,m;
char mmp[MAXN][MAXN];
bool vis[MAXN][MAXN][10][10];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int stx,sty,edx,edy;
struct node{
    int x,y,d,c,step;
    node(){}
    node(int x,int y,int d,int c,int step):x(x),y(y),d(d),c(c),step(step){}
};
bool check(int x,int y){
    if(x<1||y<1||x>n||y>m)return false;
    else return true;
}
int main(){
    int kase=0;
    bool f=1;
    while(scanf("%d%d",&n,&m),n+m){
        if(f){
            f=0;
        }else puts("");
        rep(i,1,n){
            scanf("%s",mmp[i]+1);
            rep(j,1,m){
                if(mmp[i][j]=='S'){
                    stx=i;
                    sty=j;
                }else if(mmp[i][j]=='T'){
                    edx=i;
                    edy=j;
                }
            }
        }
        clr(vis,0);
        node t=node(stx,sty,0,0,0);
        vis[stx][sty][0][0]=1;
        queue<node> que;
        que.push(t);
        int ans=INF;
        while(!que.empty()){
            node t=que.front();
            que.pop();
            if(t.x==edx&&t.y==edy&&t.c==0){
                ans=t.step;
                break;
            }
            int x=t.x+dx[t.d];
            int y=t.y+dy[t.d];
            if(check(x,y)){
                if(!vis[x][y][t.d][(t.c+1)%5]&&mmp[x][y]!='#'){
                    node tt=node(x,y,t.d,(t.c+1)%5,t.step+1);
                    que.push(tt);
                    vis[x][y][t.d][(t.c+1)%5]=1;
                }
            }
            if(!vis[t.x][t.y][(t.d+1)%4][t.c]){
                node tt=node(t.x,t.y,(t.d+1)%4,t.c,t.step+1);
                que.push(tt);
                vis[t.x][t.y][(t.d+1)%4][t.c]=1;
            }
            if(!vis[t.x][t.y][(t.d-1)%4][t.c]){
                node tt=node(t.x,t.y,(t.d-1+4)%4,t.c,t.step+1);
                que.push(tt);
                vis[t.x][t.y][(t.d-1+4)%4][t.c]=1;
            }
        }
        printf("Case #%d\n",++kase);
        if(ans==INF)puts("destination not reachable");
        else printf("minimum time = %d sec\n",ans);
    }
    return 0;
}
