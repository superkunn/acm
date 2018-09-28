#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
map<ll,bool> mmp;
int main(){
    ll v[3];
    v[0]=v[1]=1;
    mmp[floor(1.5)]=true;
    int now=2;
    double INF=pow(2,63);
    while((double)v[(now+1)%3]+(double)v[(now+2)%3]<INF){
        v[now]=v[(now+1)%3]+v[(now+2)%3];
        mmp[v[now]]=true;
        now++;
        if(now==3)now=0;
    }
    ll n;
    while(~scanf("%lld",&n)){
        if(mmp.count(n)==1)puts("No");
        else puts("Yes");
    }
    return 0;
}
