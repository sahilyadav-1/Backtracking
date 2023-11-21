class Solution {
public:
    
    void solve(vector<int>& candidates, int target, vector<vector<int>> &ans,vector<int> &temp, int i){
        if(target < 0 ) return;
        
        if(target == 0){ 
            ans.push_back(temp);
            return;
        }
        
        for(int j = i; j< candidates.size();j++){
            if(candidates[j]>target)
            break;
            temp.push_back(candidates[j]);
            solve(candidates,target-candidates[j],ans,temp,j);
            temp.pop_back();
        } 
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,ans,temp,0);
        return ans;
    }
};
