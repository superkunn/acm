#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=1e4+10;
int d[MAXN];
int main(){
    int n,m,h,r;
    scanf("%d%d%d%d",&n,&m,&h,&r);
    map<pair<int,int>,bool> mmp;
    while(r--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>y)swap(x,y);
        if(mmp.count(make_pair(x,y))==1)continue;
        mmp[make_pair(x,y)]=true;
        d[y]++;
        d[x+1]--;
    }
    for(int i=1;i<=n;i++){
        d[i]+=d[i-1];
        printf("%d\n",h+d[i]);
    }
    return 0;
}
