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
const int MAXN=1e5+5;
int a[MAXN];
int work(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,s;
        scanf("%d%d",&n,&s);
        rep(i,1,n){
            scanf("%d",&a[i]);
        }
        int sum=0;
        int l=1,r=0;
        int ans=n+1;
        for(;;){
            while(sum<s&&r<n){
                r++;
                sum+=a[r];
            }
            if(sum<s)break;
            while(sum>=s){
                sum-=a[l];
                l++;
            }
            ans=min(ans,r-l+2);
            if(r==n)break;
        }
        printf("%d\n",ans==n+1?0:ans);
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
