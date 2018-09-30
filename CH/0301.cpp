#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<(1<<n);i++){
        bool f=true;
        for(int j=0;j<n;j++){
            if(i>>j&1){
                if(f){
                    printf("%d",j+1);
                    f=false;
                }else{
                    printf(" %d",j+1);
                }
            }
        }
        puts("");
    }
    return 0;
}
