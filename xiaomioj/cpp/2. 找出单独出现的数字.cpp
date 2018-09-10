#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int ans=0;
    while(~scanf("%d",&n)){
        ans^=n;
    }
    printf("%d",ans);
    return 0;
}
