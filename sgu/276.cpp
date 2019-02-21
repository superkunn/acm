#include<bits/stdc++.h>
using namespace std;
int main(){
    int s,p;
    scanf("%d%d",&s,&p);
    if(p<=s){
        puts("0");
    }else if(s+60*5>p){
        puts("1");
    }else if(s+60*15>p){
        puts("2");
    }else if(s+60*30>p){
        puts("3");
    }else{
        puts("4");
    }
    return 0;
}
