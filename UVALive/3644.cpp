#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1e5+2;
int p[MAXN+10];
void init(){
    rep(i,1,MAXN)p[i]=i;
}
int findp(int x){
    return x==p[x]?x:p[x]=findp(p[x]);
}
int main(){
    int x,y;
    int sum=0;
    init();
    while(~scanf("%d",&x)){
        if(x==-1){
            printf("%d\n",sum);
            sum=0;
            init();
            continue;
        }
        scanf("%d",&y);
        x=findp(x);
        y=findp(y);
        if(x==y){
            sum++;
        }else{
            p[x]=y;
        }
    }
    return 0;
}
