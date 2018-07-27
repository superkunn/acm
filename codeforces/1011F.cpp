#include<bits/stdc++.h>
#define _in 1
#define _and 2
#define _or 3
#define _xor 4
#define _not 5
using namespace std;
const int MAXN=1e6+5;
int lson[MAXN];
int rson[MAXN];
int tp[MAXN];
int val[MAXN];
int chg[MAXN];
int ans[MAXN];
char op[5];
void dfs1(int x){
    if(tp[x]==_in){
        return;
    }else if(tp[x]==_and){
        dfs1(lson[x]);
        dfs1(rson[x]);
        val[x]=val[lson[x]]&val[rson[x]];
    }else if(tp[x]==_or){
        dfs1(lson[x]);
        dfs1(rson[x]);
        val[x]=val[lson[x]]|val[rson[x]];
    }else if(tp[x]==_xor){
        dfs1(lson[x]);
        dfs1(rson[x]);
        val[x]=val[lson[x]]^val[rson[x]];
    }else{
        dfs1(lson[x]);
        val[x]=val[lson[x]]^1;
    }
}
void dfs2(int x){
    if(tp[x]==_in){
        chg[x]=1;
        return;
    }else if(tp[x]==_and){
        if(val[x]){
            dfs2(lson[x]);
            dfs2(rson[x]);
        }else if(val[lson[x]]){
            dfs2(rson[x]);
        }else if(val[rson[x]]){
            dfs2(lson[x]);
        }
    }else if(tp[x]==_or){
        if(!val[x]){
            dfs2(lson[x]);
            dfs2(rson[x]);
        }else if(!val[lson[x]]){
            dfs2(rson[x]);
        }else if(!val[rson[x]]){
            dfs2(lson[x]);
        }
    }else if(tp[x]==_xor){
        dfs2(lson[x]);
        dfs2(rson[x]);
    }else{
        dfs2(lson[x]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int index=0;
    for(int i=1;i<=n;i++){
        scanf("%s",op);
        if(op[0]=='I'){
            tp[i]=_in;
            scanf("%d",&val[i]);
            ans[++index]=i;
        }else if(op[0]=='A'){
            tp[i]=_and;
            scanf("%d%d",&lson[i],&rson[i]);
        }else if(op[0]=='O'){
            tp[i]=_or;
            scanf("%d%d",&lson[i],&rson[i]);
        }else if(op[0]=='X'){
            tp[i]=_xor;
            scanf("%d%d",&lson[i],&rson[i]);
        }else{
            tp[i]=_not;
            scanf("%d",&lson[i]);
        }
    }
    dfs1(1);
    dfs2(1);
    for(int i=1;i<=index;i++){
        printf("%d",chg[ans[i]]?val[1]^1:val[1]);
    }
    return 0;
}
