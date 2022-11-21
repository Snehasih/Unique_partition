#include<iostream>
#include<vector>
using namespace std;
class Solution{
    private:
       vector<vector<int>> ans;
    public:
       void solve(int c,int val,vector<int> &temp){
         if(c==0){
            ans.push_back(temp);
            return;
         }
         if(val==0){
            return;
         }
         if(c>=val){
            temp.push_back(val);
            solve(c-val,val,temp);
            temp.pop_back();
         }
         solve(c,val-1,temp);
         
       }
       vector<vector<int>> Unique_partition(int n){
        vector<int> temp;
        solve(n,n,temp);
        return ans;

       }

      
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Solution ob;
        vector<vector<int>>ans=ob.Unique_partition(n);
        for(auto i: ans)
           for(auto j: i)
              cout<<j<<" ";
        cout<<endl;

    }
    return 0;
}