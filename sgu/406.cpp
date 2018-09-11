#include<bits/stdc++.h>
using namespace std;
char s[30];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        int len=strlen(s);
        if(s[len-1]=='f'){
            for(int i=0;i<len-1;i++)putchar(s[i]);
            puts("ves");
        }else if(s[len-2]=='f'&&s[len-1]=='e'){
            for(int i=0;i<len-2;i++)putchar(s[i]);
            puts("ves");
        }else if(s[len-1]=='x'||s[len-1]=='s'||s[len-1]=='o'||(s[len-2]=='c'&&s[len-1]=='h')){
            for(int i=0;i<len;i++)putchar(s[i]);
            puts("es");
        }else if(s[len-1]=='y'){
            for(int i=0;i<len-1;i++)putchar(s[i]);
            puts("ies");
        }else{
            for(int i=0;i<len;i++)putchar(s[i]);
            puts("s");
        }
    }
    return 0;
}
