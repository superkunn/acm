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
const int MAXN=2e6+100;
int z[MAXN];
char a[MAXN];
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
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",a);
        int n=strlen(a);
        a[n]='$';
        scanf("%s",a+n+1);
        int m=strlen(a);
        z_algorithm(a,m);
        int ans=0;
        for(int i=n+1;i<m;i++){
            if(z[i]==n)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
