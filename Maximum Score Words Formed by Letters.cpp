class Solution {
public:
    
    int solve(vector<string>& words, vector<int>& freq, vector<int>& score, int index){
        
        if(index == words.size())
            return 0;
        
        int Exclude = solve(words,freq,score,index+1);
        
        int Include = 0;
        int scoreOfWords = 0;
        bool flag = true;
        
        string word = words[index];
        for(auto i:word){
            
            if(freq[i-'a']==0)
                flag = false;
            freq[i-'a']--;
            scoreOfWords += score[i-'a'];            
        }
        
        if(flag){
            Include = scoreOfWords + solve(words,freq,score,index+1);
        }
        
        for(auto i:word){
            freq[i-'a']++;
        }
        
        return max(Exclude,Include);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26,0);
        
        for(auto i:letters)
            freq[i-'a']++;
        
        return solve(words,freq,score,0);
    }
};
