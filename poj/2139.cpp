#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=300+5;
const int INF=1e9;
int a[MAXN][MAXN];
int b[MAXN];
void draw(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d%c",a[i][j]," \n"[j==n]);
        }
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            a[i][j]=a[j][i]=INF;
        }
    }
    //draw(n);
    while(m--){
        int nn;
        scanf("%d",&nn);
        for(int i=1;i<=nn;i++){
            scanf("%d",&b[i]);
        }
        for(int i=1;i<=nn;i++){
            for(int j=i+1;j<=nn;j++){
                int x=b[i];
                int y=b[j];
                a[x][y]=a[y][x]=1;
            }
        }
    }
    //draw(n);
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    //draw(n);
    int ans=INF;
    for(int i=1;i<=n;i++){
        int now=0;
        for(int j=1;j<=n;j++){
            now+=a[i][j];
        }
        ans=min(ans,now);
    }
    printf("%d",(int)(ans*100.0/(n-1)));
    return 0;
}
