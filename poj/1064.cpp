#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
const int MAXN=1e4+4;
double a[MAXN];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lf",&a[i]);
    }
    double l=0.0,r=1e9;
    for(int i=0;i<100;i++){
        double mid=(r+l)/2.0;
        int now=0;
        for(int i=1;i<=n;i++){
            now+=(int)(a[i]/mid);
        }
        if(now>=k){
            l=mid;
        }else{
            r=mid;
        }
    }
    printf("%d.%02d",(int)floor(r*100)/100,(int)floor(r*100)%100);
    return 0;
}
