#include<bits/stdc++.h>
using namespace std;
bool not_prime[100005];
bool is_prime(int x){
    if(x<2)return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0)return false;
    }
    return true;
}
int main(){
    not_prime[0]=not_prime[1]=1;
    for(int i=2;i*i<=100000;i++){
        if(!not_prime[i]){
            for(int j=2*i;j<=100000;j+=i){
                not_prime[j]=true;
            }
        }
    }
    int n;
    scanf("%d",&n);
    while(n--){
        int x;
        scanf("%d",&x);
        bool f=0;
        for(int i=1;i*i<=x;i++){
            if(x%i!=0)continue;
            if(!not_prime[i]&&is_prime(x/i)){
                f=1;
                break;
            }
        }
        if(f)puts("Yes");
        else puts("No");
    }
    return 0;
}
