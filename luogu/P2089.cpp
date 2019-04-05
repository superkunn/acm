#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=15;
bool check(int val,int len){
    if(val<len)return false;
    if(val>3*len)return false;
    return true;
}
int ans[MAXN];
bool flag;
int cnt;
void dfs(int re,int len){
    if(len==1){
        if(flag){
            rep(i,1,9){
                printf("%d ",ans[i]);
            }
            printf("%d\n",re);
        }else{
            cnt++;
        }
        return;
    }
    rep(i,1,3){
        if(check(re-i,len-1)){
            ans[10-len+1]=i;
            dfs(re-i,len-1);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    if(!check(n,10)){
        puts("0");
        return 0;
    }
    flag=false;
    dfs(n,10);
    printf("%d\n",cnt);
    flag=true;
    dfs(n,10);
    return 0;
}
