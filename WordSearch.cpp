class Solution {
public:
    
    bool solve(vector<vector<char>>& board, int i, int j, int k, string& word){
        if((i<0 || i>=board.size()) || (j<0 || j>=board[0].size()) || (board[i][j] != word[k]) || 
        (board[i][j] == '*' )){ 
            return false;
        }
        
        if(k==word.length()-1)
            return true;
        
        char ch = board[i][j];
        
        board[i][j] = '*';
        
        bool left = solve(board,i,j-1,k+1,word);
            
        bool right = solve(board,i,j+1,k+1,word);
            
        bool up = solve(board,i-1,j,k+1,word);
            
        bool down = solve(board,i+1,j,k+1,word);
        
        board[i][j] = ch;
        
        return left || right || up || down;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(solve(board,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};
