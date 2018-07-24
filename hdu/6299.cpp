#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
struct node{
    int l,r;
}no[MAXN];
bool cmp(const node &x,const node &y){
    if(x.l==0&&y.l!=0)return true;
    if(x.l!=0&&y.l==0)return false;
    if(x.r==0&&y.r!=0)return false;
    if(x.r!=0&&y.r==0)return true;
    if(x.l<=x.r&&y.l>y.r)return true;
    if(y.l<=y.r&&x.l>x.r)return false;
    if(x.l<=x.r&&y.l<=y.r)return x.l<y.l;
    else return x.r>y.r;
}
char s[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int ans=0;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%s",s);
            int len=strlen(s);
            no[i].l=0;
            no[i].r=0;
            for(int j=0;j<len;j++){
                if(s[j]=='('){
                    no[i].r++;
                }
                else{
                    if(no[i].r==0){
                        no[i].l++;
                    }
                    else{
                        no[i].r--;
                        ans+=2;
                    }
                }
            }
        }
        sort(no+1,no+1+n,cmp);
        int ll=0;
        for(int i=1;i<=n;i++){
            int w=0;
            w=ll-no[i].l;
            if(w<=0){
                ans+=2*ll;
                ll=0;
            }
            else{
                ans+=2*no[i].l;
                ll=w;
            }
            ll+=no[i].r;
        }
        printf("%d\n",ans);
    }
    return 0;
}
