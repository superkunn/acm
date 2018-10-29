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
char a[MAXN];
int nxt[MAXN];
int n;
void init(){
    nxt[1]=0;
    for(int i=2,j=0;i<=n;i++){
        while(j!=0&&a[i]!=a[j+1])j=nxt[j];
        if(a[i]==a[j+1])j++;
        nxt[i]=j;
        if(i%(i-nxt[i])==0&&i/(i-nxt[i])>1)printf("%d %d\n",i,i/(i-nxt[i]));
    }
    puts("");
}
int main(){
    int kase=0;
    while(scanf("%d",&n),n){
        printf("Test case #%d\n",++kase);
        scanf("%s",a+1);
        init();
    }
    return 0;
}
