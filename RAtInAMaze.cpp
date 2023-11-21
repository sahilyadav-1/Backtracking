bool isSafe(int newx, int newy, vector<vector<int>> &arr, int n,                               vector<vector<bool>> &visited){
    
    if((newx>=0 && newx<n) && (newy>=0 && newy<n) && 
       visited[newx][newy]!=1 && arr[newx][newy] == 1){
        return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans,
           string output, vector<vector<bool>> &visited){
    
    if(x == n-1 && y == n-1){
        ans.push_back(output);
        return;
    }
    
    visited[x][y] = 1;
    
    //DOWN
    
    if(isSafe(x+1,y,arr,n,visited)){
        solve(x+1,y,arr,n,ans,output+'D',visited);
    }
    
    //LEFT
    
    if(isSafe(x,y-1,arr,n,visited)){
        solve(x,y-1,arr,n,ans,output+'L',visited);
    }
    
    //RIGHT
    
    if(isSafe(x,y+1,arr,n,visited)){
        solve(x,y+1,arr,n,ans,output+'R',visited);
    }
    
    //UP
    
    if(isSafe(x-1,y,arr,n,visited)){
        solve(x-1,y,arr,n,ans,output+'U',visited);
    }
    visited[x][y] = 0;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    string output;
    vector<vector<bool>> visited(n,vector<bool>(n,0));  
    if(arr[0][0] == 0)
        return ans;
    solve(0,0,arr,n,ans,output,visited);
    return ans;
}
