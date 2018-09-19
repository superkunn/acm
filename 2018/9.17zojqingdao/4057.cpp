#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v(32);
int fun(int x){
    int res=0;
    while(x){
        res++;
        x>>=1;
    }
    return res;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<32;i++){
            v[i]=0;
        }
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            int w=fun(x);
            v[w]++;
        }
        int ans=0;
        for(int i=0;i<32;i++){
            ans=max(ans,v[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
