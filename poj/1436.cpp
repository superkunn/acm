#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lson rt<<1
#define rson rt<<1|1
const int MAXN=8000+10;
struct node{
    int y1,y2,x;
    node(){}
    node(int y1,int y2,int x):
        y1(y1),y2(y2),x(x){}
}no[MAXN];
bool cmp(node a,node b){
    return a.x<b.x;
}
bool vis[MAXN][MAXN];
int tree[MAXN<<3];
void push_down(int rt){
    if(tree[rt]){
        tree[lson]=tree[rson]=tree[rt];
        tree[rt]=0;
    }
}
void build(int l,int r,int rt){
    tree[rt]=0;
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
}
void query(int L,int R,int v,int l,int r,int rt){
    if(tree[rt]){
        vis[v][tree[rt]]=true;
        vis[tree[rt]][v]=true;
        return;
    }
    if(l==r)return;
    int mid=(l+r)>>1;
    push_down(rt);
    if(mid>=L)query(L,R,v,l,mid,lson);
    if(mid+1<=R)query(L,R,v,mid+1,r,rson);
}
void update(int L,int R,int v,int l,int r,int rt){
    if(L<=l&&r<=R){
        tree[rt]=v;
        return;
    }
    int mid=(l+r)>>1;
    push_down(rt);
    if(mid>=L)update(L,R,v,l,mid,lson);
    if(mid+1<=R)update(L,R,v,mid+1,r,rson);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof(vis));
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            int y1,y2,x;
            scanf("%d%d%d",&y1,&y2,&x);
            no[i]=node(y1<<1,y2<<1,x);
        }
        sort(no+1,no+1+n,cmp);
        build(0,16000,1);
        rep(i,1,n){
            //printf("%d %d\n",no[i].y1,no[i].y2);
            query(no[i].y1,no[i].y2,i,0,16000,1);
            update(no[i].y1,no[i].y2,i,0,16000,1);
        }
        int ans=0;
        rep(i,1,n){
            rep(j,i+1,n){
                //if(vis[i][j])printf("1");
                //else printf("0");
                if(vis[i][j]){
                    rep(k,j+1,n){
                        if(vis[i][k]&&vis[j][k]){
                            ans++;
                        }
                    }
                }
            }
            //puts("");
        }
        printf("%d\n",ans);
    }
    return 0;
}
