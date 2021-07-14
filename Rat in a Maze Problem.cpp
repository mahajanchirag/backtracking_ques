class Solution{
    public:
    void helper(vector<vector<int>> &m, int n,vector<string> &ans,string path,int i,int j)
    {
        if(i<0 || i>=n || j<0 || j>= n || m[i][j]!=1)
        {
            return;
        }
        
        if(i==n-1 && j==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        m[i][j]=-1;
        
        helper(m,n,ans,path+'U',i-1,j);
        helper(m,n,ans,path+'D',i+1,j);
        helper(m,n,ans,path+'L',i,j-1);
        helper(m,n,ans,path+'R',i,j+1);
        
        m[i][j]=1;
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string path="";
        helper(m,n,ans,path,0,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
