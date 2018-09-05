#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define lson rt<<1
#define rson rt<<1|1
#define le l,m,lson
#define ri m+1,r,rson
#define mid m=(l+r)>>1
typedef long long ll;
const int MAXN=5e4+10;
struct node{
    int mi,mx,sum,addv,setv;
    node(){
        mi=mx=sum=addv=setv=0;
    }
    node(int mi,int mx,int sum,int addv,int setv):mi(mi),mx(mx),sum(sum),addv(addv),setv(setv){}
}tree[25][MAXN<<2];
struct ANS{
    int mi,mx,sum;
    ANS(){
        mi=2000000000;
        mx=-1;
        sum=0;
    }
    ANS(int mi,int mx,int sum):mi(mi),mx(mx),sum(sum){}
};
ANS fun(ANS a,ANS b){
    ANS res;
    res.sum=a.sum+b.sum;
    res.mi=min(a.mi,b.mi);
    res.mx=max(a.mx,b.mx);
    return res;
}
void push_up(int id,int rt){
    tree[id][rt].sum=tree[id][lson].sum+tree[id][rson].sum;
    tree[id][rt].mi=min(tree[id][lson].mi,tree[id][rson].mi);
    tree[id][rt].mx=max(tree[id][lson].mx,tree[id][rson].mx);
}
void push_down(int id,int rt,int l,int r){
    if(tree[id][rt].setv!=0){
        tree[id][lson].setv=tree[id][rson].setv=tree[id][rt].setv;
        tree[id][lson].addv=tree[id][rson].addv=0;
        int mid;
        tree[id][lson].sum=(m-l+1)*tree[id][rt].setv;
        tree[id][rson].sum=(r-(m+1)+1)*tree[id][rt].setv;
        tree[id][lson].mi=tree[id][rson].mi=tree[id][lson].mx=tree[id][rson].mx=tree[id][rt].setv;
        tree[id][rt].setv=0;
    }
    if(tree[id][rt].addv!=0){
        tree[id][lson].addv+=tree[id][rt].addv;
        tree[id][rson].addv+=tree[id][rt].addv;
        int mid;
        tree[id][lson].sum+=(m-l+1)*tree[id][rt].addv;
        tree[id][rson].sum+=(r-(m+1)+1)*tree[id][rt].addv;
        tree[id][lson].mi+=tree[id][rt].addv;
        tree[id][rson].mi+=tree[id][rt].addv;
        tree[id][lson].mx+=tree[id][rt].addv;
        tree[id][rson].mx+=tree[id][rt].addv;
        tree[id][rt].addv=0;
    }
}
void update_add(int id,int L,int R,int v,int l,int r,int rt){
    if(L<=l&&r<=R){
        tree[id][rt].addv+=v;
        tree[id][rt].sum+=v*(r-l+1);
        tree[id][rt].mi+=v;
        tree[id][rt].mx+=v;
        return;
    }
    push_down(id,rt,l,r);
    int mid;
    if(m>=L){
        update_add(id,L,R,v,le);
    }
    if(m<R){
        update_add(id,L,R,v,ri);
    }
    push_up(id,rt);
}
void update_set(int id,int L,int R,int v,int l,int r,int rt){
    if(L<=l&&r<=R){
        tree[id][rt].addv=0;
        tree[id][rt].setv=v;
        tree[id][rt].sum=v*(r-l+1);
        tree[id][rt].mi=v;
        tree[id][rt].mx=v;
        return;
    }
    push_down(id,rt,l,r);
    int mid;
    if(m>=L){
        update_set(id,L,R,v,le);
    }
    if(m<R){
        update_set(id,L,R,v,ri);
    }
    push_up(id,rt);
}
ANS query(int id,int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        ANS t=ANS(tree[id][rt].mi,tree[id][rt].mx,tree[id][rt].sum);
        return t;
    }
    push_down(id,rt,l,r);
    int mid;
    if(m>=L){
        ANS n1=query(id,L,R,le);
        if(m<R){
            ANS n2=query(id,L,R,ri);
            return fun(n1,n2);
        }else return n1;
    }
    if(m<R)return query(id,L,R,ri);
}
int main(){
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)){
        int op,x1,x2,y1,y2,v;
        while(k--){
            scanf("%d",&op);
            if(op==1){
                scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
                rep(i,x1,x2){
                    update_add(i,y1,y2,v,1,m,1);
                }
            }else if(op==2){
                scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&v);
                rep(i,x1,x2){
                    update_set(i,y1,y2,v,1,m,1);
                }
            }else{
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                ANS ans;
                rep(i,x1,x2){
                    ANS t=query(i,y1,y2,1,m,1);
                    ans=fun(ans,t);
                }
                printf("%d %d %d\n",ans.sum,ans.mi,ans.mx);
            }
        }
    }
    return 0;
}
