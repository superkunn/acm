#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1e6+10;
const int MOD=1e9+7;
const int P=131;
char s[MAXN];
int base[MAXN];
int a[MAXN];
int main(){
    scanf("%s",s);
    int len=strlen(s);
    base[0]=1;
    a[0]=s[0]-'a';
    for(int i=1;i<len;i++){
        base[i]=1LL*base[i-1]*P%MOD;
        a[i]=(1LL*base[i]*(s[i]-'a')+a[i-1])%MOD;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(r1-l1!=r2-l2){
            puts("No");
            continue;
        }
        int dis=l2-l1;
        ll w1=a[r1-1];
        if(l1!=1)w1=(w1-a[l1-2]+MOD)%MOD;
        ll w2=a[r2-1];
        if(l2!=1)w2=(w2-a[l2-2]+MOD)%MOD;
        if(dis>=0){
            w1=w1*base[dis]%MOD;
        }else{
            w2=w2*base[-dis]%MOD;
        }
        if(w1==w2)puts("Yes");
        else puts("No");
    }
    return 0;
}
