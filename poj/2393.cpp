#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=1e9;
int main(){
    int n,s;
    scanf("%d%d",&n,&s);
    int mm=INF;
    long long ans=0;
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        mm=min(x,mm+s);
        ans+=mm*y;
    }
    printf("%lld\n",ans);
    return 0;
}
