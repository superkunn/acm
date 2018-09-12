#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int ans=n/3*2;
    if(n%3!=0)ans+=n%3-1;
    printf("%d",ans);
    return 0;
}
