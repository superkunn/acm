#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
int main(){
    int n,s,a,b;
    scanf("%d%d%d%d",&n,&s,&a,&b);
    vector<int> ans;
    rep(i,1,n){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x<=b||(a-b<=x&&x<=a+b)){
            ans.pb(y);
        }
    }
    sort(ans.begin(),ans.end());
    int res=0;
    for(auto x:ans){
        if(s>=x){
            res++;
            s-=x;
        }
    }
    printf("%d",res);
    return 0;
}
