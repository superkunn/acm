//Phone Number
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1e3+10;
string s[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n){
        if(n==0)break;
        rep(i,1,n){
            cin>>s[i];
        }
        sort(s+1,s+1+n);
        if(n==1){
            cout<<"YES"<<endl;
            continue;
        }
        bool f=true;
        rep(i,1,n-1){
            int len1=s[i].length();
            int len2=s[i+1].length();
            if(len2<len1)continue;
            bool flag=true;
            for(int j=0;j<len1;j++){
                if(s[i][j]!=s[i+1][j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                f=false;
                break;
            }
        }
        if(f)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
