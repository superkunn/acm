#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long> > q;
int main(){
    int n;
    long long ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        long long x;
        scanf("%lld",&x);
        q.push(x);
    }
    while(q.size()>1){
        long long x=0;
        x+=q.top();
        q.pop();
        x+=q.top();
        q.pop();
        q.push(x);
        ans+=x;
    }
    printf("%lld",ans);
    return 0;
}
