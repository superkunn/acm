#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000000;
int cnt[MAXN+5];
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                cnt[i]++;
                if(x/i!=i)cnt[x/i]++;
            }
        }
    }
    for(int i=MAXN;i>=1;i--){
        if(cnt[i]>=2){
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}
