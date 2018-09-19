#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%d%d",&a,&b);
        int w=a-b+1;
        int ans;
        if(b==0)ans=0;
        else{
            ans=b/w;
            if(b%w!=0)ans++;
        }
        printf("%d %d\n",b,ans);
    }
    return 0;
}
