#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include     <stack>
#include     <queue>
#include     <cmath>
#include       <set>
#include       <map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=2e6+10;
int T;
struct DSU{
    int p[MAXN];
    void init(int n){
        for(int i=1;i<=n;i++)p[i]=i;
    }
    int findp(int x){
        return x==p[x]?x:p[x]=findp(p[x]);
    }
    void unite(int x,int y){
        x=findp(x);
        y=findp(y);
        p[x]=y;
    }
    bool same(int x,int y){
        return findp(x)==findp(y);
    }
}dsu;
int main(){
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        queue<pair<int,int> > que;
        map<int,int> mmp;
        int tot=0;
        dsu.init(2000000);
        while(n--){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(mmp.count(x)==0){
                mmp[x]=++tot;
            }
            x=mmp[x];
            if(mmp.count(y)==0){
                mmp[y]=++tot;
            }
            y=mmp[y];
            if(z==1){
                dsu.unite(x,y);
            }else{
                que.push(make_pair(x,y));
            }
        }
        bool f=true;
        while(!que.empty()){
            int x=que.front().first;
            int y=que.front().second;
            que.pop();
            if(dsu.same(x,y)){
                f=false;
                break;
            }
        }
        if(f)puts("YES");
        else puts("NO");
    }
    return 0;
}
