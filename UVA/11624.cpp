#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
const int MAXN=1e3+10;
char mmp[MAXN][MAXN];
int mm[MAXN][MAXN];
int R,C;
pii p;
queue<pii > que;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool check(int x,int y){
    if(x<1||y<1||x>R||y>C)return false;
    if(mm[x][y]==-2)return true;
    else return false;
}
bool check2(int x,int y,int k){
    if(x<1||y<1||x>R||y>C)return false;
    if(mm[x][y]>k|mm[x][y]==-2)return true;
    else return false;
}
bool check3(int x,int y){
    if(x==1||y==1||x==R||y==C)return true;
    else return false;
}
void print(){
    rep(i,1,R){
        rep(j,1,C){
            printf("%d ",mm[i][j]);
        }
        puts("");
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        while(!que.empty())que.pop();
        scanf("%d%d",&R,&C);
        int xx,yy;
        rep(i,1,R)scanf("%s",mmp[i]+1);
        rep(i,1,R){
            rep(j,1,C){
                if(mmp[i][j]=='#')mm[i][j]=-1;
                else if(mmp[i][j]=='F')mm[i][j]=0,que.push(mp(i,j));
                else if(mmp[i][j]=='.')mm[i][j]=-2;
                else if(mmp[i][j]=='J')mm[i][j]=0,xx=i,yy=j;
            }
        }
        while(!que.empty()){
            pii t=que.front();
            que.pop();
            rep(i,0,3){
                int x=t.fi+dx[i];
                int y=t.se+dy[i];
                if(check(x,y)){
                    mm[x][y]=mm[t.fi][t.se]+1;
                    que.push(mp(x,y));
                }
            }
        }
        //print();
        bool f=0;
        que.push(mp(xx,yy));
        while(!que.empty()){
            pii t=que.front();
            que.pop();
            //cout<<t.fi<<"--"<<t.se<<endl;
            if(check3(t.fi,t.se)){
                printf("%d\n",mm[t.fi][t.se]+1);
                f=1;
                break;
            }
            rep(i,0,3){
                int x=t.fi+dx[i];
                int y=t.se+dy[i];
                if(check2(x,y,mm[t.fi][t.se]+1)){
                    mm[x][y]=mm[t.fi][t.se]+1;
                    que.push(mp(x,y));
                }
            }
        }
        if(!f)puts("IMPOSSIBLE");
    }
    return 0;
}
