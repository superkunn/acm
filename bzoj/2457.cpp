#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int main(){
    int n;
    scanf("%d",&n);
    pair<int,int> P[MAXN];
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        P[i]=make_pair(x,i);
    }
    sort(P+1,P+1+n);
    //for(int i=1;i<=n;i++)cout<<P[i].second<<endl;
    int cnt=1;
    int now=0;
    int f=1;
    for(int i=1;i<=n;i++){
        int r=i;
        int mi=P[i].second;
        int mx=P[i].second;
        while(i<n&&P[r+1].first==P[i].first){
            r++;
            mi=min(mi,P[r].second);
            mx=max(mx,P[r].second);
        }
        if(f==1){
            if(mi>=now)now=mx;
            else{
                f=0;
                now=mi;
            }
        }else{
            if(mx<=now)now=mi;
            else{
                f=1;
                cnt++;
                now=mx;
            }
        }
        i=r;
    }
    int ans=cnt;
    cnt=1;
    now=2e9;
    f=0;
    for(int i=1;i<=n;i++){
        int r=i;
        int mi=P[i].second;
        int mx=P[i].second;
        while(i<n&&P[r+1].first==P[i].first){
            r++;
            mi=min(mi,P[r].second);
            mx=max(mx,P[r].second);
        }
        if(f==1){
            if(mi>=now)now=mx;
            else{
                f=0;
                cnt++;
                now=mi;
            }
        }else{
            if(mx<=now)now=mi;
            else{
                f=1;
                now=mx;
            }
        }
        i=r;
    }
    printf("%d",min(ans,cnt));
    return 0;
}
