#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int a[10]={6,2,5,5,4,5,6,3,7,6};
int fun(int x){
    if(x==0){
        return 6;
    }
    int res=0;
    while(x){
        res+=a[x%10];
        x/=10;
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    n-=4;
    int ans=0;
    rep(i,0,1000){
        rep(j,0,1000){
            if(fun(i)+fun(j)+fun(i+j)==n){
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
