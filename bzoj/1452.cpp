#include<bits/stdc++.h>
using namespace std;
const int MAXN=305;
int n,m;
int c[105][MAXN][MAXN];
int mmp[MAXN][MAXN];
void add(int cc,int x,int y,int v){
    for(int i=x;i<=n;i+=i&-i){
        for(int j=y;j<=m;j+=j&-j){
            c[cc][i][j]+=v;
        }
    }
}
int sum(int cc,int x,int y){
    int s=0;
    for(int i=x;i>0;i-=i&-i){
        for(int j=y;j>0;j-=j&-j){
            s+=c[cc][i][j];
        }
    }
    return s;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            scanf("%d",&x);
            add(x,i,j,1);
            mmp[i][j]=x;
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(mmp[x][y]!=z){
                add(mmp[x][y],x,y,-1);
                add(z,x,y,1);
                mmp[x][y]=z;
            }
        }
        else{
            int ans=0;
            int x1,x2,y1,y2,cc;
            scanf("%d%d%d%d%d",&x1,&x2,&y1,&y2,&cc);
            ans+=sum(cc,x2,y2);
            ans-=sum(cc,x2,y1-1);
            ans-=sum(cc,x1-1,y2);
            ans+=sum(cc,x1-1,y1-1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
