#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
const int MAXN=800;
int a[MAXN],b[MAXN];
int n;
int main(){
    while(~scanf("%d",&n)){
        rep(i,1,n)scanf("%d",&b[i]);
        sort(b+1,b+1+n);
        rep(i,2,n){
            rep(j,1,n)scanf("%d",&a[j]);
            sort(a+1,a+1+n);
            priority_queue<pii > pque;
            rep(j,1,n){
                int w=b[j]+a[1];
                pque.push(mp(-w,1));
            }
            rep(j,1,n){
                pii t=pque.top();
                pque.pop();
                b[j]=-t.fi;
                if(t.se+1<=n){
                    int w=-t.fi-a[t.se]+a[t.se+1];
                    pque.push(mp(-w,t.se+1));
                }
            }

        }
        rep(i,1,n)printf("%d%c",b[i]," \n"[i==n]);
    }
    return 0;
}
