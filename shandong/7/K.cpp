//Reversed Words
#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
char s[MAXN];
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    while(n--){
        while(1){
            scanf("%[^ \n]",s);
            char c=getchar();
            int len=strlen(s);
            reverse(s,s+len);
            if(c=='\n'){
                printf("%s\n",s);
                break;
            }else{
                printf("%s ",s);
            }
        }
    }
    return 0;
}
