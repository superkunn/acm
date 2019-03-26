//1A
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define lch(x) tr[x].son[0]
#define rch(x) tr[x].son[1]
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
const int MAXN=500+10;
const int INF=0x3f3f3f3f;
int n,m;
int mmp[MAXN][MAXN];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char str[MAXN];
int ctoi(char c){
    if('0'<=c&&c<='9')return c-'0';
    else return 10+c-'a';
}
void debug(int n,int m){
    rep(i,1,n){
        rep(j,1,m){
            printf("%d%c",mmp[i][j]," \n"[j==m]);
        }
    }
}
bool check(int x,int y){
    if(0<=x&&x<=n&&0<=y&&y<=m)return true;
    else return false;
}
void init(int x,int y){
    mmp[x][y]=-INF;
    rep(i,0,3){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(check(xx,yy)&&mmp[xx][yy]==0){
            init(xx,yy);
        }
    }
}
void dfs(int x,int y,int tp){
    mmp[x][y]=tp;
    rep(i,0,3){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(check(xx,yy)&&mmp[xx][yy]==-1){
            dfs(xx,yy,tp);
        }
    }
}
int num[MAXN*MAXN];
int col;
void dfs2(int x,int y){
    mmp[x][y]=-INF;
    rep(i,0,3){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(check(xx,yy)&&mmp[xx][yy]==0){
            dfs2(xx,yy);
        }else if(mmp[xx][yy]>0){
            col=mmp[xx][yy];
        }
    }
}
int ans[6];
int main(){
    int kase=0;
    while(scanf("%d%d",&n,&m),n+m){
        rep(i,0,n+1){
            rep(j,0,4*m+1){
                mmp[i][j]=0;
            }
        }
        rep(i,1,n){
            scanf("%s",str+1);
            int start=0;
            rep(j,1,m){
                int now=ctoi(str[j]);
                per(k,3,0){
                    mmp[i][start+4-k]=-((now>>k)&1);
                }
                start+=4;
            }
        }
        m*=4;
        //debug(n,m);
        n++,m++;
        init(0,0);
        int cnt=0;
        rep(i,1,n-1){
            rep(j,1,m-1){
                if(mmp[i][j]==-1){
                    cnt++;
                    num[cnt]=0;
                    dfs(i,j,cnt);
                }
            }
        }
        rep(i,1,n-1){
            rep(j,1,m-1){
                if(mmp[i][j]==0){
                    dfs2(i,j);
                    num[col]++;
                }
            }
        }
        rep(i,0,5){
            ans[i]=0;
        }
        rep(i,1,cnt){
            ans[num[i]]++;
        }
        printf("Case %d: ",++kase);
        while(ans[1]--){
            putchar('A');
        }
        while(ans[5]--){
            putchar('D');
        }
        while(ans[3]--){
            putchar('J');
        }
        while(ans[2]--){
            putchar('K');
        }
        while(ans[4]--){
            putchar('S');
        }
        while(ans[0]--){
            putchar('W');
        }
        puts("");
    }

    return 0;
}
/*
41 1
f
0
f
9
f
0
f
9
f
9
f
0
f
9
f
9
f
9
f
0
f
9
f
9
f
9
f
9
f
0
f
9
f
9
f
9
f
9
f
9
f
0 0



*/
