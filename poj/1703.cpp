#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define DEC(i,a,b) for(int i=a;i>=b;i--)
#define PB push_back
#define FT first;
#define SD second;
#define ALL(X) (X).begin(),(X).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/************long long****************/
const int MAXN=1e5+50;
struct DSU{
    int p[MAXN],w[MAXN];
    void init(int n){for(int i=0;i<=n;i++)p[i]=i,w[i]=0;}
    int findp(int x){
        if(x==p[x])return x;
        int xx=findp(p[x]);
        w[x]=(w[x]+w[p[x]])%2;
        return p[x]=xx;
    }
    void unite(int x,int y){
        int xx=findp(x),yy=findp(y);
        p[xx]=yy;
        w[xx]=(w[y]-w[x]+1)%2;
    }
    bool same(int x,int y){return findp(x)==findp(y);}
}dsu;
void solve(){
    int n;
    scanf("%d",&n);
    while(n--){
        int x,y;
        scanf("%d%d",&x,&y);
        dsu.init(x);
        while(y--){
            char c;
            int a,b;
            getchar();
            scanf("%c%d%d",&c,&a,&b);
            if(c=='D'){
                dsu.unite(a,b);
            }
            else{
                if(!dsu.same(a,b)){
                    printf("Not sure yet.\n");
                }
                else{
                    if(dsu.w[a]==dsu.w[b]){
                        printf("In the same gang.\n");
                    }
                    else{
                        printf("In different gangs.\n");
                    }
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
