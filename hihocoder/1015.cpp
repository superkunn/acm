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
const int MAXM=1e6+10;
char a[MAXN];
char b[MAXM];
int nxt[MAXN];
int f[MAXM];
int n,m;
void initkmp(){
    n=strlen(a);
    nxt[0]=-1;
    for(int i=1,j=-1;i<n;i++){
        while(j>-1&&a[i]!=a[j+1])j=nxt[j];
        if(a[i]==a[j+1])j++;
        nxt[i]=j;
    }
}
int kmp(){
    initkmp();
    int res=0;
    m=strlen(b);
    for(int i=0,j=-1;i<m;i++){
        while(j>-1&&(j==(n-1)||b[i]!=a[j+1]))j=nxt[j];
        if(b[i]==a[j+1])j++;
        f[i]=j;
        if(f[i]==n-1)res++;
    }
    return res;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",&a,&b);
        printf("%d\n",kmp());
    }
    return 0;
}
