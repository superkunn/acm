#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <bitset>
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
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=2e5+10;
int pre[MAXN],nxt[MAXN];
ll a[MAXN];
set<pair<ll,int> > st;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    rep(i,1,n)scanf("%lld",&a[i]);
    rep(i,1,n-1){
        a[i]=a[i+1]-a[i];
        if(i!=n-1)nxt[i]=i+1;
        if(i!=n-1)pre[i+1]=i;
        st.insert(mp(a[i],i));
    }
    ll ans=0;
    for(int i=1;i<=k;i++){
        pair<ll,int> now=*st.begin();
        st.erase(now);
        ans+=now.first;
        if(pre[now.second]==0&&nxt[now.second]==0)break;
        if(pre[now.second]==0){
            pair<ll,int> cur=mp(a[nxt[now.second]],nxt[now.second]);
            pre[nxt[cur.second]]=0;
            st.erase(st.find(cur));
        }else if(nxt[now.second]==0){
            pair<ll,int> cur=mp(a[pre[now.second]],pre[now.second]);
            nxt[pre[cur.second]]=0;
            st.erase(st.find(cur));
        }else{
            pair<ll,int> cur1=mp(a[nxt[now.second]],nxt[now.second]);
            st.erase(st.find(cur1));
            pair<ll,int> cur2=mp(a[pre[now.second]],pre[now.second]);
            st.erase(st.find(cur2));
            nxt[now.second]=nxt[cur1.second];
            if(nxt[cur1.second]!=0)pre[nxt[cur1.second]]=now.second;
            pre[now.second]=pre[cur2.second];
            if(pre[cur2.second]!=0)nxt[pre[cur2.second]]=now.second;
            a[now.second]=-now.first+cur1.first+cur2.first;
            st.insert(mp(-now.first+cur1.first+cur2.first,now.second));
        }
    }
    printf("%lld",ans);
    return 0;
}
