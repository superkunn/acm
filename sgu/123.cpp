#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
const int MAXN=45;
int a[MAXN];
int main(){
    int k;
    a[1]=a[2]=1;
    int ans=2;
    scanf("%d",&k);
    if(k<=2){
        printf("%d",k);
    }else{
        rep(i,3,k){
            a[i]=a[i-1]+a[i-2];
            ans+=a[i];
        }
        printf("%d",ans);
    }
    return 0;
}
