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
char mmp[10][10];
int mmmp[10][10];
int tmp[10][10];
vector<pii> pos;
int fun(int x){
    int res=0;
    while(x){
        res++;
        x-=x&-x;
    }
    return res;
}
void gao(int w){
    int x=pos[w].fi;
    int y=pos[w].se;
    rep(i,-1,1){
        if(i==0)continue;
        tmp[x][y+i]^=1;
        tmp[x+i][y]^=1;
    }
    tmp[x][y]^=1;
}
void print(){
    rep(i,1,4){
        rep(j,1,4){
            cout<<tmp[i][j];
        }
        cout<<endl;
    }
}
bool check(int x){
    rep(i,1,4){
        rep(j,1,4){
            tmp[i][j]=mmmp[i][j];
        }
    }
    rep(i,0,15){
        if((x>>i)&1){
            gao(i);
        }
    }
    //print();
    rep(i,1,4){
        rep(j,1,4){
            if(tmp[i][j]!=tmp[1][1])return false;
        }
    }
    return true;
}
int main(){
    rep(i,1,4)scanf("%s",mmp[i]+1);
    rep(i,1,4){
        rep(j,1,4){
            if(mmp[i][j]=='b'){
                mmmp[i][j]=1;
            }else{
                mmmp[i][j]=0;
            }
            pos.pb(mp(i,j));
        }
    }
    int ans=100;
    rep(i,0,(1<<16)-1){
        int w=fun(i);
        if(ans<=w)continue;
        if(check(i)){
            ans=min(ans,w);
        }
    }
    if(ans==100){
        puts("Impossible");
    }else{
        printf("%d",ans);
    }
    return 0;
}
