#include<bits/stdc++.h>
using namespace std;
int a[11];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)a[i]=i;
    do{
        for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
    }while(next_permutation(a+1,a+1+n));
    return 0;
}
