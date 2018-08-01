#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
typedef vector<int> vi;
const int MAXN=1e5+6;
vi v;
int n,cnt,m,x,y,k,root[MAXN],a[MAXN];
struct node{int l,r,sum;}T[MAXN*40];
int getid(int x){return lower_bound(all(v),x)-v.begin()+1;}
void update(int l,int r,int &x,int y,int pos){
    T[++cnt]=T[y];
    T[cnt].sum++;
    x=cnt;
    if(l==r)return;
    int mid=(l+r)/2;
    if(mid>=pos)update(l,mid,T[x].l,T[y].l,pos);
    else update(mid+1,r,T[x].r,T[y].r,pos);
}
int query(int l,int r,int x,int y,int k){
    if(l==r)return l;
    int mid=(l+r)/2;
    int sum=T[T[y].l].sum-T[T[x].l].sum;
    if(sum>=k)return query(l,mid,T[x].l,T[y].l,k);
    else return query(mid+1,r,T[x].r,T[y].r,k-sum);
}
void work(){
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%d",&a[i]);
        v.pb(a[i]);
    }
    sort(all(v));
    v.erase(unique(all(v)),v.end());
    rep(i,1,n)update(1,n,root[i],root[i-1],getid(a[i]));
    rep(i,1,m){
        scanf("%d%d%d",&x,&y,&k);
        printf("%d\n",v[query(1,n,root[x-1],root[y],k)-1]);
    }
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
