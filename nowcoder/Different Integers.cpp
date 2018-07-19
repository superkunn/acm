#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
/************long long****************/
const int MAXN=1e5+5;
int mmp[MAXN];
int n,m;
struct node{
    int l,r,id;
}Q[MAXN];
int block;
int a[MAXN];
ll ANS,ans[MAXN];
bool cmp(node x,node y){
    if(x.l/block==y.l/block)return x.r<y.r;
    else return x.l/block<y.l/block;
}
void add(int x){
    if(mmp[a[x]]==0)ANS++;
    mmp[a[x]]++;
}
void del(int x){
    mmp[a[x]]--;
    if(mmp[a[x]]==0)ANS--;
}
void solve(){
    block=1000;
    while(scanf("%d%d",&n,&m)!=EOF){
        ANS=0;
        memset(mmp,0,sizeof(mmp));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(mmp[a[i]]==0)ANS++;
            mmp[a[i]]++;
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d",&Q[i].l,&Q[i].r);
            Q[i].id=i;
        }
        sort(Q+1,Q+1+m,cmp);
        int L=1,R=2;
        for(int i=1;i<=m;i++){
            while(L>Q[i].l){del(L);L--;}
            while(L<Q[i].l){L++;add(L);}
            while(R<Q[i].r){del(R);R++;}
            while(R>Q[i].r){R--;add(R);}
            ans[Q[i].id]=ANS;
        }
        for(int i=1;i<=m;i++){
            printf("%lld\n",ans[i]);
        }
    }
}
int main(){
    solve();
    return 0;
}
