#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
    return a+b<b+a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto ss:v){
        cout<<ss;
    }
    return 0;
}
