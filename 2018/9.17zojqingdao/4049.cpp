#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=10000+10;
const int MOD=256;
int cnt[MAXN];
int tp[MAXN],a[MAXN],b[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            char op[10];
            scanf("%s",op);
            if(op[0]=='a'){
                tp[i]=1;
                scanf("%d",&a[i]);
            }else if(op[1]=='e'){
                tp[i]=2;
                scanf("%d%d",&a[i],&b[i]);
            }else if(op[1]=='n'){
                tp[i]=3;
                scanf("%d%d",&a[i],&b[i]);
            }else if(op[1]=='l'){
                tp[i]=4;
                scanf("%d%d",&a[i],&b[i]);
            }else if(op[1]=='g'){
                tp[i]=5;
                scanf("%d%d",&a[i],&b[i]);
            }
        }
        int now=1;
        int sum=0;
        bool f=0;
        memset(cnt,0,sizeof(cnt));
        while(now<=n){
            cnt[now]++;
            if(cnt[now]>256){
                puts("No");
                f=1;
                break;
            }
            if(tp[now]==1){
                sum+=a[now];
                sum%=MOD;
                now++;
            }else if(tp[now]==2){
                if(sum==a[now]){
                    now=b[now];
                }else{
                    now++;
                }
            }else if(tp[now]==3){
                if(sum!=a[now]){
                    now=b[now];
                }else{
                    now++;
                }
            }else if(tp[now]==4){
                if(sum<a[now]){
                    now=b[now];
                }else{
                    now++;
                }
            }else if(tp[now]==5){
                if(sum>a[now]){
                    now=b[now];
                }else{
                    now++;
                }
            }
        }
        if(!f)puts("Yes");
    }
    return 0;
}
