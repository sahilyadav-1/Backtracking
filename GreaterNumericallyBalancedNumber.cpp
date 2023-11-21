class Solution {
public:
    vector<string> ans;
    void solve(string nums, int i){
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int j = i; j < nums.size(); j++){
            swap(nums[i],nums[j]);
            solve(nums,i+1);
            swap(nums[i],nums[j]);
        }
    }
    
    int nextBeautifulNumber(int n) {
        vector<string>nums{"1","22","122","333","1333","4444","14444","22333","55555","122333","155555","224444","666666","1224444"};
        
        for(int i = 0; i < nums.size(); i++){
            solve(nums[i],0);
        }
        
        set<int> a;
        for(string x:ans){
            if(x!=""){
                int y = stoi(x);
                a.insert(y);
            }
        }
        
        auto it = upper_bound(a.begin(),a.end(),n);
        int res = *it;
        return res;
    }
};
