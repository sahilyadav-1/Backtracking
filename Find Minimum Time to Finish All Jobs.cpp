class Solution {
public:
    
    vector<int> work;
    int ans = INT_MAX;
    
    void solve(vector<int>& jobs, int k, int i){
        if(i == jobs.size()){
            int maxi = *max_element(work.begin(),work.end());
            ans = min(ans,maxi);
            return;
        }
        
        if(*max_element(work.begin(),work.end()) >= ans)
            return;
        
        for(int j = 0; j < k; j++){
            if(j>0 && work[j] >= work[j-1])
                continue;
            work[j] += jobs[i];
            solve(jobs,k,i+1);
            work[j] -= jobs[i];
        }
    }
    
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(),jobs.end(),greater<int>());
        if(k == jobs.size())
            return jobs[0];
        work.resize(k,0);
        solve(jobs,k,0);
        return ans;
    }
};
