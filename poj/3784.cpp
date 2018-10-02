#include<iostream>
#include<queue>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int kase,n;
        cin>>kase>>n;
        cout<<kase<<" "<<((n+1)>>1)<<'\n';
        priority_queue<int> q1;
        priority_queue<int ,vector<int>,greater<int> > q2;
        vector<int> ans;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(q1.size()<=q2.size()){
                q1.push(x);
            }else{
                q2.push(x);
            }
            if(q1.size()!=0&&q2.size()!=0){
                int x=q1.top();
                int y=q2.top();
                if(x>y){
                    q1.pop();
                    q2.pop();
                    q1.push(y);
                    q2.push(x);
                }
            }
            if(i&1)ans.push_back(q1.top());
        }
        for(int i=0;i<ans.size();i++){
            if(i==ans.size())cout<<ans[i];
            else if(i%10==9){
                cout<<ans[i]<<'\n';
            }else{
                cout<<ans[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
