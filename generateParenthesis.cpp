class Solution {
public:
    
    void solve(int currOpen, int currClosed, int remOpen, int remClosed, vector<string> &result, string &ans){
        if(remClosed==0 && remOpen==0){
            cout<< ans<<"  ";
            result.push_back(ans);
            return;
        }
        if(remOpen>0){
            ans.push_back('(');
            solve(currOpen+1,currClosed,remOpen-1,remClosed,result,ans);
            
            ans.pop_back();
        }  
        if(remClosed>0 && currOpen>currClosed){
            ans.push_back(')');
            solve(currOpen,currClosed+1,remOpen,remClosed-1,result,ans);
            
            ans.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
    
        vector<string> result;
        string ans = "(";
        
        solve(1,0,n-1,n,result,ans);
        
        return result;
    }
};
