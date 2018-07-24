#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct BIT{
    int n,c[MAXN<<1];
    void init(int _n){n=_n;for(int i=0;i<=n;i++)c[i]=0;}
    void add(int i,int v){for(;i<=n;i+=i&-i)c[i]+=v;}
    int sum(int i){int s=0;for(;i>0;i-=i&-i)s+=c[i];return s;}
}bit;
int a[MAXN];
int fir[MAXN];
int las[MAXN];
int ans[MAXN];
struct node{
    int l,r,id;
}no[MAXN];
bool cmp(const node &x,const node &y){
    return x.r<y.r;
}
int main(){
    int n,q;
    while(scanf("%d%d",&n,&q)!=EOF){
        bit.init(n);
        memset(fir,-1,sizeof(fir));
        int w=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(fir[a[i]]==-1)fir[a[i]]=i,w++;
            las[a[i]]=i;
        }
        for(int i=1;i<=q;i++){
            scanf("%d%d",&no[i].l,&no[i].r);
            no[i].id=i;
        }
        sort(no+1,no+1+q,cmp);
        int index=1;
        for(int i=1;i<=q;i++){
            if(no[i].r-no[i].l==1){
                ans[no[i].id]=w;
                continue;
            }
            while(index<no[i].r){
                index++;
                if(las[a[index-1]]==index-1){
                    bit.add(1,1);
                    bit.add(fir[a[index-1]],-1);
                }
            }
            ans[no[i].id]=w-bit.sum(no[i].l);
        }
        for(int i=1;i<=q;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
