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
#define ALL(X) (X).begin(),(X).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/************long long****************/
const int MAXN=1e3+5;
struct DSU{
    int p[MAXN],r[MAXN];
    void init(int n){for(int i=0;i<=n;i++)p[i]=i,r[i]=0;}
    int findp(int x){return x==p[x]?x:p[x]=findp(p[x]);}
    void unite(int x,int y){
        x=findp(x),y=findp(y);
        if(x==y)return;
        if(r[x]<r[y])p[x]=y;
        else p[y]=x;
        if(r[x]==r[y])r[x]++;
    }
    bool same(int x,int y){return findp(x)==findp(y);}
}dsu;
vector<pii> vec;
bool check(int x,int y,int xx,int yy,int d){
    return (x-xx)*(x-xx)+(y-yy)*(y-yy)<=d*d;
}
bool z[MAXN];
void solve(){
    int n,d;
    cin>>n>>d;
    dsu.init(n);
    REP(i,0,n-1){
        int x,y;
        cin>>x>>y;
        vec.PB({x,y});
    }
    char c;
    while(cin>>c){
        if(c=='O'){
            int x;
            cin>>x;
            z[x]=true;
            for(int i=0;i<n;i++){
                if(z[i+1]&&check(vec[x-1].first,vec[x-1].second,vec[i].first,vec[i].second,d))dsu.unite(x,i+1);
            }
        }
        else{
            int x,y;
            cin>>x>>y;
            if(dsu.same(x,y))cout<<"SUCCESS\n";
            else cout<<"FAIL\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
