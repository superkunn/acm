#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
queue<int> que;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        que.push(i);
    }
    int cnt=0;
    int tot=0;
    while(cnt<n){
        int now=que.front();
        que.pop();
        tot++;
        if(tot==m){
            tot=0;
            cnt++;
            printf("%d ",now);
        }else{
            que.push(now);
        }
    }
    return 0;
}
