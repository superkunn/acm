#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(){
    int n;
    while(~scanf("%d",&n)){
        int f1=1,f2=1,f3=1;
        stack<int> st;
        queue<int> que;
        priority_queue<int> pque;
        rep(i,1,n){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x==1){
                if(f1)st.push(y);
                if(f2)que.push(y);
                if(f3)pque.push(y);
            }else{
                if(f1){
                    if(st.empty())f1=0;
                    else{
                        if(st.top()!=y)f1=0;
                        st.pop();
                    }
                }
                if(f2){
                    if(que.empty())f2=0;
                    else{
                        if(que.front()!=y)f2=0;
                        que.pop();
                    }
                }
                if(f3){
                    if(pque.empty())f3=0;
                    else{
                        if(pque.top()!=y)f3=0;
                        pque.pop();
                    }
                }
            }
        }
        if(f1+f2+f3==0)puts("impossible");
        else if(f1+f2+f3==1){
            if(f1==1)puts("stack");
            else if(f2==1)puts("queue");
            else puts("priority queue");
        }else puts("not sure");
    }
    return 0;
}
