#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1e5+5;
int main(){
    int ans[19]={2,3,5,7,11,13,17,23,31,37,53,71,73,113,131,137,173,311,317};
    int T;
    scanf("%d",&T);
    char s[105];
    rep(kase,1,T){
        scanf("%s",s);
        int bbb;
        int len=strlen(s);
        //cout<<len<<endl;
        if(len>=5){
            bbb=317;
        }else{
            int x=0;
            for(int i=0;i<len;i++){
                x*=10;
                x+=(s[i]-'0');
            }
            for(int i=0;i<19;i++){
                if(ans[i]<=x)bbb=ans[i];
            }
        }
        cout<<"Case #"<<kase<<": ";
        cout<<bbb<<endl;
    }
    return 0;
}
