#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
const int MAXN=1e4+5;
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
char mm[125][125];
int main(){
    int W,H;
    while(~scanf("%d%d",&H,&W)){
        if(W==0&&H==0)break;
        dsu.init(W*H);
        for(int i=1;i<=H;i++){
            scanf("%s",mm[i]+1);
        }
        for(int i=1;i<=H;i++){
            for(int j=1;j<=W;j++){
                if(i!=1&&(mm[i-1][j]==mm[i][j]||mm[i-1][j]==mm[i][j])){
                    dsu.unite((i-1)*W+j,(i-2)*W+j);
                }
                if(j!=1&&(mm[i][j-1]==mm[i][j]||mm[i][j-1]==mm[i][j])){
                    dsu.unite((i-1)*W+j,(i-1)*W+j-1);
                }
            }
        }
        set<int> ss;
        for(int i=1;i<=W*H;i++){
            ss.insert(dsu.findp(i));
        }
        printf("%d\n",ss.size());
    }
    return 0; 
}
