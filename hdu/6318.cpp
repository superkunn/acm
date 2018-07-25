#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> A;
ll merge_count(vector<int> &a){
    int n=a.size();
    if(n<=1)return 0;
    ll cnt=0;
    vector<int> b(a.begin(),a.begin()+n/2);
    vector<int> c(a.begin()+n/2,a.end());
    cnt+=merge_count(b);
    cnt+=merge_count(c);
    int ai=0,bi=0,ci=0;
    while(ai<n){
        if(bi<b.size()&&(ci==c.size()||b[bi]<=c[ci])){
            a[ai++]=b[bi++];
        }else{
            cnt+=n/2-bi;
            a[ai++]=c[ci++];
        }
    }
    return cnt;
}
int main(){
    int n,x,y;
    while(~scanf("%d%d%d",&n,&x,&y)){
        A.clear();
        for(int i=0;i<n;i++){
            int w;
            scanf("%d",&w);
            A.push_back(w);
        }
        printf("%lld\n",merge_count(A)*min(x,y));
    }
    return 0;
}
