#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
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
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const ll B1=1e7+7;
const ll B2=1e9+7;
char pa[10004];
char tx[1000006];
int work(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",pa,tx);
        int pl=strlen(pa);
        int tl=strlen(tx);
        ll w=1;
        rep(i,1,pl)w=(w*B1)%B2;
        ll ph=0,th=0;
        rep(i,0,pl-1){
            ph=(ph*B1+pa[i])%B2;
            th=(th*B1+tx[i])%B2;
        }
        int ans=0;
        for(int i=0;i+pl<=tl;i++){
            if(ph==th)ans++;
            if(i+pl<tl)th=(th*B1+tx[i+pl]-tx[i]*w)%B2;
        }
        printf("%d\n",ans);
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
