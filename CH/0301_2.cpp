#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> ans;
void dfs(int x){
    if(x==n+1){
        int sz=ans.size();
        for(int i=0;i<sz;i++){
            printf("%d ",ans[i]);
        }
        puts("");
        return;
    }
    dfs(x+1);
    ans.push_back(x);
    dfs(x+1);
    ans.pop_back();
}
int main(){
    scanf("%d",&n);
    dfs(1);
    return 0;
}
