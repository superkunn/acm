#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        if(m==2){
            int a,b;
            cin>>a>>b;
            if(a>b)swap(a,b);
            if(floor((b-a)*(sqrt(5.0)+1)/2.0)==a)cout<<"Watson"<<endl;
            else cout<<"Sherlock"<<endl;
        }else{
            int ans=0;
            while(m--){
                int x;
                cin>>x;
                ans^=x;
            }
            if(ans==0)cout<<"Watson"<<endl;
            else cout<<"Sherlock"<<endl;
        }
    }
    return 0;
}
