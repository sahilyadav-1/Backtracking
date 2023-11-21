class Solution {
public:
    
    void solve(int &ans, int &mn, int i, vector<int>& toppingCosts, int curr, int target){
        
        if(abs(curr-target)<mn){
            mn = abs(curr-target);
            ans = curr;
        }
        
        if(abs(curr-target) == mn){
            ans = min(ans,curr);
        }
        
        if((curr-target)>mn || i>=toppingCosts.size()){
            return;
        }
        
        solve(ans,mn,i+1,toppingCosts,curr+toppingCosts[i],target);
        
        solve(ans,mn,i+1,toppingCosts,curr+2*toppingCosts[i],target);
        
        solve(ans,mn,i+1,toppingCosts,curr,target);
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans = INT_MAX;
        int mn = INT_MAX;
        for(auto x : baseCosts){
            solve(ans,mn,0,toppingCosts,x,target);
        }
        
        return ans;
    }
};
