#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN=400;
int mm[MAXN][MAXN];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&mm[i][j]);
        }
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            mm[i][j]+=max(mm[i+1][j],mm[i+1][j+1]);
        }
    }
    printf("%d",mm[1][1]);
    return 0;
}
