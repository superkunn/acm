#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(){
    int n;
    scanf("%d",&n);
    priority_queue<int> pque;
    while(n--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x;
            scanf("%d",&x);
            pque.push(-x);
        }else if(op==2){
            printf("%d\n",-pque.top());
        }else{
            pque.pop();
        }
    }
    return 0;
}
