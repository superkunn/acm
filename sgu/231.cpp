#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+10;
bool not_prime[MAXN];
int main(){
    int n;
    not_prime[0]=not_prime[1]=true;
    scanf("%d",&n);
    for(int i=2;i*i<=n;i++){
        if(!not_prime[i]){
            for(int j=2*i;j<=n;j+=i){
                not_prime[j]=true;
            }
        }
    }
    queue<int>que;
    for(int i=1;i+2<=n;i++){
        if(!not_prime[i]&&!not_prime[i+2]){
            que.push(i);
        }
    }
    printf("%d\n",que.size());
    while(!que.empty()){
        printf("2 %d\n",que.front());
        que.pop();
    }
    return 0;
}
