//
// Created by 刘强 on 2018/6/5.
//

#include <vector>
using std::vector;

class Solution {
public:
    /**
     * 将矩阵看做为一个排序的vector，然后对其进行二分查找
     * @param matrix
     * @param target
     * @return
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l != r) {
            int mid = (r + l - 1) >> 1;
            if (matrix[mid / n][mid % n] < target)
                l = mid + 1; //注意：此处不能设置为l = mid，否则会陷入死循环
            else
                r = mid;
        }
        return matrix[r / n][r % n] == target;
    }

    bool searchMatrix2(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low = 0;
        int high = rows * cols - 1;
        int mid = 0;
        while (low < high){
            mid = low + ((high - low) >> 1); //避免使用(high+low)/2的方式，因此可能存在溢出的情况
            if (matrix[mid / cols][mid % cols] < target) low = mid + 1; //对low进行处理
            else high = mid;
        }
        return matrix[low / cols][low % cols] == target;//因此这里使用的应该也是low
    }
};