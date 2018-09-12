#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
vi A;
ll merging(vi &a){
    int len=a.size();
    if(len<=1)return 0;
    vi b(a.begin(),a.begin()+len/2);
    vi c(a.begin()+len/2,a.end());
    ll res=0;
    res+=merging(b);
    res+=merging(c);
    int al=0,bl=0,cl=0;
    while(al<len){
        if(bl<b.size()&&(cl==c.size()||b[bl]<=c[cl])){
            a[al++]=b[bl++];
        }else{
            res+=len/2-bl;
            a[al++]=c[cl++];
        }
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        A.pb(x);
    }
    ll ans=merging(A);
    printf("%I64d",ans);
    return 0;
}
