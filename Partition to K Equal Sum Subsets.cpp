class Solution {
public:
     bool check(int i,vector<int> &visited,vector<int> &subset,vector<int> a,int si,int sum)  
    {
        if(visited[i]==1)
        {
            return false;
        }
        
        if(subset[si]+a[i]>sum)
        {
            return false;
        }
        
        return true;
        
    }
  
    bool solve(vector<int> a,vector<int> &subset,vector<int> &visited,int si,int n,int k,int sum)
    {
        if(subset[si]==sum)
        {
            if(si==k-2)
            {
                return true;
            }
            
            return solve(a,subset,visited,si+1,n,k,sum);
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(check(i,visited,subset,a,si,sum))
            {
                subset[si]=subset[si]+a[i];
                visited[i]=1;
                if(solve(a,subset,visited,si,n,k,sum))
                {
                    return true;
                }
                subset[si]=subset[si]-a[i];
                visited[i]=0;
            }
        }
        
        return false;
    }
    
    bool canPartitionKSubsets(vector<int>& a, int k) 
    {
       
        int n=a.size();
        if(n<k)
         {
             return false; 
         }
         
         
         if(k==1 )
         {
             return true;
         }
         
         int sum=0;
         for(int i=0;i<n;i++)
         {
             sum=sum+a[i];
         }
         
         
         if(sum%k!=0)
         {
             return false;
         }
         
         sum=sum/k;
         
         vector<int> subset(k,0);
         vector<int> visited(n,0);
         
         return solve(a,subset,visited,0,n,k,sum);
         
    }
};
