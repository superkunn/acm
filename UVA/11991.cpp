#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
typedef vector<int> vi;
map<int,vi > mmp;
int main(){
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        mmp.clear();
        rep(i,1,n){
            int x;
            scanf("%d",&x);
            if(mmp.count(x)==0){
                mmp[x]=vi();
            }
            mmp[x].pb(i);
        }
        while(m--){
            int x,y;
            scanf("%d%d",&y,&x);
            if(mmp.count(x)==0||y>mmp[x].size())puts("0");
            else printf("%d\n",mmp[x][y-1]);
        }
    }
    return 0;
}
