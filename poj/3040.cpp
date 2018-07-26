#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=25;
struct node{
    int v,b;
}no[MAXN];
bool cmp(const node &x,const node &y){
    return x.v<y.v;
}
int main(){
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&no[i].v,&no[i].b);
    }
    sort(no+1,no+1+n,cmp);
    int ans=0;
    bool update=1;
    while(update){
        update=0;
        int now=0;
        for(int i=n;i>=1;i--){
            if(no[i].b==0)continue;
            int re=c-now;
            if(re>=no[i].v){
                int w=re/no[i].v;
                if(no[i].b>=w){
                    no[i].b-=w;
                    now+=w*no[i].v;
                }else{
                    now+=no[i].b*no[i].v;
                    no[i].b=0;
                }
            }
        }
        if(now==c){
            ans++;
            update=1;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(no[i].b==0)continue;
            no[i].b--;
            update=1;
            ans++;
            break;
        }
    }
    printf("%d",ans);
    return 0;
}
