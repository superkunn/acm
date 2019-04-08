#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;
const int MAXN=2e4+10;
const double eps=1e-8;
pii p[MAXN];
int main(){
    int n;
    scanf("%d",&n);
    double sum=0;
    rep(i,1,n){
        scanf("%d%d",&p[i].fi,&p[i].se);
        sum+=p[i].se;
    }
    sum/=2;
    sort(p+1,p+1+n);
    int pos;
    double now=0;
    rep(i,1,n){
        now+=p[i].se;
        if(now+eps>=sum){
            pos=p[i].fi;
            break;
        }
    }
    printf("%d",pos);
    return 0;
}
