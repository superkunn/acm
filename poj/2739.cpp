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
const int MAXN=1e4+10;
int v[MAXN],prime[MAXN];
int cnt=0;
void primes( int n){
    for(int i=2;i<=n;i++){
        if(v[i]==0){
            v[i]=i;
            prime[++cnt]=i;
        }
        for(int j=1;j<=cnt;j++){
            if(prime[j]>v[i]||prime[j]>n/i)break;
            v[i*prime[j]]=prime[j];
        }
    }
}
int a[MAXN];
int main(){
    primes(10000);
    for(int i=1;i<=cnt;i++){
        int now=0;
        for(int j=i;j<=cnt;j++){
            now+=prime[j];
            if(now>10000)break;
            a[now]++;
        }
    }
    int x;
    while(scanf("%d",&x),x){
        printf("%d\n",a[x]);
    }
    return 0;
}
