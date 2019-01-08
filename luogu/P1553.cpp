#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
char s[30];
int check(int len){
    rep(i,1,len){
        if(s[i]=='.')return 2;
        if(s[i]=='/')return 3;
        if(s[i]=='%')return 4;
    }
    return 1;
}
int fd(int len,char c){
    rep(i,1,len){
        if(s[i]==c){
            return i;
        }
    }
}
void fun1(int l,int r){
    int now=r;
    while(s[now]=='0'&&now!=l){
        now--;
    }
    per(i,now,l){
        putchar(s[i]);
    }
}
void fun2(int l,int r){
    int now=l;
    while(s[now]=='0'&&now!=r){
        now++;
    }
    per(i,r,now){
        putchar(s[i]);
    }
}
int main(){
    scanf("%s",s+1);
    int len=strlen(s+1);
    int tp=check(len);
    if(tp==1){
        fun1(1,len);
    }else if(tp==2){
        int p=fd(len,'.');
        fun1(1,p-1);
        putchar('.');
        fun2(p+1,len);
    }else if(tp==3){
        int p=fd(len,'/');
        fun1(1,p-1);
        putchar('/');
        fun1(p+1,len);
    }else{
        fun1(1,len-1);
        putchar('%');
    }
    return 0;
}
