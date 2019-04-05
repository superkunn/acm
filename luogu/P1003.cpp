#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1e4+10;
int a[MAXN][5];
int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        rep(j,1,4){
            scanf("%d",&a[i][j]);
        }
    }
    int x,y;
    scanf("%d%d",&x,&y);
    int ans=-1;
    rep(i,1,n){
        if((a[i][1]<=x)&&(x<a[i][1]+a[i][3])&&(a[i][2]<=y)&&(y<a[i][2]+a[i][4])){
            ans=i;
        }
    }
    printf("%d",ans);
}
