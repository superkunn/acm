#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN=1e6+5;
const int MOD=1e9;
int a[MAXN];
int main(){
    a[1]=1;
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        if(i&1){
            a[i]=a[i-1];
        }else{
            a[i]=(a[i-1]+a[i>>1])%MOD;
        }
    }
    printf("%d",a[n]);
    return 0;
}
