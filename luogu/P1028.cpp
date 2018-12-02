#include <algorithm>
#include  <iostream>
#include   <cstring>
#include   <iomanip>
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
const int MAXN=1e3+10;
int dp[MAXN];
int sum[MAXN];
int main(){
    int n;
    cin>>n;
    dp[1]=1;
    sum[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=sum[i/2]+1;
        sum[i]=sum[i-1]+dp[i];
    }
    cout<<dp[n]<<endl;
    return 0;
}

