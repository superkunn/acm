#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef int anytype;
const int MAXN=1e5+10;
int a[MAXN];
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
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    anytype w=QuickSelect(a,1,n,n/2+1);
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=abs(a[i]-w);
    printf("%lld",ans);
    return 0;
}
