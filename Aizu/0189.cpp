#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=1e5;
int mm[10][10];
int main(){
    int n;
    while(~scanf("%d",&n)){
        if(n==0)break;
        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                if(i==j)mm[i][j]=0;
                else mm[i][j]=INF;
            }
        }
        for(int i=1;i<=n;i++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            mm[x][y]=min(mm[x][y],z);
            mm[y][x]=mm[x][y];
        }
        for(int k=0;k<=9;k++){
            for(int i=0;i<=9;i++){
                for(int j=0;j<=9;j++){
                    if(mm[i][j]>mm[i][k]+mm[k][j])mm[i][j]=mm[i][k]+mm[k][j];
                }
            }
        }
        int id=0;
        int ans=INF;
        for(int i=0;i<=9;i++){
            int now=0;
            for(int j=0;j<=9;j++){
                if(mm[i][j]==INF)continue;
                now+=mm[i][j];
            }
            if(now==0)continue;
            if(now<ans){
                id=i;
                ans=now;
            }
        }
        printf("%d %d\n",id,ans);
    }
    return 0;
}
