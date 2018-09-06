#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> pii;
const int MAXV=510;
const int MAXE=1000+10;
const int INF=0x3f3f3f3f;
int tot;
int head[MAXV];
struct Edge{
    int v,c,nxt;
    Edge(){}
    Edge(int v,int c,int nxt):v(v),c(c),nxt(nxt){}
}edge[MAXE<<1];
void init(){
    tot=0;
    clr(head,-1);
}
void add_edge(int u,int v,int c){
    edge[tot]=Edge(v,c,head[u]);
    head[u]=tot++;
}
int d[MAXV];
int d2[MAXV];
void dij(int s){
    priority_queue<pii ,vector<pii >,greater<pii > > pque;
    rep(i,1,500)d[i]=INF;
    d[s]=0;
    pque.push(mp(0,s));
    while(!pque.empty()){
        pii t=pque.top();
        pque.pop();
        int u=t.se;
        if(d[u]<t.fi)continue;
        for(int i=head[u];~i;i=edge[i].nxt){
            Edge e=edge[i];
            if(d[e.v]>d[u]+e.c){
                d[e.v]=d[u]+e.c;
                pque.push(mp(d[e.v],e.v));
            }
        }
    }
}
int x[MAXE],y[MAXE],z[MAXE];
stack<int> st;
bool dfs1(int s,int e){
    if(s==e){
        st.push(s);
        return true;
    }
    for(int i=head[s];~i;i=edge[i].nxt){
        int v=edge[i].v;
        if(d[v]==d[s]+edge[i].c){
             if(dfs1(v,e)){
                st.push(s);
                return true;
            }
        }
    }
    return false;
}
queue<int> que;
bool dfs2(int s,int e){
    if(s==e){
        que.push(s);
        return true;
    }
    for(int i=head[s];~i;i=edge[i].nxt){
        int v=edge[i].v;
        if(d2[v]==d2[s]+edge[i].c){
             if(dfs2(v,e)){
                que.push(s);
                return true;
            }
        }
    }
    return false;
}
int main(){
    int N,S,E;
    bool ff=1;
    while(~scanf("%d%d%d",&N,&S,&E)){
        if(ff)ff=0;
        else puts("");
        int M;
        scanf("%d",&M);
        init();
        rep(i,1,M){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            add_edge(u,v,c);
            add_edge(v,u,c);
        }
        dij(E);
        rep(i,1,N)d2[i]=d[i];
        dij(S);
        bool f=1;
        int ans1=d[E];
        int ans2,ans3;
        int K;
        scanf("%d",&K);
        rep(i,1,K){
            scanf("%d%d%d",&x[i],&y[i],&z[i]);
            if(d[x[i]]+z[i]+d2[y[i]]<ans1){
                ans1=d[x[i]]+z[i]+d2[y[i]];
                ans2=x[i];
                ans3=y[i];
                f=0;
            }
            if(d[y[i]]+z[i]+d2[x[i]]<ans1){
                ans1=d[y[i]]+z[i]+d2[x[i]];
                ans2=y[i];
                ans3=x[i];
                f=0;
            }
        }
        if(f){
            while(!st.empty())st.pop();
            dfs1(S,E);
            while(!st.empty()){
                if(st.size()==1){printf("%d",st.top());break;}
                printf("%d ",st.top());
                st.pop();
            }
            puts("");
            puts("Ticket Not Used");
            printf("%d\n",ans1);
        }else{
            while(!st.empty())st.pop();
            dfs1(S,ans2);
            while(!st.empty()){
                printf("%d ",st.top());
                st.pop();
            }
            while(!que.empty())que.pop();
            dfs2(E,ans3);
            while(!que.empty()){
                if(que.size()==1){printf("%d",que.front());break;}
                printf("%d ",que.front());
                que.pop();
            }
            puts("");
            printf("%d\n",ans2);
            printf("%d\n",ans1);
        }
    }
    return 0;
}
