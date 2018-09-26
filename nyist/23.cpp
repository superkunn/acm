#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x%(y+1)==0)puts("Lose");
        else puts("Win");
    }
    return 0;
}
