class Solution {
public:
    
    void solve(string &tiles, string &output, set<string> &result, map<int,bool> &m){
        
        for(int  i = 0; i < tiles.size(); i++){
            
            if(m[i]==0){
                
                char ch = tiles[i];
                output.push_back(ch);
                m[i]=1;
                
                result.insert(output);
                solve(tiles,output,result,m);
                
                output.pop_back();
                m[i]=0;
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        string output = "";
        set<string> result;
        map<int,bool> m;
        
        solve(tiles,output,result,m);
        return result.size();
    }
};
