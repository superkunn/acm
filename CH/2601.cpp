#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <bitset>
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
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=500+10;
int r,c;
char mmp[MAXN][MAXN];
int mmmp[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool check(int x,int y){
    if(x<0||y<0||x>r||y>c)return false;
    if(vis[x][y])return false;
    return true;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&r,&c);
        for(int i=1;i<=r;i++){
            scanf("%s",mmp[i]+1);
        }
        //cout<<"read"<<endl;
        memset(mmmp,0x3f,sizeof(mmmp));
        memset(vis,0,sizeof(vis));
        deque<pii> deq;
        deq.push_back(mp(0,0));
        mmmp[0][0]=0;
        int ans=-1;
        while(!deq.empty()){
            pii now=deq.front();
            deq.pop_front();
            //cout<<now.first<<" "<<now.second<<"--"<<mmmp[now.first][now.second]<<endl;
            vis[now.first][now.second]=true;
            if(now.first==r&&now.second==c){
                ans=mmmp[now.first][now.second];
                break;
            }
            int x,y;
            x=now.first+1;
            y=now.second+1;
            if(check(x,y)){
                if(mmp[now.first+1][now.second+1]!='/'){
                    mmmp[x][y]=min(mmmp[x][y],mmmp[now.first][now.second]);
                    //cout<<"000"<<x<<" "<<y<<endl;
                    deq.push_front(mp(x,y));
                }else{
                    mmmp[x][y]=min(mmmp[x][y],mmmp[now.first][now.second]+1);
                    deq.push_back(mp(x,y));
                }
            }
            x=now.first-1;
            y=now.second-1;
            if(check(x,y)){
                if(mmp[now.first][now.second]!='/'){
                    mmmp[x][y]=min(mmmp[x][y],mmmp[now.first][now.second]);
                    //cout<<"000"<<x<<" "<<y<<endl;
                    deq.push_front(mp(x,y));
                }else{
                    mmmp[x][y]=min(mmmp[x][y],mmmp[now.first][now.second]+1);
                    deq.push_back(mp(x,y));
                }
            }
            x=now.first+1;
            y=now.second-1;
            if(check(x,y)){
                if(mmp[now.first+1][now.second]=='/'){
                    mmmp[x][y]=min(mmmp[x][y],mmmp[now.first][now.second]);
                    //cout<<"000"<<x<<" "<<y<<endl;
                    deq.push_front(mp(x,y));
                }else{
                    mmmp[x][y]=min(mmmp[x][y],mmmp[now.first][now.second]+1);
                    deq.push_back(mp(x,y));
                }
            }
            x=now.first-1;
            y=now.second+1;
            if(check(x,y)){
                if(mmp[now.first][now.second+1]=='/'){
                    mmmp[x][y]=min(mmmp[x][y],mmmp[now.first][now.second]);
                    //cout<<"000"<<x<<" "<<y<<endl;
                    deq.push_front(mp(x,y));
                }else{
                    mmmp[x][y]=min(mmmp[x][y],mmmp[now.first][now.second]+1);
                    deq.push_back(mp(x,y));
                }
            }
//            for(auto bb:deq){
//                cout<<"("<<bb.fi<<","<<bb.se<<") ";
//            }
//            cout<<endl;
        }
        if(ans==-1){
            puts("NO SOLUTION");
        }else{
            printf("%d\n",ans);
        }
    }
    return 0;
}
/*
4
4 4
\/\\
/\/\
//\\
\\\\
*/
