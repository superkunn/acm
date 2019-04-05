#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int tp(char c){
    if('0'<=c&&c<='9'){
        return 1;
    }
}
int main(){
    string s;
    cin>>s;
    int len=s.length()-1;
    int l=-1;
    stack<int> st;
    while(l<len){
        l++;
        if(tp(s[l])==1){
            int now=s[l]-'0';
            while(s[++l]!='.'){
                now*=10;
                now+=s[l]-'0';
            }
            st.push(now);
        }else if(s[l]=='+'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(x+y);
        }else if(s[l]=='-'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y-x);
        }else if(s[l]=='*'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(x*y);
        }else if(s[l]=='/'){
            int x=st.top();
            st.pop();
            int y=st.top();
            st.pop();
            st.push(y/x);
        }else{
            printf("%d",st.top());
        }
    }
    return 0;
}
