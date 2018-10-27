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
int main(){
    int n;
    scanf("%d",&n);
    vi cnt(100005,0);
    int x;
    rep(i,1,n)scanf("%d",&x),cnt[x]++;
    int w;
    for(w=1;;w++){
        if((w+1)*(w+1)>200000)break;
    }
    ll ans=0;
    rep(i,1,100000){
        rep(j,1,w){
            //cout<<j<<endl;
            int now=j*j;
            int k=now-i;
            if(k==i){
                ans+=1LL*(cnt[k]-1)*cnt[k]/2;
            }else if(k>i&&k<=100000){
                ans+=1LL*cnt[i]*cnt[k];
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
