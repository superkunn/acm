#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        double ans=0.0;
        rep(i,1,n-1){
            double pos=(double)i/n*(n+m);
            ans+=fabs(pos-floor(pos+0.5))/(n+m);
        }
        printf("%.4lf\n",ans*10000);
    }
    return 0;
}
