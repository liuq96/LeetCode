//
// Created by 刘强 on 2018/6/5.
//
#include <vector>
#include <set>
using std::set;
using std::vector;

class SetMatrixZeroes {
public:
    /**
     * 使用set容器来记录零行列
     */
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        int rows = matrix.size();
        int cols = matrix[0].size();
        set<int> row_set;
        set<int> col_set;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (matrix[i][j] == 0) {
                    row_set.insert(i);
                    col_set.insert(j);
                }
        for (auto i : row_set)
            for (int j = 0; j < cols; ++j)
                matrix[i][j] = 0;

        for (auto j : col_set)
            for (int i = 0; i < rows; i ++)
                matrix[i][j] = 0;
    }

    /**
     * 空间复杂度为O(1)的方法
     * @param matrix
     */
    void setZeroes2(vector< vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int last_zero_row = -1;
        //从最后一行自下而上找存在零元素的行
        for (int i = rows - 1; i >= 0 && last_zero_row == -1; i --)
            for (int j = 0; j < cols; ++j)
                if (matrix[i][j] == 0) {
                    last_zero_row = i;
                    break;
                }
        //不存在零元素，则直接返回即可
        if (last_zero_row == -1) return;

        for (int i = 0; i < last_zero_row; ++i) {
            bool this_row_is_zero = false;
            for (int j = 0; j < cols; ++j)
                if (matrix[i][j] == 0) {
                    this_row_is_zero = true;
                    //用存在零元素的最后一行来存储列
                    matrix[last_zero_row][j] = 0;
                }
            if (this_row_is_zero) {
                for (int j = 0; j < cols; ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        //对列数进行处理
        for (int j = 0; j < cols; ++j) {
            if (matrix[last_zero_row][j] == 0) {
                for (int i = 0; i < rows; ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        //对最后一行零元素处理
        for (int j = 0; j < cols; ++j) {
            matrix[last_zero_row][j] = 0;
        }
    }
};
