//
// Created by 刘强 on 2018/6/6.
//
#include <vector>
using std::vector;

class Subsets {
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> result;
        if (nums.empty()) return result;
        vector<int>cur;
        generate_set(result, nums, cur, 0);
        return result;
    }

private:
    void generate_set(vector<vector<int>> &result, vector<int>& nums,
                      vector<int>& cur, int begin) {
        if (cur.size() <= nums.size()) result.push_back(cur);
        for (int i = begin; i < nums.size(); ++i) {
            cur.push_back(nums[i]);
            generate_set(result, nums, cur, i + 1);
            cur.pop_back();
        }
    }
};
