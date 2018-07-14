#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define PB push_back
#define ALL(X) (X).begin(),(X).end()
typedef vector<int> vi;
typedef long long ll;
/************long long****************/
int r,c;
int a[12][10005];
int ans;
void dfs(int x){
    if(x==r+1){
        int now=0;
        REP(i,1,c){
            int w=0;
            REP(j,1,r){
                if(a[j][i])w++;
            }
            now+=max(w,r-w);
        }
        ans=max(ans,now);
        return;
    }
    dfs(x+1);
    REP(i,1,c)a[x][i]^=1;
    dfs(x+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>r>>c){
        if(r==0&&c==0)break;
        ans=0;
        REP(i,1,r){
            REP(j,1,c){
                cin>>a[i][j];
            }
        }
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}
