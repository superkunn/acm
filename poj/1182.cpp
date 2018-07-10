#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int p[50050];
int w[50050];
void init(int n){
    for(int i=0;i<=n;i++){
        p[i]=i;
        w[i]=0;
    }
}
int findp(int x){
    if(x==p[x])return x;
    int xx=findp(p[x]);
    w[x]=(w[x]+w[p[x]])%3;
    p[x]=xx;
    return xx;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    init(n);
    int ans=0;
    while(k--){
        int d,x,y;
        scanf("%d%d%d",&d,&x,&y);
        if(x>n||y>n){
            ans++;
            continue;
        }
        if(d==2){
            if(x==y){
                ans++;
                continue;
            }
            int xx=findp(x);
            int yy=findp(y);
            if(xx!=yy){
                p[xx]=yy;
                w[xx]=(w[y]-w[x]+1+3)%3;
            }
            else{
                if(w[x]!=(w[y]+1)%3){
                    ans++;
                }
            }
        }
        else{
            int xx=findp(x);
            int yy=findp(y);
            if(xx!=yy){
                p[xx]=yy;
                w[xx]=(w[y]-w[x]+3)%3;
            }
            else{
                if(w[x]!=w[y]){
                    ans++;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}
