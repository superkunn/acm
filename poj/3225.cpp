#include<cstdio>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lson rt<<1
#define rson rt<<1|1
const int MAXN=65535*2+1;
/*
1 -> 1
2 -> 0
3 -> ~
U -> [x,y] 1
I -> [0,x-1] 0 [y+1,MAXN] 0
D -> [x,y] 0
C -> [0,x-1] 0 [y+1,MAXN] 0 [x,y] ~
S -> [x,y] ~
*/
int tree[MAXN<<2];
int ans[MAXN];
void change(int &x){
    if(x==0)x=3;
    else if(x==3)x=0;
    else x=3-x;
}
void push_down(int rt){
    if(tree[rt]==1||tree[rt]==2){
        tree[lson]=tree[rson]=tree[rt];
        tree[rt]=0;
    }else if(tree[rt]==3){
        change(tree[lson]);
        change(tree[rson]);
        tree[rt]=0;
    }
}
void update1(int L,int R,int v,int l,int r,int rt){
    if(L<=l&&r<=R){
        tree[rt]=v;
        return;
    }
    if(l==r)return;
    int mid=(l+r)>>1;
    push_down(rt);
    if(mid>=L)update1(L,R,v,l,mid,lson);
    if(mid+1<=R)update1(L,R,v,mid+1,r,rson);
}
void update2(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        change(tree[rt]);
        return;
    }
    if(l==r)return;
    int mid=(l+r)>>1;
    push_down(rt);
    if(mid>=L)update2(L,R,l,mid,lson);
    if(mid+1<=R)update2(L,R,mid+1,r,rson);
}
void query(int l,int r,int rt){
    if(tree[rt]==1){
        rep(i,l,r)ans[i]=1;
    }else if(tree[rt]==2){
        return;
    }
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    push_down(rt);
    query(l,mid,lson);
    query(mid+1,r,rson);
}
void check(){
    query(0,MAXN,1);
    rep(i,0,30){
        if(i&1)printf("%d ",ans[i]);
        else printf("%d",ans[i]);
    }
    puts("");
}
int main(){
    char op[5];
    tree[1]=2;
    while(~scanf("%s",op)){
        if(op[0]=='z')break;
        getchar();
        char a,b;
        int x,y;
        scanf("%c%d,%d%c",&a,&x,&y,&b);
        if(a=='['){
            x=x*2;
        }else{
            x=x*2+1;
        }
        if(b==']'){
            y=y*2;
        }else{
            y=y*2-1;
        }
        if(op[0]=='U'){
            if(x<=y)update1(x,y,1,0,MAXN,1);
        }else if(op[0]=='I'){
            if(x>0)update1(0,x-1,2,0,MAXN,1);
            if(y<MAXN)update1(y+1,MAXN,2,0,MAXN,1);
        }else if(op[0]=='D'){
            if(x<=y)update1(x,y,2,0,MAXN,1);
        }else if(op[0]=='C'){
            if(x>0)update1(0,x-1,2,0,MAXN,1);
            if(y<MAXN)update1(y+1,MAXN,2,0,MAXN,1);
            if(x<=y)update2(x,y,0,MAXN,1);
        }else{
            if(x<=y)update2(x,y,0,MAXN,1);
        }
        //check();
    }
    query(0,MAXN,1);
    bool f=false;
    int l=-1;
    rep(i,0,MAXN+1){
        if(ans[i]==1){
            f=true;
            if(l==-1){
                l=i;
            }
        }else{
            if(l!=-1){
                if(l&1){
                    printf("(%d,",l>>1);
                }else{
                    printf("[%d,",l>>1);
                }
                if((i-1)&1){
                    printf("%d) ",i>>1);
                }else{
                    printf("%d] ",i>>1);
                }
                l=-1;
            }
        }
    }
    if(!f)puts("empty set");
    return 0;
}
