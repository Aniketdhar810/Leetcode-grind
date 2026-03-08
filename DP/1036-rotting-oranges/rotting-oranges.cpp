class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int dx[]={-1,1,0,0};
        int dy[]={0,0,1,-1};
        int ans=0;
        int fresh=0;
        int rows=grid.size();
        int columns=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        while(!q.empty()){
            if(fresh==0) break;
            ans++;
            int n=q.size();
            for(int i=0;i<n;i++){
                auto [x,y]=q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int newx=x+dx[j];
                    int newy=y+dy[j];
                    if(newx>=0 && newy>=0 && newx<rows && newy<columns && grid[newx][newy]==1){
                        grid[newx][newy]=2;
                        fresh--;
                        q.push({newx,newy});
                    }
                }
            }
        }
        if(fresh) return -1;
        else return ans;
    }
};