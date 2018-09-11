#include<bits/stdc++.h>
using namespace std;
int vis[10];
char s1[10],s2[10];
int main(){
    scanf("%s%s",s1,s2);
    for(int i=0;i<4;i++){
        vis[s1[i]-'0']=1;
    }
    int ans1=0,ans2=0;
    for(int i=0;i<4;i++){
        if(s1[i]==s2[i])ans1++;
        else if(vis[s2[i]-'0'])ans2++;
    }
    printf("%d %d",ans1,ans2);
    return 0;
}
