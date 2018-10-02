#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    set<pair<int,int>> st;
    int n;
    scanf("%d",&n);
    int x;
    scanf("%d",&x);
    st.insert(make_pair(x,1));
    for(int i=2;i<=n;i++){
        scanf("%d",&x);
        st.insert(make_pair(x,i));
        auto it=st.find(make_pair(x,i));
        int val=1e9,ans,ai=1e9;
        if(it!=st.begin()){
            auto now=it;
            now--;
            ai=now->first;
            val=abs((now->first)-x);
            ans=now->second;
        }
        if(++it!=st.end()){
            int w=abs((it->first)-x);
            if(w==val&&(it->first)<ai){
                ans=it->second;
            }else if(w<val){
                ans=it->second;
                val=w;
            }
        }
        printf("%d %d\n",val,ans);
    }
    return 0;
}
