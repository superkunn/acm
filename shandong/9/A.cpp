//Anagram
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
const int MAXN=1e5+10;
char a[MAXN],b[MAXN];
bool vis[MAXN];
int main(){
    while(~scanf("%s%s",a+1,b+1)){
        int len=strlen(a+1);
        multiset<char> mst;
        memset(vis,0,sizeof(vis));
        rep(i,1,len){
            mst.insert(b[i]);
        }
        int ans=0;
        rep(i,0,25){
            if(mst.size()==0)break;
            rep(j,1,len){
                if(vis[j])continue;
                char now='A'+(a[j]-'A'+i)%26;
                auto it=mst.find(now);
                if(it!=mst.end()){
                    ans+=i;
                    vis[j]=true;
                    mst.erase(it);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
