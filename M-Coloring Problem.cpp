bool valid(bool graph[101][101],int colored[], int c, int V,int node)
{
    for(int i=0;i<V;i++)
    {
        if(i!=node && graph[node][i]==true && colored[i]==c)
        {
            return false;
        }
    }
    
    return true;
}



bool solve(bool graph[101][101],int colored[], int m, int V,int node)
{
    if(node==V)
    {
        return true;
    }
    
    for(int i=1;i<=m;i++)
    {
        if(valid(graph,colored,i,V,node))
        {
            colored[node]=i;
            if(solve(graph,colored,m,V,node+1))
            {
                return true;
            }
            colored[node]=0;
        }
        
    }
    
    return false;
    
}


bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int colored[V]={0};
    return solve(graph,colored,m,V,0);
}
