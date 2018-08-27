#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
int T;
struct node{
    int jinjia;
    int chujia;
};
bool operator<(node x,node y){
    return x.chujia>y.chujia;
}

int main(){
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        priority_queue<node> yimai;
        priority_queue<int,vector<int>,greater<int> > daimai;
        rep(i,1,n){
            int x;
            scanf("%d",&x);
            if(daimai.empty()){
                if(yimai.empty()||yimai.top().chujia>=x){
                    daimai.push(x);
                }else{
                    if(!yimai.empty()&&yimai.top().chujia<x){
                        node t=yimai.top();
                        yimai.pop();
                        daimai.push(t.chujia);
                        t.chujia=x;
                        yimai.push(t);
                    }
                }

            }else{
                if(!yimai.empty()&&yimai.top().chujia<x){
                        node t=yimai.top();
                        yimai.pop();
                        int w=t.chujia;
                        t.chujia=x;
                        yimai.push(t);
                        if(daimai.empty()){
                            daimai.push(w);
                        }else{
                            if(daimai.top()<w){
                                node tt;
                                tt.jinjia=daimai.top();
                                daimai.pop();
                                tt.chujia=w;
                                yimai.push(tt);
                            }else{
                                daimai.push(w);
                            }
                        }
                }
                else if(x>daimai.top()){
                    node t;
                    t.jinjia=daimai.top();
                    t.chujia=x;
                    yimai.push(t);
                    daimai.pop();
                }else{
                    daimai.push(x);
                }
            }
        }
        ll ans=0;
        ll num=yimai.size()*2;
        //cout<<yimai.size()<<endl;
        while(!yimai.empty()){
            node t=yimai.top();
            yimai.pop();
          //  cout<<t.chujia<<" "<<t.jinjia<<endl;
            ans+=1LL*(t.chujia-t.jinjia);
        }
        printf("%lld %lld\n",ans,num);
    }
    return 0;
}
