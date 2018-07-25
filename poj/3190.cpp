#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=5e4+5;
struct node{
    int l,r,id;
}no[MAXN];
struct node2{
    int id,t;
};
bool operator<(node2 x,node2 y){
    return x.t>y.t;
}
bool cmp(const node &x,const node &y){
    return x.l<y.l;
}
int ans[MAXN];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&no[i].l,&no[i].r);
        no[i].id=i;
    }
    sort(no+1,no+1+n,cmp);
    priority_queue<node2> que;
    int index=0;
    for(int i=1;i<=n;i++){
        if(!que.empty()&&que.top().t<no[i].l){
            ans[no[i].id]=que.top().id;
            node2 temp;
            temp.id=que.top().id;
            temp.t=no[i].r;
            que.pop();
            que.push(temp);
        }else{
            ans[no[i].id]=++index;
            node2 temp;
            temp.id=index;
            temp.t=no[i].r;
            que.push(temp);
        }
    }
    printf("%d\n",index);
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
