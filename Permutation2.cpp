class Solution {
public:
    
    void solve(vector<int> &nums, int i, vector<vector<int>> &ans){
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_set<int> a;
        for(int j = i; j < nums.size(); j++){
            
            if(a.find(nums[j]) != a.end()) continue;
                a.insert(nums[j]);
                swap(nums[i],nums[j]);
                solve(nums,i+1,ans);
                swap(nums[i],nums[j]);           
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        solve(nums,0,ans);
        
        return ans;
    }
};
