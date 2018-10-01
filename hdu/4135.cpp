#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int sum[MAXN];
int ans[MAXN];
int now=1;
stack<int> L,R;
void funin(int x){
    L.push(x);
    sum[now]=sum[now-1]+x;
    ans[now]=max(ans[now-1],sum[now]);
    now++;
}
int main(){
    int n;
    scanf("%d",&n);
    char op[5];
    ans[0]=-2e9;
    while(n--){
        scanf("%s",op);
        if(op[0]=='I'){
           int x;
           scanf("%d",&x);
           funin(x);
        }else if(op[0]=='D'){
            now--;
            L.pop();
        }else if(op[0]=='R'){
            int x=R.top();
            L.push(x);
            R.pop();
            funin(x);
        }else if(op[0]=='L'){
            int x=L.top();
            R.push(x);
            L.pop();
            now--;
        }else{
            int k;
            scanf("%d",&k);
            printf("%d\n",ans[k]);
        }
    }
    return 0;
}
