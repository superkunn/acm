#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <bitset>
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
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=2e6+10;
int trie[MAXN][2];
int tot=1;
void Insert(int x){
    int p=1;
    for(int i=30;i>=0;i--){
        int w=(x>>i)&1;
        if(trie[p][w]==0)trie[p][w]=++tot;
        p=trie[p][w];
    }
}
int query(int x){
    int p=1;
    int ans=0;
    for(int i=30;i>=0;i--){
        int w=(x>>i)&1;
        if(trie[p][w^1]!=0){
            p=trie[p][w^1];
            ans+=1<<i;
        }else{
            p=trie[p][w];
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    int x;
    scanf("%d",&x);
    Insert(x);
    int ans=0;
    for(int i=2;i<=n;i++){
        scanf("%d",&x);
        ans=max(ans,query(x));
        Insert(x);
    }
    printf("%d",ans);
    return 0;
}
