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
const int MAXN=2e4+10;
int a[MAXN],sa[MAXN],rk[MAXN],fir[MAXN],sec[MAXN],c[MAXN],h[MAXN];
char str[MAXN];
int len;
bool cmp(int i,int j,int k){
    return sec[i]==sec[j]&&sec[i+k]==sec[j+k];
}
void sufarr(int n){
    int i,p,l,m=105;
    rep(i,0,m-1)c[i]=0;
    rep(i,0,n-1)c[rk[i]=a[i]]++;
    rep(i,1,m-1)c[i]+=c[i-1];
    per(i,n-1,0)sa[--c[a[i]]]=i;
    for(l=p=1;p<n;l*=2,m=p){
        for(p=0,i=n-l;i<n;i++)sec[p++]=i;
        rep(i,0,n-1)if(sa[i]>=l)sec[p++]=sa[i]-l;
		rep(i,0,n-1)fir[i]=rk[sec[i]];
		rep(i,0,m-1)c[i]=0;
		rep(i,0,n-1)c[fir[i]]++;
		rep(i,1,m-1)c[i]+=c[i - 1];
		per(i,n-1,0)sa[--c[fir[i]]] = sec[i];
		memcpy(sec,rk,sizeof(rk));
		rk[sa[0]]=0;
		for(i=p=1;i<n;i++)rk[sa[i]]=cmp(sa[i],sa[i-1],l)?p-1:p++;
	}
}
void calh(){
	int i,j,k=0;
	rep(i,1,len)rk[sa[i]]=i;
	for(i=0;i<len;h[rk[i++]]=k)
        for (k?k--:0,j=sa[rk[i]-1];a[i+k]==a[j+k];k++);
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    rep(i,0,n-1)scanf("%d",&a[i]);
    if(k==1){
        printf("%d\n",n);
        return 0;
    }
    len=n;
    a[len]=0;
    sufarr(len+1);
    calh();
    multiset<int> st;
    int l=2,r=1;
    for(int i=0;i<k-1;i++){
        st.insert(h[++r]);
    }
    int ans=*st.begin();
    while(r<n){
        st.erase(st.find(h[l++]));
        st.insert(h[++r]);
        ans=max(ans,*st.begin());
    }
    printf("%d",ans);
	return 0;
}
