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
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=2e5+10;
int n;
int a[MAXN],b[MAXN],ans[MAXN];
struct BIT{
    int n,c[MAXN];
    void init(int _n){
        n=_n;
        rep(i,0,n)c[i]=0;
    }
    void update(int i,int v){
        for(;i<=n;i+=i&-i)c[i]+=v;
    }
    int query(int i){
        int s=0;
        for(;i;i-=i&-i)s+=c[i];
        return s;
    }
    int findk(int k){
        int l=1,r=n,ans;
        while(l<=r){
            int mid=(l+r)>>1;
            if(query(mid)>=k){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
}bit;
int work(){
    while(~scanf("%d",&n)){
        rep(i,1,n){
            scanf("%d%d",&a[i],&b[i]);
            a[i]++;
        }
        bit.init(n);
        rep(i,1,n){
            bit.update(i,1);
        }
        per(i,n,1){
            int pos=bit.findk(a[i]);
            bit.update(pos,-1);
            ans[pos]=b[i];
        }
        rep(i,1,n)printf("%d%c",ans[i]," \n"[i==n]);
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
