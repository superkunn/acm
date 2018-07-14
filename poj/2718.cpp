#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int mypow[]={1,10,100,1000,10000,100000,1000000,100000};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    getline(cin,s);
    while(n--){
        getline(cin,s);
        vector<int> v;
        for(int i=0;i<s.length();i++){
            if(s[i]!=' ')v.push_back(s[i]-'0');
        }
        int len=v.size();
        int ans=1e9;
        do{
            if(v[len/2-1]==0&&len/2!=1||v[len-1]==0&&len/2!=len-1)continue;
            int w1=0;
            int w2=0;
            for(int i=0;i<len/2;i++){
                w1+=mypow[i]*v[i];
            }
            for(int i=0;i+len/2<len;i++){
                w2+=mypow[i]*v[i+len/2];
            }
            ans=min(abs(w1-w2),ans);
        }while(next_permutation(v.begin(),v.end()));
        cout<<ans<<'\n';
    }
    return 0;
}
