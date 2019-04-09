#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(){
    int n;
    scanf("%d",&n);
    if(n==0){
        puts("0");
        return 0;
    }else if(n<0){
        putchar('-');
        n=-n;
    }
    bool f=true;
    while(n){
        if((n%10)!=0){
            f=false;
        }
        if(!f){
            printf("%d",n%10);
        }
        n/=10;
    }
    return 0;
}
