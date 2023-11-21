class Solution {
public:
    
    vector<string> ans;
    unordered_set<string> set;
    
    
    int countInvalid(string s){
        stack<char> stacks;
        for(int i = 0; i < s.length(); i++){
            if(s[i]=='('){
                stacks.push('(');
            }
            else if(s[i]==')'){
                if(stacks.size()==0){
                    stacks.push(')');
                }
                else if(stacks.top()==')'){
                    stacks.push(')');
                }
                else if(stacks.top()=='('){
                    stacks.pop();
                }
            }
        }
        return stacks.size();
    }
    
    void solve(int invalid, string s){
        
        if(invalid < 0)
            return;
        
        if(invalid == 0){
            int invalidNow = countInvalid(s);
            if(invalidNow == 0){
                ans.push_back(s);
            }
            return;
        }
        
        for(int i = 0; i < s.length(); i++){
            
            if(s[i]!=')' && s[i]!='(')
                continue;
            
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            string res = left+right;
            
            if(set.find(res)==set.end()){
                set.insert(res);
                solve(invalid-1,res);
            }
        }
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int invalid = countInvalid(s);
        solve(invalid,s);
        return ans;
    }
};
