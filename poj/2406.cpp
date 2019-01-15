#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1e6+10;
char s[MAXN];
int nxt[MAXN];
int main(){
    while(scanf("%s",s),s[0]!='.'){
        int len=strlen(s);
        if(len==0){
            puts("0");
            continue;
        }
        nxt[0]=-1;
        for(int i=1,j=-1;i<len;i++){
            while(j!=-1&&s[i]!=s[j+1])j=nxt[j];
            if(s[i]==s[j+1])j++;
            nxt[i]=j;
        }
        if(len%(len-1-nxt[len-1])==0){
            printf("%d\n",len/(len-1-nxt[len-1]));
        }else{
            puts("1");
        }
    }
    return 0;
}
