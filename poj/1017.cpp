#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long a[7];
bool check(){
    for(int i=1;i<=6;i++){
        if(a[i]!=0)return false;
    }
    return true;
}
int main(){
    while(~scanf("%lld",&a[1])){
        for(int i=2;i<=6;i++){
            scanf("%lld",&a[i]);
        }
        if(check())break;
        long long ans=0;
        ans+=a[6];
        ans+=(a[3]+3)/4;
        a[3]=a[3]%4;
        ans+=a[5];
        a[1]-=a[5]*11;
        if(a[1]<0)a[1]=0;
        ans+=a[4];
        int w=a[4]*5;
        if(a[2]>=w){
            a[2]-=w;
        }else{
            w-=a[2];
            a[2]=0;
            w*=4;
            a[1]-=w;
            if(a[1]<0)a[1]=0;
        }
        if(a[3]==1){
            w=5;
            if(a[2]>=w){
                a[2]-=w;
                w=0;
            }else{
                w-=a[2];
                a[2]=0;
            }
            w=7+w*4;
            a[1]-=w;
            if(a[1]<0)a[1]=0;
        }else if(a[3]==2){
            w=3;
            if(a[2]>=w){
                a[2]-=w;
                w=0;
            }else{
                w-=a[2];
                a[2]=0;
            }
            w=6+w*4;
            a[1]-=w;
            if(a[1]<0)a[1]=0;
        }else if(a[3]==3){
            w=1;
            if(a[2]>=w){
                a[2]-=w;
                w=0;
            }else{
                w-=a[2];
                a[2]=0;
            }
            w=5+w*4;
            a[1]-=w;
            if(a[1]<0)a[1]=0;
        }
        ans+=(a[2]+8)/9;
        a[2]=a[2]%9;
        w=36-a[2]*4;
        if(w!=36){
            a[1]-=w;
            if(a[1]<0)a[1]=0;    
        }
        ans+=(a[1]+35)/36;
        printf("%lld\n",ans);
    }
    return 0;
}
