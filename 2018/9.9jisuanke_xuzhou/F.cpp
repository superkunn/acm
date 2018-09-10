#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define clr(a,x) memset(a,x,sizeof(a))
#define mp make_pair
typedef pair<int,int> pii;
map<pii,int> mmp[2];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        int ans=0;
        scanf("%d",&n);
        int now=0;
        while(n--){
            mmp[now].clear();
            int m;
            scanf("%d",&m);
            rep(i,1,m){
                int x,y;
                scanf("%d%d",&x,&y);
                pii p=mp(x,y);
                int w;
                if(mmp[now^1].count(p)){
                    w=mmp[now^1][p]+1;
                }else w=1;
                ans=max(ans,w);
                mmp[now][p]=w;
            }
            now^=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
