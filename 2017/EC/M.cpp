#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    scanf("%d",&T);
    int kase=0;
    while(T--){
        int a[5];
        for(int i=0;i<5;i++)scanf("%d",&a[i]);
        int n;
        scanf("%d",&n);
        ll ans=0;
        while(n--){
            int x;
            scanf("%d",&x);
            if(x<=48){
                ans+=a[0];
            }else if(x<=56){
                ans+=a[1];
            }else if(x<=60){
                ans+=a[2];
            }else if(x<=62){
                ans+=a[3];
            }else{
                ans+=a[4];
            }
        }
        printf("Case #%d: %I64d\n",++kase,ans*10000);
    }
    return 0;
}
