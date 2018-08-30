#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;
#define clr(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=200+10;
int SG[MAXN][MAXN];
int fun(int a,int b){
    if(SG[a][b]!=-1)return SG[a][b];
    set<int> s;
    for(int i=2;i+2<=a;i++)s.insert(fun(i,b)^fun(a-i,b));
    for(int i=2;i+2<=b;i++)s.insert(fun(a,i)^fun(a,b-i));
    int g=0;
    while(s.count(g)!=0)g++;
    return SG[a][b]=g;
}
int main(){
    clr(SG,-1);
    int a,b;
    while(~scanf("%d%d",&a,&b)){
        if(fun(a,b)!=0)puts("WIN");
        else puts("LOSE");
    }
    return 0;
}
