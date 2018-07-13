#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
const int INF=1e6;
int mm[305][305];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
struct node{
    int x,y,t;
};
queue<node> que;
bool check(int x,int y){
    if(x>=0&&y>=0)return true;
    else return false;
}
int bfs(int x,int y,int t){
    while(!que.empty())que.pop();
    node tt;
    tt.x=x;
    tt.y=y;
    tt.t=t;
    que.push(tt);
    while(!que.empty()){
        tt=que.front();
        que.pop();
        if(mm[tt.x][tt.y]<=tt.t)continue;
        if(mm[tt.x][tt.y]==INF){
            return tt.t;
        }
        mm[tt.x][tt.y]=0;
        for(int i=0;i<4;i++){
            int nx=tt.x+dx[i];
            int ny=tt.y+dy[i];
            if(check(nx,ny)){
                node ttt;
                ttt.x=nx;
                ttt.y=ny;
                ttt.t=tt.t+1;
                que.push(ttt);
            }
        }
    }
    return -1;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=302;i++){
        for(int j=0;j<=302;j++){
            mm[i][j]=INF;
        }
    }
    while(n--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        mm[x][y]=min(z,mm[x][y]);
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(check(nx,ny)){
                mm[nx][ny]=min(z,mm[nx][ny]);
            }
        }
    }
    printf("%d",bfs(0,0,0));
    return 0; 
}
