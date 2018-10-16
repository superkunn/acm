#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
map<string,int> mmp[10];
char s[10];
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%s",s);
            int len=strlen(s);
            mmp[i].clear();
            if(i==0){
                for(int j=1;j<(1<<len);j++){
                    int now=j;
                    string ss;
                    while(now){
                        int pos=now&-now;
                        int k=-1;
                        while(pos>0){
                            pos>>=1;
                            k++;
                        }
                        ss+=s[k];
                        now-=now&-now;
                    }
                    int chang=ss.length();
                    for(int k=0;k<chang;k++){
                        string sss;
                        for(int kk=0;kk<chang;kk++){
                            sss+=ss[(k+kk)%chang];
                        }
                        mmp[0][sss]=1;
                    }
                }
            }else{
                for(int j=1;j<(1<<len);j++){
                    int now=j;
                    string ss;
                    while(now){
                        int pos=now&-now;
                        int k=-1;
                        while(pos>0){
                            pos>>=1;
                            k++;
                        }
                        ss+=s[k];
                        now-=now&-now;
                    }
                    int chang=ss.length();
                    for(int k=0;k<chang;k++){
                        string sss;
                        for(int kk=0;kk<chang;kk++){
                            sss+=ss[(k+kk)%chang];
                        }
                        if(mmp[i-1].count(sss)!=0){
                            mmp[i][sss]=1;
                        }
                    }
                }
            }

        }
        string ans="";
        for(auto hhh:mmp[n-1]){
            if(hhh.first.length()>ans.length()){
                ans=hhh.first;
            }else if(hhh.first.length()==ans.length()){
                ans=min(ans,hhh.first);
            }
        }
        if(ans.length()!=0)cout<<ans<<endl;
        else puts("0");
    }
    return 0;
}
