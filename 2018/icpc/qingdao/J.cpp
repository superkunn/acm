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
const int MAXN=1e5+10;
int a[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        int cnt=0;
        rep(i,1,n){scanf("%d",&a[i]);if(a[i]==0)cnt++;}
        if(k==n){
            puts("Richman");
            continue;
        }
        if(cnt>k){
            puts("Impossible");
            continue;
        }
        k-=cnt;
        ll w=0;
        rep(i,1,n){
            if(k==0){
                int mi=1e9+10;
                rep(j,i,n){
                    if(a[j]!=0)mi=min(mi,a[j]);
                }
                w+=mi-1;
                break;
            }
            if(a[i]!=0){
                w+=a[i];
                k--;
            }
        }
        printf("%lld\n",w);
    }
    return 0;
}
