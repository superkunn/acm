//Julyed
#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",(a+b-1)/b);
    }
    return 0;
}
