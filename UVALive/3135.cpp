#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
char op[10];
int mmp[3005];
int main(){
    priority_queue<pii > pque;
    while(~scanf("%s",op)){
        if(op[0]=='#')break;
        int x,y;
        scanf("%d%d",&x,&y);
        mmp[x]=-y;
        pque.push(mp(-y,-x));
    }
    int k;
    scanf("%d",&k);
    while(k--){
        printf("%d\n",-pque.top().se);
        pii temp=pque.top();
        pque.pop();
        temp.fi+=mmp[-temp.se];
        pque.push(temp);
    }
    return 0;
}
