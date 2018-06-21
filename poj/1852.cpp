#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a,b;
        scanf("%d%d",&a,&b);
        int mn=0,mx=-1;
        while(b--){
            int w;
            scanf("%d",&w);
            int now=min(w,a-w);
            mn=max(mn,now);
            now=max(w,a-w);
            mx=max(mx,now);
        }
        printf("%d %d\n",mn,mx);
    }
    return 0;
}
