#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e4+5;
struct BIT{
    int n,c[MAXN<<1];
    void init(int _n){
        n=_n;
        for(int i=0;i<=n;i++){
            c[i]=0;
        }
    }
    void add(int i,int v){
        for(;i<=n;i+=i&-i){
            c[i]+=v;
        }
    }
    int sum(int i){
        int s=0;
        for(;i>0;i-=i&-i){
            s+=c[i];
        }
        return s;
    }
}bit;
int a[MAXN];
int nex[MAXN];
int head[1000005];
struct node{
    int l,r,id;
}no[200005];
int ans[200005];
bool cmp(const node &x,const node &y){
    return x.r<y.r;
}
int main(){
    int n;
    scanf("%d",&n);
    bit.init(n);
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        nex[i]=head[a[i]];
        head[a[i]]=i;
    }

    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&no[i].l,&no[i].r);
        no[i].id=i;
    }
    sort(no+1,no+1+m,cmp);
    int index=0;
    for(int i=1;i<=m;i++){
        while(index<no[i].r){
            index++;
            bit.add(index,1);
            if(nex[index]!=-1){
                bit.add(nex[index],-1);
            }
        }
        ans[no[i].id]=bit.sum(no[i].r)-bit.sum(no[i].l-1);
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
