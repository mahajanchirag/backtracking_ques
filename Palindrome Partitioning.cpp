class Solution {
public:
    
    void helper(string s,int start,vector<vector<string>> &ans,vector<vector<bool>> &dp,vector<string> &temp)
    {
        if(start>=s.size())
        {
            ans.push_back(temp);
            return;
        }
        
        
        for(int i=start;i<s.size();i++)
        {
            if(dp[start][i]==true)
            {
                temp.push_back(s.substr(start,i+1-start));
                helper(s,i+1,ans,dp,temp);
                temp.pop_back();
            }
        }
        
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<vector<bool>> dp (s.length(), vector <bool> (s.length(), false));
    for (int i = 0; i < s.length(); i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            if (s[i] == s[j] && (i - j < 2 || dp[j + 1][i - 1])) 
            {
                dp[j][i] = true;
            }
        }
    }
        
        
        vector<string> temp;
        helper(s,0,ans,dp,temp);
        return ans;
    }
};
