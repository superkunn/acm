
#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <cstdio>
#include    <vector>
#include     <stack>
#include     <queue>
#include     <cmath>
#include       <set>
#include       <map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAXN=1e5+5;
int n,q,cnt,x,y,root[MAXN],fst[MAXN],lst[MAXN],a[MAXN];
struct node{int l,r,sum;}T[MAXN*40];
void update(int l,int r,int &x,int y,int pos){
    x=++cnt;
    T[x]=T[y];
    T[x].sum++;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(pos<=mid)update(l,mid,T[x].l,T[y].l,pos);
    else update(mid+1,r,T[x].r,T[y].r,pos);
}
int query(int l,int r,int x,int y,int ff){
    if(x<=l&&r<=y)return T[ff].sum;
    int mid=(l+r)>>1;
    int ans=0;
    if(x<=mid)ans+=query(l,mid,x,y,T[ff].l);
    if(y>mid)ans+=query(mid+1,r,x,y,T[ff].r);
    return ans;
}
int work(){
    while(scanf("%d%d",&n,&q)!=EOF){
        memset(fst,-1,sizeof(fst));
        int ans=0;
        cnt=0;
        rep(i,1,n){
            scanf("%d",&a[i]);
            if(fst[a[i]]==-1)fst[a[i]]=i,ans++;
            lst[a[i]]=i;
        }
        rep(i,1,n){
            if(lst[a[i]]==i){
                update(1,n,root[i],root[i-1],fst[a[i]]);
            }else{
                root[i]=root[i-1];
            }
        }
        while(q--){
            scanf("%d%d",&x,&y);
            if(x+1>=y){
                printf("%d\n",ans);
                continue;
            }
            printf("%d\n",ans-query(1,n,x+1,y-1,root[y-1]));
        }
    }
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
