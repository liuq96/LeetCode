//
// Created by 刘强 on 2018/6/2.
//
#include <vector>
using std::vector;

class SpiralMatrix2 {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int row_begin = 0, row_end = n-1;
        int col_begin = 0, col_end = n-1;
        int nums = 1;
        while (row_begin <= row_end && col_begin <= col_end) {
            for (int j = col_begin; j <= col_end; j ++) {
                v[row_begin][j] = nums ++;
            }
            row_begin ++;
            for (int i = row_begin; i <= row_end; i ++) {
                v[i][col_end] = nums ++;
            }
            col_end --;
            if (col_begin <= col_end) {
                for (int j = col_end; j >= col_begin; j --) {
                    v[row_end][j] = nums ++;
                }
            }
            row_end --;
            if (row_begin <= row_end) {
                for (int i = row_end; i >= row_begin; i --) {
                    v[i][col_begin] = nums ++;
                }
            }
            col_begin ++;
        }
        return v;
    }
};
