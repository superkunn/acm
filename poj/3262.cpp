#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN=1e5+50;
struct node{
    long long t,d;
}no[MAXN];
bool cmp(const node &x,const node &y){
    return x.t*y.d<y.t*x.d;
}
int main(){
    int n;
    scanf("%d",&n);
    long long sum=0;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&no[i].t,&no[i].d);
        no[i].t*=2;
        sum+=no[i].d;
    }
    sort(no+1,no+1+n,cmp);
    long long ans=0;
    for(int i=1;i<n;i++){
        sum-=no[i].d;
        ans+=no[i].t*sum;
    }
    printf("%lld",ans);
    return 0;
}
