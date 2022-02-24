bool canColor(int node, int col, int color[], bool graph[101][101], int n){
    for(int j=0;j<=n;j++){
        if(graph[node][j] and color[j]==col)
            return false;
    }
    return true;
}

bool func(int node, bool graph[101][101], int n, int m, int color[]){
    if(node==n)
        return true;
    
    for(int col=1;col<=m;col++){
        if(canColor(node,col,color,graph,n)){
            color[node]=col;
            if(func(node+1,graph,n,m,color))
                return true;
            color[node]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    int color[V];
    for(int i=0;i<V;i++)
        color[i]=0;
    
    return func(0,graph,V,m,color);
}
