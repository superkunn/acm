#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
priority_queue<float>  que;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        float x;
        scanf("%f",&x);
        que.push(x);
    }
    while(que.size()!=1){
        float x=que.top();
        que.pop();
        float y=que.top();
        que.pop();
        float z=sqrt(x*y)*2.0;
        que.push(z);
    }
    printf("%.3f",que.top());
    return 0;
}
