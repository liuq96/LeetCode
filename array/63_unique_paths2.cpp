//
// Created by 刘强 on 2018/6/3.
//
#include <vector>
#include <queue>
#include <iostream>
using std::pair;
using std::vector;
using std::queue;

class UniquePaths2 {
public:
    /**
     * 对于复杂情况会超时
     * @param obstacleGrid
     * @return
     */
    int uniquePathsWithObstacles(vector<vector<int>> & obstacleGrid) {
        if (obstacleGrid.empty())
            return 0;
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>>vis(rows, vector<int>(cols, 0));
        queue<pair<int,int>> q;
        q.push(pair<int,int>(0,0));
        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            if (!obstacleGrid[row][col]) vis[row][col] ++;
            else continue;
            if (row < rows-1 && col < cols-1){
                if (!vis[row+1][col] && !obstacleGrid[row+1][col]) q.push(pair<int,int>(row+1, col));
                if (!vis[row][col+1] && !obstacleGrid[row][col+1]) q.push(pair<int,int>(row, col+1));
            } else if (row < rows-1) {
                if (!vis[row+1][col] && !obstacleGrid[row+1][col]) q.push(pair<int,int>(row+1, col));
            } else if (col < cols-1) {
                if (!vis[row][col+1] && !obstacleGrid[row][col+1]) q.push(pair<int,int>(row, col+1));
            }
        }
        return vis[rows-1][cols-1];
    }

    int uniquePathsWithObstacles2(vector<vector<int>> & obstacleGrid){
        if (obstacleGrid.empty())
            return 0;
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>>dp(rows+1, vector<int>(cols+1, 0));
        //因为存在[[1][0]]这样的情况，所以设置[0][1]或[1][0]为1，然后根据矩阵情况，来确定第一个位置的值
        dp[0][1] = 1;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (!obstacleGrid[i-1][j-1])
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[rows][cols];
    }
};

