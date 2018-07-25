#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1e3+5;
struct node{
    double l,r;
}no[MAXN];
bool cmp(const node &x,const node &y){
    return x.l<y.l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    double d;
    int kase=0;
    while(cin>>n>>d){
        if(n==0&&d==0)break;
        int ans=n;
        for(int i=1;i<=n;i++){
            double x,y;
            cin>>x>>y;
            if(y>d)ans=-1;
            double w=sqrt(d*d-y*y);
            no[i].l=x-w;
            no[i].r=x+w;
        }
        if(ans==-1){
            cout<<"Case "<<++kase<<": "<<ans<<'\n';
            continue;
        }
        sort(no+1,no+1+n,cmp);
        double ll,rr;
        ll=no[1].l;
        rr=no[1].r;
        for(int i=2;i<=n;i++){
            double lll=max(ll,no[i].l);
            double rrr=min(rr,no[i].r);
            if(lll<=rrr){
                ll=lll;
                rr=rrr;
                ans--;
            }else{
                ll=no[i].l;
                rr=no[i].r;
            }
        }
        cout<<"Case "<<++kase<<": "<<ans<<'\n';
    }
    return 0;
}
