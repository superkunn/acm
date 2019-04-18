#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
int main(){
    int n;
    scanf("%d",&n);
    int i=1;
    int ans=1;
    while(i<n){
        i<<=1;
        i|=1;
        ans++;
    }
    printf("%d",ans);
    return 0;
}
