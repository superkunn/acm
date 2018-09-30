#include<bits/stdc++.h>
using namespace std;
char a[5][7];
int dp[5][5];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool check(int x,int y){
    if(x<0||x>4||y<0||y>4)return false;
    else return true;
}
void fun(int x,int y){
    dp[x][y]^=1;
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(check(xx,yy)){
            dp[xx][yy]^=1;
        }
    }
}
void print(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
            cout<<dp[i][j];
        cout<<endl;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int ans=100;
        for(int i=0;i<5;i++)scanf("%s",a[i]);
        for(int k=0;k<(1<<5);k++){
            for(int i=0;i<5;i++)
                for(int j=0;j<5;j++)
                    dp[i][j]=int(a[i][j]-'0');
            //print();
            int cnt=0;
            for(int i=0;i<5;i++){
                if((k>>i&1)==0)fun(0,i),cnt++;
            }
            bool f=1;
            for(int i=1;i<5;i++){
                for(int j=0;j<5;j++){
                    if(dp[i-1][j]==0){
                        fun(i,j);
                        cnt++;
                    }
                }
                if(cnt>6){
                    f=false;
                    break;
                }
            }
            for(int i=0;i<5;i++){
                if(dp[4][i]==0){
                    f=false;
                    break;
                }
            }
            if(!f)continue;
            ans=min(ans,cnt);
        }
        printf("%d\n",ans==100?-1:ans);
    }
    return 0;
}
