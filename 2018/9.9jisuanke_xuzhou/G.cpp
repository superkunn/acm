#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
typedef vector<int> vi;
ll fun(vi v){
    int sz=v.size();
    set<int> st;
    ll ans=0;
    per(i,sz-1,0){
        int now=v[i];
        set<int>::iterator ite=st.lower_bound(now);
        if(ite==st.begin()){
            ans+=now;
        }else{
            ite--;
            ans+=now-*ite;
        }
        st.insert(now);
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    vi a,b;
    rep(i,1,n){
        int x,y;
        scanf("%d%d",&x,&y);
        a.pb(x);
        b.pb(y);
    }
    printf("%lld",fun(a)+fun(b));
    return 0;
}
