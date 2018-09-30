#include<cstdio>
#include<algorithm>
using namespace std;
int a[15];
int d[15];
int main(){
    a[1]=1;
    d[1]=1;
    puts("1");
    for(int i=2;i<=12;i++){
        d[i]=2*d[i-1]+1;
        int ans=0x3f3f3f3f;
        for(int j=1;j<i;j++){
            ans=min(ans,2*a[j]+d[i-j]);
        }
        a[i]=ans;
        printf("%d\n",ans);
    }
    return 0;
}
