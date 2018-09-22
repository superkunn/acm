#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+10;
char s[MAXN];
int even[MAXN];
int odd[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        int n=strlen(s);
        even[0]=even[1]=0;
        for(int i=0;i<n;i++){
            even[i+1]++;
            if(s[i]=='0'){
                even[i+2]=even[i+1]+odd[i+1];
                odd[i+2]=0;
            }else{
                odd[i+2]=even[i+1]+odd[i+1];
                even[i+2]=0;
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ans+=1LL*even[i+1]*2*(n-i);
                ans+=1LL*odd[i+1]*(n-i);
            }else{
                ans+=1LL*even[i+1]*(n-i);
                ans+=1LL*odd[i+1]*2*(n-i);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
