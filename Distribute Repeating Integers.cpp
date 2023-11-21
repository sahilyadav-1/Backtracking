class Solution {
public:
    
    bool solve(unordered_map<int,int>& m, vector<int>& quantity, int index){
        if(index == quantity.size()){
            return true;
        }
        
        for(auto i:m){
            
            if(i.second>=quantity[index]){
                m[i.first] -= quantity[index];
                if(solve(m,quantity,index+1))
                    return true;
                m[i.first] += quantity[index];
            }
        }
        return false;
    }
    
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        
        sort(quantity.begin(),quantity.end(),greater<int>());
        return solve(m,quantity,0);
    }
};
