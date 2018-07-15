#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<string>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define PB push_back
#define ALL(X) (X).begin(),(X).end()
typedef vector<int> vi;
typedef long long ll;
/************long long****************/

struct node{
    int l,r;
}no[25005];
bool cmp(node x,node y){
    if(x.l==y.l)return x.r>y.r;
    else return x.l<y.l;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t;
    cin>>n>>t;
    REP(i,1,n)cin>>no[i].l>>no[i].r;
    sort(no+1,no+1+n,cmp);
    int ans=1;
    if(no[1].l>1){
        cout<<-1;
        return 0;
    }
    int rr=no[1].r;
    int now=rr;
    REP(i,2,n){
        if(no[i].l<=rr+1){
            now=max(now,no[i].r);
        }
        else{
            if(no[i].l>now+1){
                cout<<-1;
                return 0;
            }
            else{
                if(now>rr)ans++;
                i--;
                rr=now;
            }
        }
    }
    if(rr!=now)ans++;
    if(now<t){
        cout<<-1;
    }
    else{
        cout<<ans;
    }
    return 0;
}
