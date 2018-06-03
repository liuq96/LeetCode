//
// Created by 刘强 on 2018/6/2.
//
#include <vector>
#include <iostream>
using std::cout;
using std::vector;

class SpiralMatrix {
public:
    /**
     * 该方法首先计算可以形成一个环形的次数，然后进行遍历输出
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        if (matrix.empty() || matrix[0].empty())
            return v;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int times = std::min((rows + 1) / 2, (cols + 1) / 2);
        for (int t = 0; t < times; ++t) {
            int row_st = t, row_ed = rows - 1 - t;
            int col_st = t, col_ed = cols - 1 - t;
            for (int i = col_st; i <= col_ed; i ++) {
                v.push_back(matrix[row_st][i]);
            }
            for (int i = row_st + 1; i <= row_ed-1; ++i) {
                v.push_back(matrix[i][col_ed]);
            }
            //注意上下重叠的情况
            if (row_st != row_ed) {
                for (int i = col_ed; i >= col_st ; i --) {
                    v.push_back(matrix[row_ed][i]);
                }
            }
            //注意左右重叠的情况
            if (col_st != col_ed) {
                for (int i = row_ed - 1; i >= row_st + 1; i --) {
                    v.push_back(matrix[i][col_st]);
                }
            }
        }
        return v;
    }

    vector<int> spiralOrder2(vector<vector<int>> matrix) {
        vector<int> v;
        if (matrix.empty() || matrix[0].empty())
            return v;
        int row_begin = 0, row_end = matrix.size() - 1;
        int col_begin = 0, col_end = matrix[0].size() - 1;
        while (row_begin <= row_end && col_begin <= col_end) {
            for (int j = col_begin; j <= col_end; j ++) {
                v.push_back(matrix[row_begin][j]);
            }
            row_begin ++;
            for (int i = row_begin; i <= row_end; i ++) {
                v.push_back(matrix[i][col_end]);
            }
            col_end --;
            if (row_begin <= row_end) {
                for (int j = col_end; j >= col_begin; j --){
                    v.push_back(matrix[row_end][j]);
                }
            }
            row_end --;
            if (col_begin <= col_end) {
                for (int i = row_end; i >= row_begin; i --){
                    v.push_back(matrix[i][col_begin]);
                }
            }
            col_begin ++;
        }
        return v;
    }
};

int main_spiral(){
    SpiralMatrix matrix;
    vector<vector<int>>m;
    m.push_back(vector<int>{7});
    m.push_back(vector<int>{9});
    m.push_back(vector<int>{6});
    vector<int> result = matrix.spiralOrder2(m);
    for (auto val : result)
        cout << val << " ";
    return 0;
}
