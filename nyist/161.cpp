#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    while(cin>>a>>b){
        if(a>b)swap(a,b);
        if(floor((b-a)*(sqrt(5.0)+1)/2.0)==a){
            cout<<0<<endl;
        }else cout<<1<<endl;
    }
    return 0;
}
