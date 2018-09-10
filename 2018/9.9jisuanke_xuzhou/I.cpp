#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        char base;
        scanf("%d %c",&n,&base);
        getchar();
        bool f=0;
        int ans=2*n;
        for(int i=1;i<=n;i++){
            char c=getchar();
            if(f)continue;
            if(abs(c-base)==0){
                ans-=2;
            }else if(abs(c-base)<10){
                ans-=1;
                f=1;
            }else {
                f=1;
            }
        }
        if(ans==0)ans=1;
        printf("%d\n",ans);
    }
    return 0;
}
