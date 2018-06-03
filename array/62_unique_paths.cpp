//
// Created by 刘强 on 2018/6/3.
//
#include <queue>
#include <iostream>
#include <vector>
using std::vector;
using std::queue;
using std::pair;

class UniquePath {
public:
    /**
     * 对于复杂情况，会超时
     * @param m
     * @param n
     * @return
     */
    int uniquePaths(int m, int n){
        queue<int> rq;
        queue<int> cq;
        rq.push(1);
        cq.push(1);
        vector<vector<int>> v(m+1, vector<int>(n+1, 0));
        int paths = 0;
        while (!rq.empty() && !cq.empty()){
            int cur_row = rq.front();
            int cur_col = cq.front();
            rq.pop();
            cq.pop();
            v[cur_row][cur_col] ++;
            if (cur_row < m && cur_col < n) {
                if (!v[cur_row+1][cur_col]) {
                    rq.push(cur_row + 1); cq.push(cur_col);
                }
                if (!v[cur_row][cur_col+1]) {
                    rq.push(cur_row); cq.push(cur_col + 1);
                }
            } else if (cur_row < m) {
                if (!v[cur_row+1][cur_col]) {
                    rq.push(cur_row + 1); cq.push(cur_col);
                }
            } else if (cur_col < n) {
                if (!v[cur_row][cur_col+1]) {
                    rq.push(cur_row); cq.push(cur_col + 1);
                }
            }
        }
        return v[m][n];
    }

    int uniquePaths2(int m, int n){
        vector<vector<int>> paths(m, vector<int>(n, 1));
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                paths[i][j] = paths[i-1][j] + paths[i][j-1];
            }
        }
        return paths[m-1][n-1];
    }
};

int main(){
    UniquePath uniquePath;
    std::cout << uniquePath.uniquePaths2(23, 12) << std::endl;
}