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
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        double ans=exp(a)*b;
        if(c==1){
            printf("%.1f\n",ans);
        }else if(c==2){
            printf("%.2f\n",ans);
        }else if(c==3){
            printf("%.3f\n",ans);
        }else if(c==4){
            printf("%.4f\n",ans);
        }else if(c==5){
            printf("%.5f\n",ans);
        }
    }
    return 0;
}

