#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
    int pos;
    int ful;
}no[10005];
bool cmp(node x,node y){
    return x.pos>y.pos;
}
priority_queue<int> que;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&no[i].pos,&no[i].ful);
    }
    int x,y;
    scanf("%d%d",&x,&y);
    int index=0;
    for(int i=1;i<=n;i++){
        if(no[i].pos<=x){
            no[++index].pos=no[i].pos;
            no[index].ful=no[i].ful;
        }
    }
    no[++index].pos=0;
    no[index].ful=0;
    sort(no+1,no+1+index,cmp);
    int ans=0;
    for(int i=1;i<=index;i++){
        while(x-y>no[i].pos){
            if(que.empty()){
                printf("-1");
                return 0;
            }
            y+=que.top();
            que.pop();
            ans++;
        }
        que.push(no[i].ful);
    }
    printf("%d",ans);
    return 0;
}
