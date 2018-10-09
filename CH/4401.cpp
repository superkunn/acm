#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include     <stack>
#include     <queue>
#include     <cmath>
#include       <set>
#include       <map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=4e4+10;
int a[MAXN];
int L[MAXN],R[MAXN],pos[MAXN];
int cnt[40][40][MAXN],ccc[40][MAXN];
int pmm[MAXN];
int t;
int main(){
//    freopen("C:\\Users\\hanxukun\\Desktop\\test\\in.txt","r",stdin);
//    freopen("C:\\Users\\hanxukun\\Desktop\\test\\out.txt","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    t=pow(1.0*n,1.0/3);
    int len=0;
    if(t)len=n/t;
    for(int i=1;i<=t;i++){
        L[i]=(i-1)*len+1;
        R[i]=i*len;
    }
    if(R[t]<n){
        t++;
        L[t]=R[t-1]+1;
        R[t]=n;
    }
    int tot=0;
    map<int,int> mmp;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(mmp.count(x)==0){
            mmp[x]=++tot;
            pmm[tot]=x;
        }
        a[i]=mmp[x];
    }
    for(int i=1;i<=t;i++){
        for(int j=L[i];j<=R[i];j++){
            ccc[i][a[j]]++;
            pos[j]=i;
        }
    }
    for(int i=1;i<=t;i++){
        for(int j=i;j<=t;j++){
            for(int k=1;k<=tot;k++){
                cnt[i][j][k]=cnt[i][j-1][k]+ccc[j][k];
            }

        }
    }
    int now=0;
    //cout<<t<<endl;
    while(m--){
        int x,y;
        scanf("%d%d",&x,&y);
        x=(x+now-1)%n+1;
        y=(y+now-1)%n+1;
        if(x>y)swap(x,y);
        //cout<<x<<" "<<y<<endl;
        int l=pos[x];
        int r=pos[y];
        int ans=0x3f3f3f3f;
        int num=1;
        if(l==r){
            for(int i=x;i<=y;i++){
                cnt[0][0][a[i]]++;
            }
            for(int i=1;i<=tot;i++){
                if(cnt[0][0][i]>num){
                    ans=pmm[i];
                    num=cnt[0][0][i];
                }else if(cnt[0][0][i]==num){
                    ans=min(ans,pmm[i]);
                }
            }
            for(int i=x;i<=y;i++){
                cnt[0][0][a[i]]--;
            }
        }else{
            for(int i=x;i<=R[l];i++){
                cnt[l+1][r-1][a[i]]++;
            }
            for(int i=L[r];i<=y;i++){
                cnt[l+1][r-1][a[i]]++;
            }
            for(int i=1;i<=tot;i++){
                if(cnt[l+1][r-1][i]>num){
                    ans=pmm[i];
                    num=cnt[l+1][r-1][i];
                }else if(cnt[l+1][r-1][i]==num){
                    ans=min(ans,pmm[i]);
                }
            }
            for(int i=x;i<=R[l];i++){
                cnt[l+1][r-1][a[i]]--;
            }
            for(int i=L[r];i<=y;i++){
                cnt[l+1][r-1][a[i]]--;
            }
        }
        now=ans;
        printf("%d\n",ans);
    }
    return 0;
}
