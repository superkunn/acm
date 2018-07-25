#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
struct BIT{
    int n;
    long long c[MAXN<<1];
    void init(int _n){n=_n;for(int i=0;i<=n;i++)c[i]=0;}
    void add(int x,int v){for(int i=x;i<=n;i+=i&-i)c[i]+=v;}
    long long sum(int x){long long s=0;for(int i=x;i>0;i-=i&-i)s+=c[i];return s;}
}bit;
struct node{
    int v, id;
}no[MAXN];
int a[MAXN];
bool cmp(const node &x,const node &y){
    return x.v<y.v;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        if(n==0)break;
        for(int i=1;i<=n;i++){
            scanf("%d",&no[i].v);
            no[i].id=i;
        }
        sort(no+1,no+1+n,cmp);
        int index=1;
        a[no[1].id]=1;
        for(int i=2;i<=n;i++){
            if(no[i].v!=no[i-1].v){
                index++;
            }
            a[no[i].id]=index;
        }
        bit.init(n);
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans+=bit.sum(n)-bit.sum(a[i]);
            bit.add(a[i],1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
