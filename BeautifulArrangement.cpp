class Solution {
public:
    
    void permutation(vector<int> &input, int &ans, int index){
        
        if(index == input.size()){
            ans++;
            return;
        }
        
        for(int i = index; i < input.size(); i++){
            
            if(input[i]%(index+1)==0 || (index+1)%input[i]==0){
                swap(input[i],input[index]);
                permutation(input,ans,index+1);
                swap(input[i],input[index]);
            }
        }
    }
    
    int countArrangement(int n) {
        vector<int> input;
        int ans = 0;
        
        for(int i = 1; i <= n; i++){
            input.push_back(i);
        }
        
        permutation(input,ans,0);
        
        return ans;
    }
};
