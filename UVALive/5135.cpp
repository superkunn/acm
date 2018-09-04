#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define clr(a,x) memset(a,x,sizeof(a))
#define mp make_pair
#define fi first
#define se second
#define pb push_back
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
const int MAXV=5e4+10;
const int MAXE=5e4+10;
int tot;
int head[MAXV];
struct Edge{
    int v,nxt;
    Edge(){}
    Edge(int v,int nxt):v(v),nxt(nxt){}
}edge[MAXE<<1];
void init(){
    tot=0;
    clr(head,-1);
}
void add_edge(int u,int v){
    edge[tot]=Edge(v,head[u]);
    head[u]=tot++;
}
int pre[MAXV],bccno[MAXV],is_cut[MAXV],dfs_clock,bcc_cnt;
vi bcc[MAXV];
stack<pii > st;
int dfs(int u,int fa){
    int lowu=pre[u]=++dfs_clock;
    int child=0;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        pii e=mp(u,v);
        if(!pre[v]){
            st.push(e);
            child++;
            int lowv=dfs(v,u);
            lowu=min(lowu,lowv);
            if(lowv>=pre[u]){
                is_cut[u]=1;
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                for(;;){
                    pii x=st.top();
                    st.pop();
                    if(bccno[x.fi]!=bcc_cnt){
                        bcc[bcc_cnt].pb(x.fi);
                        bccno[x.fi]=bcc_cnt;
                    }
                    if(bccno[x.se]!=bcc_cnt){
                        bcc[bcc_cnt].pb(x.se);
                        bccno[x.se]=bcc_cnt;
                    }
                    if(x.fi==u&&x.se==v)break;
                }
            }
        }else if(pre[v]<pre[u]&&v!=fa){
            st.push(e);
            lowu=min(lowu,pre[v]);
        }
    }
    if(fa<0&&child==1)is_cut[u]=0;
    return lowu;
}
void find_bcc(int n){
    clr(pre,0);
    clr(bccno,0);
    clr(is_cut,0);
    dfs_clock=bcc_cnt=0;
    rep(i,1,n)if(!pre[i])dfs(i,-1);
}
int main(){
    int m;
    int kase=0;
    while(scanf("%d",&m),m){
        int n=1;
        init();
        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            int n=max(n,max(x,y));
            add_edge(x,y);
            add_edge(y,x);
        }
        find_bcc(n);
        ll ans1=0,ans2=1;
        rep(i,1,bcc_cnt){
            int cnt=0;
            for(int j=0;j<bcc[i].size();j++){
                if(is_cut[bcc[i][j]])cnt++;
            }
            if(cnt==1){
                ans1++;ans2*=1LL*(bcc[i].size()-cnt);
            }
        }
        if(bcc_cnt==1){
            ans1=2;
            ans2=1LL*bcc[1].size()*(bcc[1].size()-1)/2;
        }
        printf("Case %d: %lld %lld\n",++kase,ans1,ans2);
    }
    return 0;
}
