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
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
int phi1(int n){
    int res=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            res=res/i*(i-1);
            for(;n%i==0;n/=i);
        }
    }
    if(n!=1) res=res/n*(n-1);
    return res;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans=1;
        for(int i=2;1LL*i*i<=x;i++){
            if(x%i==0){
                if(x/i==i){
                    if(i>=y)ans+=phi1(i);
                }else{
                    if(i>=y)ans+=phi1(x/i);
                    if(x/i>=y)ans+=phi1(i);
                }
            }
        }
        printf("%lld\n",ans);
	}
	return 0;
}


