#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
char mm[105][105];
int n,m;
int dx[8]={0,0,1,1,1,-1,-1,-1};
int dy[8]={1,-1,1,-1,0,1,-1,0};
bool check(int x,int y){
    if(1<=x&&x<=n&&1<=y&&y<=m)return true;
    else return false;
}
void dfs(int x,int y){
    mm[x][y]='.';
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(check(nx,ny)&&mm[nx][ny]=='W'){
            dfs(nx,ny);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%s",mm[i]+1);
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mm[i][j]=='W'){
                ans++;
                dfs(i,j);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
