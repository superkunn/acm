#include<bits/stdc++.h>
using namespace std;
bool check(string s){
    if(s.length()!=6)return false;
    string ss="jessie";
    for(int i=0;i<6;i++){
        bool f=0;
        if(s[i]-'a'==ss[i]-'a'||s[i]-'A'==ss[i]-'a'){
            f=1;
        }
        if(f==0)return false;
    }
    return true;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        string s;
        cin>>s;
        if(check(s))puts("Good guy!");
        else puts("Dare you say that again?");
    }
    return 0;
}
