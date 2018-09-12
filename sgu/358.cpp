#include<bits/stdc++.h>
using namespace std;
int fun(int a,int b,int c){
    if(a<=b&&b<=c){
        return b;
    }else if(c<=b&&b<=a){
        return b;
    }else if(b<=a&&a<=c){
        return a;
    }else if(c<=a&&a<=b){
        return a;
    }else{
        return c;
    }
}
int main(){
    int a[3];
    for(int i=0;i<3;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a[i]=fun(x,y,z);
    }
    printf("%d",fun(a[0],a[1],a[2]));
    return 0;
}
