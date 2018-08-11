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
#define clr(a,x) memset(a,x,sizeof(a))
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
int N,Q;
int tot;
struct node{
    int link[2],v;
    node(){link[0]=link[1]=-1;}
}no[400005];
int qq[150005][3];
int op,u,v,w,val;
int work(){
    while(scanf("%d%d",&N,&Q)!=EOF){
        tot=0;
        clr(qq,0);
        rep(kase,1,Q){
            scanf("%d",&op);
            if(op==1){
                scanf("%d%d%d",&u,&w,&val);
                no[++tot].v=val;
                no[tot].link[0]=no[tot].link[1]=-1;
                if(qq[u][2]==0){
                    qq[u][2]=1;
                    qq[u][0]=qq[u][1]=tot;
                }else{
                    rep(i,0,1){
                        if(no[qq[u][w]].link[i]==-1){
                            no[qq[u][w]].link[i]=tot;
                            no[tot].link[0]=qq[u][w];
                            qq[u][w]=tot;
                            break;
                        }
                    }
                    qq[u][2]++;
                }
            }else if(op==2){
                scanf("%d%d",&u,&w);
                if(qq[u][2]==0){
                    puts("-1");
                }else if(qq[u][2]==1){
                    printf("%d\n",no[qq[u][0]].v);
                    qq[u][2]=0;
                }else{
                    printf("%d\n",no[qq[u][w]].v);
                    rep(i,0,1){
                        if(no[qq[u][w]].link[i]!=-1){
                            int now=qq[u][w];
                            int ttt=no[now].link[i];
                            rep(j,0,1){
                                if(no[ttt].link[j]==now){
                                    no[ttt].link[j]=-1;
                                    qq[u][w]=ttt;
                                    break;
                                }    
                            }
                            break;
                        }
                    }
                    qq[u][2]--;
                }
            }else{
                scanf("%d%d%d",&u,&v,&w);
                if(qq[v][2]==0){

                }else if(qq[u][2]==0){
                    qq[u][2]=qq[v][2];
                    if(w==0){
                        qq[u][0]=qq[v][0];
                        qq[u][1]=qq[v][1];
                    }else{
                        qq[u][0]=qq[v][1];
                        qq[u][1]=qq[v][0];
                    }
                }else{
                    qq[u][2]+=qq[v][2];
                    rep(i,0,1){
                        if(no[qq[u][1]].link[i]==-1){
                            no[qq[u][1]].link[i]=qq[v][w];
                            rep(j,0,1){
                                if(no[qq[v][w]].link[j]==-1){
                                    no[qq[v][w]].link[j]=qq[u][1];
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    qq[u][1]=qq[v][w^1];
                }
                qq[v][2]=0;
            }
        } 
    }
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
