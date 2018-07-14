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
int mm[8][8];
int v[1000000];
int base[]={1,10,100,1000,10000,100000,1000000,10000000};
map<string,int> mmp;
queue<string> que;
int ans=0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool check(int x,int y){
    if(1<=x&&x<=5&&1<=y&&y<=5)return true;
    else return false;
}
void bfs(int x,int y){
    while(!que.empty())que.pop();
    string ss="";
    ss+=char(x+'0');
    ss+=char(y+'0');
    ss+=char(mm[x][y]+'0');
    que.push(ss);
    while(!que.empty()){
        ss=que.front();
        que.pop();
        mmp[ss]=1;
        if(ss.length()==8){
            int w=0;
            for(int i=2;i<ss.length();i++){
                w+=base[i-2]*(ss[i]-'0');
            }
            if(v[w]==0)ans++;
            v[w]=1;
            continue;
        }
        REP(i,0,3){
            int nx=ss[0]-'0'+dx[i];
            int ny=ss[1]-'0'+dy[i];
            if(check(nx,ny)){
                string sss=ss;
                sss+=char(mm[nx][ny]+'0');
                sss[0]=char(nx+'0');
                sss[1]=char(ny+'0');
                if(mmp[sss]==0){
                    que.push(sss);
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    REP(i,1,5){
        REP(j,1,5){
            cin>>mm[i][j];
        }
    }
    REP(i,1,5){
        REP(j,1,5){
            bfs(i,j);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
