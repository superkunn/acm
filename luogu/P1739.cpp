#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1000+5;
char str[MAXN];
int main(){
    scanf("%s",str+1);
    int len=strlen(str+1);
    int cnt=0;
    rep(i,1,len){
        if(str[i]=='('){
            cnt++;
        }else if(str[i]==')'){
            cnt--;
            if(cnt<0){
                puts("NO");
                return 0;
            }
        }
    }
    printf("%s",cnt?"NO":"YES");
    return 0;
}
