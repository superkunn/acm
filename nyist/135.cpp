#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int m;
        scanf("%d",&m);
        int ans=0;
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            a%=(b+1);
            ans^=a;
        }
        if(ans)puts("Win");
        else puts("Lose");
    }
    return 0;
}
