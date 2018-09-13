#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int n,m;
    scanf("%d%d",&n,&m);
    if(m<1||m>12){
        puts("Impossible");
        return 0;
    }
    if(n<1||n>a[m]){
        puts("Impossible");
        return 0;
    }
    m--;
    int cnt=n;
    for(int i=0;i<=m;i++){
        cnt+=a[i];
    }
    cnt--;
    cnt%=7;
    printf("%d",cnt+1);
    return 0;
}
