#include<cstdio>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=5e4+10;
const int INF=0x3f3f3f3f;
int a[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            a[i]=INF;
        }
        rep(i,1,n){
            int x;
            scanf("%d",&x);
            a[lower_bound(a+1,a+1+n,x)-a]=x;
        }
        int ans=0;
        rep(i,1,n){
            if(a[i]!=INF){
                ans=i;
            }else{
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
