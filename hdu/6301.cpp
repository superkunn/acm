#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct node{
    int l,r;
}no[MAXN];
bool cmp(node x,node y){
    if(x.l==y.l)return x.r>y.r;
    return x.l<y.l;
}
int ans[MAXN];
priority_queue<int,vector<int>,greater<int> > que;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        while(!que.empty())que.pop();
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)que.push(i);
        for(int i=1;i<=m;i++){
            cin>>no[i].l>>no[i].r;
        }
        sort(no+1,no+1+m,cmp);
        for(int i=1;i<no[1].l;i++){
            ans[i]=1;
        }
        for(int i=no[1].l;i<=no[1].r;i++){
            ans[i]=que.top();
            que.pop();
        }
        int ll=no[1].l,rr=no[1].r;
        for(int i=2;i<=m;i++){
            if(no[i].r<=rr)continue;
            if(no[i].l<=rr){
                while(ll<no[i].l){
                    que.push(ans[ll]);
                    ll++;
                }
                while(rr<no[i].r){
                    rr++;
                    ans[rr]=que.top();
                    que.pop();
                }
            }
            else{
                for(int j=ll;j<=rr;j++){
                    que.push(ans[j]);
                }
                for(int j=rr+1;j<no[i].l;j++){
                    ans[j]=1;
                }
                for(int j=no[i].l;j<=no[i].r;j++){
                    ans[j]=que.top();
                    que.pop();
                }
                ll=no[i].l,rr=no[i].r;
            }
        }
        for(int i=rr+1;i<=n;i++){
            ans[i]=1;
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i];
            if(i!=n)cout<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
