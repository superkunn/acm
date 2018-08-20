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
ll a[25];
ll b[25];
int work(){
    a[1]=1;
    rep(i,2,20)a[i]=a[i-1]*i;
    b[1]=0;
    b[2]=1;
    rep(i,3,20)b[i]=(b[i-1]+b[i-2])*(i-1);
    int n;
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        double ans=100.0*b[x]/(1.0*a[x]);
        printf("%.2lf%%\n",ans);
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
