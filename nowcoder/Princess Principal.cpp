#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
int a[MAXN];
int w[MAXN];
int tp[MAXN];
stack<int> stk;
int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    stk.push(0);
    w[0]=0;
    a[0]=-10;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if((a[i]&1)&&a[stk.top()]+1==a[i]){
            stk.pop();
            w[i]=stk.top();
        }else{
            w[i]=stk.top();
            stk.push(i);
        }
    }
//    for(int i=1;i<=n;i++)cout<<w[i]<<" ";
//    cout<<endl;
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        if((y-x)%2==0){
            puts("No");
            continue;
        }
        if(a[y]%2==1&&a[x]%2==0){
            if(w[x]==w[y])puts("Yes");
            else puts("No");
        }else{
            puts("No");
        }
    }
    return 0;
}
