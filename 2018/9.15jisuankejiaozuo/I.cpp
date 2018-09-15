#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    while(~scanf("%d%d%d",&a,&b,&c)){
        bool f=0;
        if(a%2==0||b%2==0||c%2==0)f=1;
        if(f)puts("Yes");
        else puts("No");
    }
    return 0;
}
