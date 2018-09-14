#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll b[105];
const int M=(int)(log(1e18)/log(2))+1;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        ll a;
        scanf("%I64d",&a);
        for(int j=M;j>=0;j--){
            if((a>>j)&1){
                if(b[j]){
                    a^=b[j];
                }else{
                    b[j]=a;
                    for(int k=j-1;k>=0;k--){
                        if(b[k]&&(b[j]>>k&1)){
                            b[j]^=b[k];
                        }
                    }
                    for(int k=j+1;k<=M;k++){
                        if((b[k]>>j)&1){
                            b[k]^=b[j];
                        }
                    }
                    break;
                }
            }
        }
    }
    ll ans=0;
    for(int i=0;i<=M;i++){
        ans^=b[i];
    }
    printf("%I64d",ans);
    return 0;
}
