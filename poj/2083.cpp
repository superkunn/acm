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
char ch[800][800];
void dfs(int x,int y,int len,int mi){
    if(mi==0){
        ch[x][y]='X';
        return;
    }
    dfs(x,y,len/3,mi-1);
    dfs(x,y-len*2/3,len/3,mi-1);
    dfs(x-len*2/3,y,len/3,mi-1);
    dfs(x-len*2/3,y-len*2/3,len/3,mi-1);
    dfs(x-len/3,y-len/3,len/3,mi-1);
}
int main(){
    //3**6=729
    rep(i,1,729)rep(j,1,729)ch[i][j]=' ';
    dfs(729,729,729,6);
    int n;
    while(scanf("%d",&n),n!=-1){
        n=pow(3,n-1);
        rep(i,1,n){
            rep(j,1,n){
                putchar(ch[i][j]);
            }
            puts("");
        }
        puts("-");
    }
    return 0;
}
