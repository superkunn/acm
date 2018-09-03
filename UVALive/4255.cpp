#include<bits/stdc++.h>
using namespace std;
const int MAXV=12;
int G[MAXV][MAXV];
int mmp[MAXV][MAXV];
int indec[MAXV];
void init(){
    memset(G,0,sizeof(G));
    memset(mmp,0,sizeof(mmp));
    memset(indec,0,sizeof(indec));
}
int que[MAXV];
int st,ed;
int ans[MAXV];
void topsort(int n){
    st=1;
    ed=0;
    for(int i=0;i<=n;i++){
        if(indec[i]==0)que[++ed]=i;
    }
    while(st<=ed){
        int u=que[st++];
        for(int i=0;i<=n;i++){
            if(G[u][i]!=1)continue;
            int v=i;
            if(--indec[v]==0)que[++ed]=v;
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        getchar();
        init();
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                char c=getchar();
                if(c=='-'){
                    G[i-1][j]=1;
                    indec[j]++;
                }else if(c=='0'){
                    mmp[j][i-1]=2;
                    G[j][i-1]=1;
                    indec[i-1]++;
                }else{
                    G[j][i-1]=1;
                    indec[i-1]++;
                }
            }
        }
        topsort(n);
        int now;
        for(int i=1;i<=ed;i++){
            if(que[i]==0)now=i;
            //cout<<que[i]<<" ";
        }
        //cout<<endl;
        //cout<<now<<endl;
        ans[0]=0;
        for(int i=now+1;i<=ed;i++){
            if(mmp[que[i]][que[i-1]]==2||mmp[que[i-1]][que[i]]==2){
               ans[que[i]]=ans[que[i-1]];
               continue;
            }
            ans[que[i]]=ans[que[i-1]]-1;
        }
        for(int i=now-1;i>=1;i--){
            if(mmp[que[i]][que[i+1]]==2||mmp[que[i+1]][que[i]]==2){
               ans[que[i]]=ans[que[i+1]];
               continue;
            }
            ans[que[i]]=ans[que[i+1]]+1;
        }
        for(int i=1;i<=n;i++){
            printf("%d%c",ans[i]-ans[i-1]," \n"[i==n]);
        }
    }
    return 0;
}
