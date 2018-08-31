#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
typedef long long anytype;
const int MAXN=1e6+10;
ll a[MAXN];
anytype QuickSelect(anytype arr[],int l,int r,int k){
    int i=l,j=r,mid=arr[(i+j)>>1];
    while(i<=j){
        while(arr[i]<mid)i++;
        while(arr[j]>mid)j--;
        if(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    }
    if(l<j&&k<=j)return QuickSelect(arr,l,j,k);
    if(i<r&&k>=i)return QuickSelect(arr,i,r,k);
    return arr[k];
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        ll sum=0;
        rep(i,1,n){
            int x;
            scanf("%d",&x);
            sum+=x;
            if(i!=n){
                a[i+1]=a[i]+x;
            }
        }
        ll w=sum/n;
        rep(i,2,n){
            a[i]-=(i-1)*w;
        }
        ll a1=QuickSelect(a,1,n,(1+n)/2);
        ll ans=0;
        rep(i,1,n){
            ans+=abs(a1-a[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
