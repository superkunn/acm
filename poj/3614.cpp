
#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
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
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=2505;
int C,L;
pii cow[MAXN];
pii lotion[MAXN];
priority_queue<int,vi,greater<int> > que;
int work(){
    scanf("%d%d",&C,&L);
    rep(i,1,C)scanf("%d%d",&cow[i].fi,&cow[i].se);
    rep(i,1,L)scanf("%d%d",&lotion[i].fi,&lotion[i].se);
    sort(cow+1,cow+1+C);
    sort(lotion+1,lotion+1+L);
    int index=1;
    int ans=0;
    rep(i,1,L){
        while(index<=C&&cow[index].fi<=lotion[i].fi){
            que.push(cow[index].se);
            index++;
        }
        while(!que.empty()&&lotion[i].se){
            int tmp=que.top();
            que.pop();
            if(tmp<lotion[i].fi)continue;
            ans++;
            lotion[i].se--;
        }
    }
    printf("%d\n",ans);
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
