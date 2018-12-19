#include<cstdio>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
const int MAXN=5e5+10;
int cnt[MAXN];
int w[MAXN];
char name[MAXN][15];
int a[MAXN];
struct BIT{
    int n;
    ll c[MAXN<<1];
    void init(int _n){
        n=_n;
        rep(i,0,n)c[i]=0;
    }
    void update(int i,ll v){
        for(;i<=n;i+=i&-i)c[i]+=v;
    }
    ll query(int i){
        ll s=0;
        for(;i;i-=i&-i)s+=c[i];
        return s;
    }
    int findpos(ll v){// >=v,if can't find ,return n+1;
        ll sum=0;
        int pos=0;
        int i=1;
        for(;i<n;i<<=1);
        for(;i;i>>=1){
            if(pos+i<=n&&sum+c[pos+i]<v){
                sum+=c[pos+i];
                pos+=i;
            }
        }
        return pos+1;
    }
}bit;
int main(){
    rep(i,1,500000){
        for(int j=i;j<=500000;j+=i){
            cnt[j]++;
        }
    }
    w[1]=1;\
    rep(i,2,500000){
        if(cnt[i]>cnt[w[i-1]]){
            w[i]=i;
        }else{
            w[i]=w[i-1];
        }
    }
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        bit.init(n);
        int k=w[n];
        rep(i,1,n){
            scanf("%s%d",name[i],&a[i]);
            bit.update(i,1);
        }
        int now=m;
        int pos=m;
        rep(i,1,k){
            if(i==k){
                printf("%s %d\n",name[pos],cnt[k]);
                break;
            }
            bit.update(pos,-1);
            if(a[pos]>0){
                now=(now-2+a[pos]+(n-1))%(n-1)+1;
                pos=bit.findpos(now);
            }else{
                now=now-(-a[pos])%(n-1);
                while(now<=0)now+=(n-1);
                while(now>(n-1))now-=(n-1);
                pos=bit.findpos(now);
            }
            n--;
        }
    }
    return 0;
}
