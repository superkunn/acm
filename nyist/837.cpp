#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=100000+5;
int a[MAXN<<1];
pair<int,int> P[MAXN];
int main(){
    int now=0;
    for(int i=1;i<=100001;i++){
        while(a[now])now++;
        a[now]=1;
        P[i]=make_pair(now,now+i-1);
        if(now+i-1<MAXN*2)a[now+i-1]=1;
    }
    int n;
    while(~scanf("%d",&n)){
        rep(i,1,n+1)printf("(%d,%d)",P[i].first,P[i].second);
        puts("");
    }
    return 0;
}
