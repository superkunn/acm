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
inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
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
    int n=read();
    while(n--){
        int x=read();
        int y=read();
        dsu.init(x);
        while(y--){
            char c;
            scanf("%c",&c);
            int a=read();
            int b=read();
            if(c=='D'){
                dsu.unite(a,b);
            }
            else{
                if(!dsu.same(a,b)){
                    puts("Not sure yet.");
                }
                else{
                    if(dsu.w[a]==dsu.w[b]){
                        puts("In the same gang.");
                    }
                    else{
                        puts("In different gangs.");
                    }
                }
            }
        }
    }
}
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    solve();
    return 0;
}
