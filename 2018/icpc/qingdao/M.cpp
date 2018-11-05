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
int ch[10]={1,0,0,0,1,0,1,0,2,1};
int fun(int x){
    if(x==0)return 1;
    int res=0;
    while(x){
        res+=ch[x%10];
        x/=10;
    }
    return res;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int x,k;
        scanf("%d%d",&x,&k);
        while(k){
            if(x==0){
                if(k&1){
                    x=1;
                }else{
                    x=0;
                }
                break;
            }
            k--;
            x=fun(x);
        }
        printf("%d\n",x);
    }
    return 0;
}
