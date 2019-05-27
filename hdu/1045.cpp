#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define SZ(x) ((int)(x).size())
#define lson rt<<1
#define rson rt<<1|1
#define pb push_back
#define fi first
#define se second
#define what_is(x) cerr<<#x<<" "<<x<<endl;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
template <typename T>
inline void _read(T& x){
    cin>>x;
}
void R(){}
template <typename T,typename... U>
void R(T&head,U&... tail){
    _read(head);
    R(tail...);
}

template <typename T>
inline void _write(const T& x){
    cout<<x<<' ';
}
void W(){cout<<endl;}
template <typename T,typename... U>
void W(const T&head,const U&... tail){
    _write(head);
    W(tail...);
}

void go();
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout<<fixed<<setprecision(15);
    go();
    return 0;
}
/****************ackun*********************/
namespace G1{
    const int MAXV=20;
    const int MAXE=20;
    int tot;
    int head[MAXV];
    struct Edge{
        int v,nxt;
    }edge[MAXE<<1];
    int n;
    void init(int _n){//一共n个点
        n=_n;
        tot=0;
        clr(head,-1);
    }
    void add_edge(int u,int v){
        edge[tot]=Edge{v,head[u]};
        head[u]=tot++;
    }
    int match[MAXV];
    bool used[MAXV];
    bool dfs(int u){
        used[u]=true;
        for(int i=head[u];~i;i=edge[i].nxt){
            int v=edge[i].v;
            int w=match[v];
            if(w<0||!used[w]&&dfs(w)){
                match[u]=v;
                match[v]=u;
                return true;
            }
        }
        return false;
    }
    int gao(){
        int res=0;
        clr(match,-1);
        rep(i,1,n){
            if(match[i]<0){
                clr(used,0);
                if(dfs(i)){
                    res++;
                }
            }
        }
        return res;
    }
}
string s[4];
int n,tot;
int vis1[4][4],vis2[4][4];
void dfs1(int x,int y){
    vis1[x][y]=tot;
    if(y<n-1&&!vis1[x][y+1]&&s[x][y+1]=='.'){
        dfs1(x,y+1);
    }
}
void dfs2(int x,int y){
    vis2[x][y]=tot;
    if(x<n-1&&!vis2[x+1][y]&&s[x+1][y]=='.'){
        dfs2(x+1,y);
    }
}
void go(){
    while(true){
        R(n);
        if(n==0){
            break;
        }
        rep(i,0,n-1){
            R(s[i]);
        }
        tot=0;
        clr(vis1,0);
        clr(vis2,0);
        rep(i,0,n-1){
            rep(j,0,n-1){
                if(s[i][j]=='.'&&!vis1[i][j]){
                    ++tot;
                    dfs1(i,j);
                }
                if(s[i][j]=='.'&&!vis2[i][j]){
                    ++tot;
                    dfs2(i,j);
                }
            }
        }
        set<pii> st;
        rep(i,0,n-1){
            rep(j,0,n-1){
                if(vis1[i][j]){
                    st.insert({vis1[i][j],vis2[i][j]});
                }
            }
        }
        G1::init(tot);
        for(auto x:st){
            G1::add_edge(x.fi,x.se);
            G1::add_edge(x.se,x.fi);
        }
        cout<<G1::gao()<<endl;
    }
}
