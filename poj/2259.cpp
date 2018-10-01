#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
using namespace std;
typedef long long ll;
bool inq[1005];
int main(){
    int n;
    int kase=0;
    while(scanf("%d",&n),n){
        printf("Scenario #%d\n",++kase);
        memset(inq,0,sizeof(inq));
        queue<int> que[1005];
        map<int,int> mmp;
        for(int i=1;i<=n;i++){
            int m;
            scanf("%d",&m);
            while(m--){
                int x;
                scanf("%d",&x);
                mmp[x]=i;
            }
        }
        char op[10];
        for(;;){
            scanf("%s",op);
            if(op[0]=='S')break;
            if(op[0]=='E'){
                int x;
                scanf("%d",&x);
                int tp=mmp[x];
                que[tp].push(x);
                if(!inq[tp]){
                    inq[tp]=true;
                    que[0].push(tp);
                }
            }else{
                int tp=que[0].front();
                printf("%d\n",que[tp].front());
                que[tp].pop();
                if(que[tp].empty()){
                    que[0].pop();
                    inq[tp]=false;
                }
            }
        }
        puts("");
    }
    return 0;
}
