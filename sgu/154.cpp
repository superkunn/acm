#include<bits/stdc++.h>
using namespace std;
int n;
bool check(int x){
    int cnt=0;
    while(x){
        cnt+=x/5;
        x/=5;
    }
    if(cnt>=n)return true;
    else return false;
}
int main(){
    scanf("%d",&n);
    int ans=-1;
    int l=1,r=1000000000;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    int cnt=0;
    int now=ans;
    while(now){
        cnt+=now/5;
        now/=5;
    }
    if(cnt==n){
        printf("%d",ans);
    }else{
        puts("No solution");
    }
    return 0;
}
