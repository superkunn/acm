#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t1,t2;
    scanf("%d%d%d",&n,&t1,&t2);
    int now=0,a=t1,b=t2;
    while(now<n){
        if(a==b){
            now+=2;
            if(now<n){
                a+=t1;
                b+=t2;
            }
        }else if(a<b){
            now++;
            if(now>=n)now++;
            else a+=t1;
        }else{
            now++;
            if(now>=n)now++;
            else b+=t2;
        }
    }
    printf("%d %d",now,max(a,b));
    return 0;
}
