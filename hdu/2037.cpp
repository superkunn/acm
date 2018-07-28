#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN=105;
struct node{
    int v,id;
}no[MAXN<<1];
bool cmp(const node &x,const node &y){
    return x.v<y.v;
}
int w[MAXN<<1];
struct node2{
    int l,r;
}no2[MAXN];
bool cmp2(const node2 &x,const node2 &y){
    return x.r<y.r;
}
int dp[MAXN<<1];
int main(){
    int n;
    while(~scanf("%d",&n)){
        if(!n)break;
        for(int i=1;i<=2*n;i++){
            scanf("%d",&no[i].v);
            no[i].id=i;
        }
        sort(no+1,no+1+2*n,cmp);
        int index=1;
        w[no[1].id]=1;
        for(int i=2;i<=2*n;i++){
            if(no[i].v!=no[i-1].v){
                index++;
            }
            w[no[i].id]=index;
        }
        for(int i=2;i<=2*n;i+=2){
            no2[i/2].l=w[i-1];
            no2[i/2].r=w[i];
        }
        sort(no2+1,no2+1+n,cmp2);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            int nl=no2[i].l;
            int nr=no2[i].r;
            if(dp[nl]+1>dp[nr]){
                for(int i=nr;i<=200;i++){
                    dp[i]=dp[nl]+1;
                }
            }
        }
        printf("%d\n",dp[200]);
    }
    return 0;
}
