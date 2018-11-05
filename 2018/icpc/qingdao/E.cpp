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
template <class T>
inline bool scan_d(T &ret){
    char c;
    int sgn;
    if (c = getchar(), c == EOF) return 0; //EOF
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
inline void out(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if (x > 9) out(x / 10);
    putchar(x % 10 + '0');
}
const int MAXN=1e5+10;
ll a[MAXN];
ll b[MAXN];
int you[MAXN];
int zuo[MAXN];
int n;
ll k;
bool check(ll mid){
    if(mid==0)return true;
    rep(i,1,n+1){
        b[i]=0;
        you[i]=0;
        zuo[i]=0;
    }
    ll kk=k;
    ll aa=0;
    ll bb=0;
    ll o=0;
    if(kk==0)return false;
    kk--;
    b[1]=a[1];
    rep(i,1,n-1){
        if(b[i]>=mid){
            if(i==n-1)o=1;
            you[i]++;
            if(kk==0)return false;
            b[i+1]+=a[i+1];
            kk--;
        }else{
            ll w=mid-b[i];
            ll cnt=(w+a[i]-1)/a[i];
            b[i]+=cnt*a[i];
            if(kk<2*cnt)return false;
            kk-=2*cnt;
            b[i+1]+=cnt*a[i+1];
            if(b[i+1]<mid){
                if(kk==0)return false;
                kk--;
                b[i+1]+=a[i+1];
                you[i]++;
                if(i==n-1)o=1;
            }else{
                zuo[i]++;
            }
        }
    }
    if(b[n]<mid){
        if(o==1){
            ll w=mid-b[n];
            ll cnt=(w+a[n]-1)/a[n];
            if(kk<2*cnt)return false;
            kk-=2*cnt;
        }else{
            ll w=mid-b[n];
            ll cnt=(w+a[n]-1)/a[n];
            if(kk<2*cnt-1)return false;
            kk-=2*cnt-1;
            you[n-1]++;
            zuo[n-1]--;
        }
    }
    int mi=n;
    rep(i,1,n){
        you[i]+=you[i-1];
        zuo[i]+=zuo[i-1];
    }
    rep(i,1,n){
        mi=min(mi,zuo[i-1]+you[n]-you[i-1]);
    }
    if(kk<mi)return false;
    return true;
}
int main(){
    int T;
    scan_d(T);
    while(T--){
        scan_d(n);
        scan_d(k);
        rep(i,1,n){
            scan_d(a[i]);
        }
        ll l=0,r=1e17+10;
        ll ans;
        while(l<=r){
            ll mid=(l+r)>>1;
            //cout<<mid<<endl;
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
