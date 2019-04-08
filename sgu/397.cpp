#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1e6+10;
char buf[MAXN];
int main(){
    scanf("%s",buf+1);
    int len=strlen(buf+1);
    stack<char> a,b;
    rep(i,1,len){
        if(buf[i]=='L'){
            if(!a.empty()){
                b.push(a.top());
                a.pop();
            }
        }else if(buf[i]=='R'){
            if(!b.empty()){
                a.push(b.top());
                b.pop();
            }
        }else{
            a.push(buf[i]);
        }
    }
    while(!a.empty()){
        b.push(a.top());
        a.pop();
    }
    while(!b.empty()){
        putchar(b.top());
        b.pop();
    }
    return 0;
}
