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
char mmp[9][9];
int val;
int bb[5][5];
int op[5][5];
int wei(int x){
    int res=0;
    while(x){
        res++;
        x-=x&-x;
    }
    return res;
}
void fun(int x,int y){
    rep(i,1,4){
        if(i==x)continue;
        op[x][y]+=bb[i][y];
    }
    rep(i,1,4){
        if(i==y)continue;
        op[x][y]+=bb[x][i];
    }
    op[x][y]+=bb[x][y];
}
int bbb[16];
pii P[16];
bool work(int x){
    int y=val;
    rep(i,0,15){
        if(x&(1<<i)){
            y^=bbb[i];
        }
    }
    if(y==0)return true;
    else return false;
}
int main(){
    rep(i,1,4)scanf("%s",mmp[i]+1);
    int now=0;
    val=0;
    rep(i,1,4){
        rep(j,1,4){
            if(now==0){
                now=1;
            }else{
                now<<=1;
            }
            bb[i][j]=now;
            if(mmp[i][j]=='+')val+=now;
        }
    }
    rep(i,1,4){
        rep(j,1,4){
            fun(i,j);
        }
    }
    int ts=0;
    rep(i,1,4){
        rep(j,1,4){
            P[ts]=mp(i,j);
            bbb[ts++]=op[i][j];
//            rep(k,0,15){
//                if(op[i][j]&(1<<k))cout<<1;
//                else cout<<0;
//            }
//            cout<<endl;
        }
    }
    int n=(1<<16)-1;
    int ans=n;
    rep(i,0,n){
        if(wei(ans)<=wei(i)){
            continue;
        }
        if(work(i)){
            //cout<<i<<endl;
            ans=i;
        }
    }
    printf("%d\n",wei(ans));
    rep(i,0,15){
        if(ans&(1<<i))printf("%d %d\n",P[i].first,P[i].second);
    }
    return 0;
}
