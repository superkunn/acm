#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
map<char,string> mm;
int main(){
    mm['0']="0000";
    mm['1']="0001";
    mm['2']="0010";
    mm['3']="0011";
    mm['4']="0100";
    mm['5']="0101";
    mm['6']="0110";
    mm['7']="0111";
    mm['8']="1000";
    mm['9']="1001";
    mm['A']="1010";
    mm['B']="1011";
    mm['C']="1100";
    mm['D']="1101";
    mm['E']="1110";
    mm['F']="1111";
    mm['a']="1010";
    mm['b']="1011";
    mm['c']="1100";
    mm['d']="1101";
    mm['e']="1110";
    mm['f']="1111";
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        map<string,int> mmp;
        rep(i,1,m){
            int x;
            string s;
            cin>>x>>s;
            mmp[s]=x;
        }
        string ss;
        cin>>ss;
        string sss="";
        rep(i,0,ss.length()-1){
            sss+=mm[ss[i]];
        }
        int now=0;
        string ssss="";
        while(now+8<sss.length()){
            int cnt=0;
            rep(i,0,8-1){
                if(sss[now+i]=='1')cnt++;
            }
            now+=8+1;
            if(sss[now-1]-'0'==cnt%2)continue;
            rep(i,0,8-1){
                ssss+=sss[now-8-1+i];
            }
        }
        string sssss="";
        int index=0;
        rep(i,0,ssss.length()-1){
            sssss+=ssss[i];
            map<string,int>::iterator ite;
            ite=mmp.find(sssss);
            if(ite!=mmp.end()){
                cout<<char(mmp[sssss]);
                sssss="";
                index++;
            }
            if(index==n)break;
        }
        cout<<endl;
    }
    return 0;
}
