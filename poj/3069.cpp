#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[1005];
int main(){
    int r,n;
    while(~scanf("%d%d",&r,&n)){
        if(r==-1&&n==-1)break;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        sort(a+1,a+1+n);
        int ans=0;
        int f=0;
        int x;
        for(int i=1;i<=n;i++){
            if(f==0){
                f=1;
                ans++;
                x=a[i];
            }
            else if(f==1){
                if(x+r>=a[i])continue;
                if(a[i-1]+r>=a[i]){
                    x=a[i-1];
                    f=2;
                }
                else{
                    x=a[i];
                    ans++;
                    f=1;
                }
            }
            else{
                if(x+r>=a[i])continue;
                f=1;
                x=a[i];
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
