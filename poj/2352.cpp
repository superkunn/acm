#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=15000+5;
const int MAXM=32000+5;
struct BIT{
    int n,c[MAXM<<1];
    void init(int _n){n=_n;for(int i=0;i<=n;i++)c[i]=0;}
    void add(int x,int v){for(int i=x;i<=n;i+=i&-i)c[i]+=v;}
    int sum(int x){int s=0;for(int i=x;i>0;i-=i&-i)s+=c[i];return s;}
}bit;
struct node{
    int x,y;
}no[MAXN];
int ans[MAXN];
int main(){
    int n;
    scanf("%d",&n);
    bit.init(MAXM);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x++;
        y++;
        ans[bit.sum(x)]++;
        bit.add(x,1);
    }
    for(int i=0;i<n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
