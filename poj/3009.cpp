#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
int mm[25][25];
int w,h;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans;
bool check(int x,int y){
    if(1<=x&&x<=h&&1<=y&&y<=w)return true;
    else return false;
}
void dfs(int x,int y,int step){
    if(step>10)return;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        while(check(nx,ny)&&mm[nx][ny]!=1){
            if(mm[nx][ny]==3){
                ans=step<ans?step:ans;
            }
            nx+=dx[i];
            ny+=dy[i];
            if(check(nx,ny)&&mm[nx][ny]==1){
                mm[nx][ny]=0;
                dfs(nx-dx[i],ny-dy[i],step+1);
                mm[nx][ny]=1;
                break;
            }
        }
    }
    return;
}
int main(){
    while(~scanf("%d%d",&w,&h)){
        if(w==0&&h==0)break;
        ans=2018;
        int stx,sty,ex,ey;
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                scanf("%d",&mm[i][j]);
                if(mm[i][j]==2){
                    stx=i;
                    sty=j;
                }
                else if(mm[i][j]==3){
                    ex=i;
                    ey=j;
                }
            }
        }
        dfs(stx,sty,1);
        printf("%d\n",ans==2018?-1:ans);
    }
    return 0; 
}
