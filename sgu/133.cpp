#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
vector<pii > v;
bool cmp(pii a,pii b){
    if(a.first==b.first)return a.second>b.second;
    return a.first<b.first;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v.pb(mp(x,y));
    }
    sort(v.begin(),v.end(),cmp);
    int r=v[0].second;
    int ans=0;
    for(int i=1;i<n;i++){
        if(v[i].second<=r)ans++;
        else r=v[i].second;
    }
    printf("%d",ans);
    return 0;
}
