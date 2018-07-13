#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=405;
struct DSU{
    int p[MAXN],r[MAXN];
    void init(int x){
        for(int i=0;i<=x;i++){
            p[i]=i;
            r[i]=0;
        }
    }
    int findp(int x){
        if(x==p[x])return x;
        else return p[x]=findp(p[x]);
    }
    void unite(int x,int y){
        x=findp(x);
        y=findp(y);
        if(x==y)return;
        if(r[x]<r[y]){
            p[x]=y;
        }
        else{
            p[y]=x;
            if(r[x]==r[y])r[x]++;
        }
    }
    bool same(int x,int y){
        return findp(x)==findp(y);
    }    
}dsu;
char mm[25][25];
int main(){
    int W,H;
    while(~scanf("%d%d",&W,&H)){
        if(W==0&&H==0)break;
        dsu.init(W*H);
        for(int i=1;i<=H;i++){
            scanf("%s",mm[i]+1);
        }
        int x;
        for(int i=1;i<=H;i++){
            for(int j=1;j<=W;j++){
                if(mm[i][j]=='@')x=(i-1)*W+j;
                if(mm[i][j]=='.'||mm[i][j]=='@'){
                    if(i!=1&&(mm[i-1][j]=='.'||mm[i-1][j]=='@')){
                        dsu.unite((i-1)*W+j,(i-2)*W+j);
                    }
                    if(j!=1&&(mm[i][j-1]=='.'||mm[i][j-1]=='@')){
                        dsu.unite((i-1)*W+j,(i-1)*W+j-1);
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=W*H;i++){
            if(dsu.same(x,i))ans++;
        }
        printf("%d\n",ans);
    }
    return 0; 
}
