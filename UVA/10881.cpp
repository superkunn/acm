#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1e4+10;
struct node{
    int id,p,d;
    node(){}
    node(int id,int p,int d):id(id),p(p),d(d){}
    bool operator < (const node& a)const{
        return p<a.p;
    }
}no1[MAXN],no2[MAXN];
int ans1[MAXN],ans2[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    rep(kase,1,T){
        int l,t,n;
        scanf("%d%d%d",&l,&t,&n);
        rep(i,1,n){
            int x;
            char c;
            scanf("%d %c",&x,&c);
            int d=c=='L'?-1:1;
            no1[i]=node(i,x,d);
            no2[i]=node(0,x+t*d,d);
        }
        sort(no1+1,no1+1+n);
        sort(no2+1,no2+1+n);
        rep(i,1,n-1){
            if(no2[i].p==no2[i+1].p)no2[i].d=no2[i+1].d=0;
        }
        rep(i,1,n){
            ans1[no1[i].id]=no2[i].p;
            ans2[no1[i].id]=no2[i].d;
        }
        printf("Case #%d:\n",kase);
        rep(i,1,n){
            if(ans1[i]<0||ans1[i]>l)puts("Fell off");
            else{
                printf("%d ",ans1[i]);
                if(ans2[i]==-1)puts("L");
                else if(ans2[i]==0)puts("Turning");
                else puts("R");
            }
        }
        puts("");
    }
    return 0;
}
