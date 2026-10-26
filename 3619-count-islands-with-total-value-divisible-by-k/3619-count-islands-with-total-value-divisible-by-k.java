class Solution {
    int direction[][]={{0,1},{1,0},{-1,0},{0,-1}};
    public int countIslands(int[][] grid, int k) {
        int count=0;
        for (int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]!=0){
                    long sum=bfs(grid,i,j);
                    if(sum%k==0) count++;
                }
            }
        }
        return count;
    }
    private long bfs(int [][]grid,int  i,int j){
        if(i<0||j<0||i>=grid.length||j>=grid[0].length||grid[i][j]==0) return 0;
        long sum=grid[i][j];
        grid[i][j]=0;
        for(int dir[]:direction){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            sum+=bfs(grid,new_i,new_j);
        }
        return sum;
    }
}