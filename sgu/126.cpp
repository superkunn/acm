#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    return a?gcd(b%a,a):b;
}
int fun(int k){
    int res=-1;
    while(k){
        res++;
        if(k!=1&&(k&1)){
            return -1;
        }
        k>>=1;
    }
    return res;
}
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int k=(a+b)/gcd(a,b);
    printf("%d",fun(k));
    return 0;
}
