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
const int MAXN=1e6+10;
int a[MAXN];
int work(){
    int n;
    scanf("%d",&n);
    set<int> st;
    rep(i,1,n){
        scanf("%d",&a[i]);
        st.insert(a[i]);
    }
    int ans=n;
    int sum=0;
    int l=1,r=0;
    int sz=st.size();
    map<int,int> mmp;
    for(;;){
        while(sum<sz&&r<n){
            r++;
            if(mmp[a[r]]++==0)sum++;
        }
        if(sum<sz)break;
        while(sum>=sz){
            if(mmp[a[l]]--==1)sum--;
            l++;
        }
        ans=min(ans,r-l+2);
    }
    printf("%d",ans);
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
