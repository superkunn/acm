#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> ans;
void dfs(int x){
    if(ans.size()>m||ans.size()+n-x+1<m)return;
    if(x==n+1){
        int sz=ans.size();
        for(int i=0;i<sz;i++){
            printf("%d ",ans[i]);
        }
        puts("");
        return;
    }
    ans.push_back(x);
    dfs(x+1);
    ans.pop_back();
    dfs(x+1);
}
int main(){
    scanf("%d%d",&n,&m);
    dfs(1);
    return 0;
}
