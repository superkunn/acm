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
const int MAXN=1e6+10;
char s1[MAXN];
char s2[MAXN];
int cnt[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        scanf("%s%s",s1+1,s2+1);
        int c=0;
        int bb=0;
        rep(i,1,n){
            if(s1[i]==s2[i]){
                cnt[i]=0;
            }else{
                if(cnt[i-1]==0){
                    cnt[i]=++c;
                }else{
                    cnt[i]=cnt[i-1];
                }
            }
            if(cnt[i]==1)bb++;
        }
        if(c==0){
            printf("%lld\n",1LL*n*(n+1)/2);
        }else if(c==2){
            puts("6");
        }else if(c==1){
            printf("%lld\n",1LL*2*(bb-1)+1LL*(n-bb)*2);
        }else{
            puts("0");
        }
    }
    return 0;
}
