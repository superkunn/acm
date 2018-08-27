#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
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
const int MAXN=1e5+10;
double a[MAXN],b[MAXN];
int n,k;
bool check(double x){
    vector<double> v;
    rep(i,1,n){
        v.pb(a[i]-x*b[i]);
    }
    sort(v.rbegin(),v.rend());
    double sum=0;
    rep(i,0,k-1){
        sum+=v[i];
    }
    if(sum>=0)return true;
    else return false;
}
int work(){
    scanf("%d%d",&n,&k);
    rep(i,1,n){
        scanf("%lf%lf",&a[i],&b[i]);
    }
    double l=0.0,r=1000006.0;
    rep(i,0,50){
        double mid=(l+r)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    vector<pair<double,int> > pp;
    rep(i,1,n){
        pp.pb(mp(a[i]-l*b[i],i));
    }
    sort(pp.rbegin(),pp.rend());
    rep(i,0,k-1){
        printf("%d ",pp[i].se);
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
