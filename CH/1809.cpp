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
const int MAXN=4e5+10;
int n,m;
int z[MAXN];
char a[MAXN],b[MAXN];
void z_algorithm(char *a,int len){
    z[0]=len;
    for(int i=1,j=1,k;i<len;i=k){
        if(j<i)j=i;
        while(j<len && a[j]==a[j-i])++j;
        z[i]=j-i;
        k=i+1;
        while(k+z[k-i]<j)z[k]=z[k-i],++k;
    }
}
int cnt[MAXN];
int main(){
    int q;
    scanf("%d%d%d",&n,&m,&q);
    scanf("%s%s",a,b);
    int s1=strlen(a);
    int s2=strlen(b);
    b[s2]='$';
    strcpy(b+s2+1,a);
    int len=s1+1+s2;
    z_algorithm(b,len);
    rep(i,s2+1,len-1)cnt[z[i]]++;
    while(q--){
        int x;
        scanf("%d",&x);
        printf("%d\n",cnt[x]);
    }
    return 0;
}
