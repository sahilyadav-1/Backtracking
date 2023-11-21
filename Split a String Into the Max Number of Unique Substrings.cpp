class Solution {
public:
    
    unordered_set<string> set;
    int ans = 0;
    
    void solve(string s){
        
        if( s.empty() ){
            int len = set.size();
            ans = max(len,ans);
            return;
        }
        
        string str = "";
        for(int i = 0; i < s.length(); i++){
            str = s.substr(0,i+1);
            if(set.find(str)==set.end()){
                set.insert(str);
                solve(s.substr(i+1));
                set.erase(str);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        
        solve(s);
        
        return ans;
    }
};
