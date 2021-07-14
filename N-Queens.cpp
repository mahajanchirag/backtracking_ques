class Solution {
public:
    
    
    bool valid(vector<int> &left,vector<int> &upDiag,vector<int> &lowDiag,int col,int row,int n)
    {
        if(left[row]==1 || lowDiag[row+col]==1 || upDiag[n-1+col-row]==1)
        {
            return false;
        }
        
        return true;
    }
    
    
    void solve(vector<vector<string>> &ans,
                                 vector<string> &grid,vector<int> &left,
                                 vector<int> &upDiag,vector<int> &lowDiag,int col,int n)
    {
        if(col==n)
        {
            ans.push_back(grid);
            return ;
        }
        
        for(int row=0;row<n;row++)
        {
            if(valid(left,upDiag,lowDiag,col,row,n))
            {
                grid[row][col]='Q';
                left[row]=1;
                lowDiag[row+col]=1;
                upDiag[n-1+col-row]=1;
                solve(ans,grid,left,upDiag,lowDiag,col+1,n);
                grid[row][col]='.';
                left[row]=0;
                lowDiag[row+col]=0;
                upDiag[n-1+col-row]=0;
                
                
            }
        }
        
        
        
        
        
    }
    
    
    
    
    
    
    
    
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ans;
        vector<string> grid(n,string(n,'.'));
        
        vector<int> left(n,0),upDiag(2*n-1,0),lowDiag(2*n-1,0);
        solve(ans,grid,left,upDiag,lowDiag,0,n);
        return ans;
    }
};
