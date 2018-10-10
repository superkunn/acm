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
int cnt;
int num[MAXN];
int p[MAXN];
void divide(int n){
    cnt=0;
    for(int i=2;1LL*i*i<=n;i++){
        if(n%i==0){
            p[++cnt]=i,num[cnt]=0;
        }
        while(n%i==0)n/=i,num[cnt]++;
    }
    if(n>1){
        p[++cnt]=n,num[cnt]=1;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    divide(n);
    printf("%d",p[2]);
    return 0;
}
