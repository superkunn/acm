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
const int MAXN=1e5+10;
char ss[20];
bool vis[MAXN];
int trie[MAXN][10],tot=1;
bool Insert(char* str){
    int len=strlen(str);
    int p=1;
    for(int i=0;i<len;i++){
        int ch=str[i]-'0';
        if(i==len-1){
            if(trie[p][ch]!=0)return true;
        }
        if(trie[p][ch]==0){
            trie[p][ch]=++tot;
        }
        p=trie[p][ch];
        if(vis[p])return true;
    }
    vis[p]=true;
    return false;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int m;
        scanf("%d",&m);
        int f=0;
        tot=1;
        memset(vis,0,sizeof(vis));
        memset(trie,0,sizeof(trie));
        for(int i=1;i<=m;i++){
            scanf("%s",ss);
            if(f)continue;
            f|=Insert(ss);
        }
        if(f){
            puts("NO");
        }else{
            puts("YES");
        }
    }
    return 0;
}
