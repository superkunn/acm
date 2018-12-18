#include<cstdio>
#include<cstring>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define lson rt<<1
#define rson rt<<1|1
typedef long long ll;
const int MAXN=2e5+10;
int a[MAXN],b[MAXN],ans[MAXN];
int tree[MAXN<<2];
void push_up(int rt){
    tree[rt]=tree[lson]+tree[rson];
}
void build(int l,int r,int rt){
    if(l==r){
        tree[rt]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    push_up(rt);
}
void update(int pos,int l,int r,int rt){
    if(l==r){
        tree[rt]--;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)update(pos,l,mid,lson);
    else update(pos,mid+1,r,rson);
    push_up(rt);
}
int findpos(int v,int l,int r,int rt){
    if(l==r){
        return r;
    }
    int mid=(l+r)>>1;
    if(tree[lson]>=v)return findpos(v,l,mid,lson);
    else return findpos(v-tree[lson],mid+1,r,rson);
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        build(1,n,1);
        rep(i,1,n){
            scanf("%d%d",&a[i],&b[i]);
            a[i]++;
        }
        per(i,n,1){
            int pos=findpos(a[i],1,n,1);
            ans[pos]=b[i];
            update(pos,1,n,1);
        }
        rep(i,1,n){
            printf("%d ",ans[i]);
        }
        puts("");
    }
    return 0;
}
