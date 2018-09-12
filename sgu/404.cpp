#include<bits/stdc++.h>
using namespace std;
char ans[105];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int pos=(n-1)%m;
    for(int i=0;i<m;i++){
        scanf("%s",ans);
        if(i==pos)puts(ans);
    }
    return 0;
}
