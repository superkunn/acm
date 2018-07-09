#include <cstdio>
#include <iostream>
using namespace std;
int a[2005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        getchar();
        scanf("%c",&a[i]);
    }
    int l=1,r=n;
    int num=0;
    while(l<=r){
        bool f=0;
        for(int i=0;l+i<=r;i++){
            if(a[i+l]<a[r-i]){
                printf("%c",a[l]);
                num++;
                if(num==80){
                    printf("\n");
                    num=0;
                }
                l++;
                f=1;
                break;
            }
            else if(a[i+l]>a[r-i]){
                printf("%c",a[r]);
                num++;
                if(num==80){
                    printf("\n");
                    num=0;
                }
                r--;
                f=1;
                break;
            }
        }
        if(f)continue;
        printf("%c",a[l]);
        num++;
        if(num==80){
            printf("\n");
            num=0;
        }
        l++;
    }
    return 0;
}
