#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
typedef vector<int> vi;
const int MAXN=2e5+10;
vi v;
int getId(int x){
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
int cnt;
int root[MAXN];
struct node{
    int l,r,sum;
}Tree[MAXN*40];
int a[MAXN];
void update(int l,int r,int x,int &y,int pos){
    y=++cnt;
    Tree[y]=Tree[x];
    Tree[y].sum++;
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid){
        update(l,mid,Tree[x].l,Tree[y].l,pos);
    }else{
        update(mid+1,r,Tree[x].r,Tree[y].r,pos);
    }
}
int query(int l,int r,int x,int y,int z){
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    int sum=Tree[Tree[y].l].sum-Tree[Tree[x].l].sum;
    if(sum>=z){
        return query(l,mid,Tree[x].l,Tree[y].l,z);
    }else{
        return query(mid+1,r,Tree[x].r,Tree[y].r,z-sum);
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%d",&a[i]);
        v.pb(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    rep(i,1,n){
        update(1,n,root[i-1],root[i],getId(a[i]));
    }
    while(m--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        printf("%d\n",v[query(1,n,root[x-1],root[y],z)-1]);
    }
    return 0;
}
