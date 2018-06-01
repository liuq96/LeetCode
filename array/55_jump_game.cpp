//
// Created by 刘强 on 2018/6/1.
//
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

class JumpGame {
public:
    /**
     * 该方法是通过对特殊元素0进行处理，当元素为0时，向前判断是否可以满足跨过0元素
     */
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1 && nums[0] == 0) return true; //[0]的特殊情况
        if (nums.size() > 1 && nums[0] == 0 ) return false; //[0,1]的特殊情况
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                bool result = false;
                for (int j = 0; j < i; j ++) {
                    if (i == nums.size()-1){
                        if (nums[j] >= (i - j)) {
                            result = true;
                            break;
                        }
                    } else {
                        if (nums[j] > (i - j)){
                            result = true;
                            break;
                        }
                    }
                }
                if (!result) return result;
            }
        }
        return true;
    }

    /**
     * 该方法通过计算可以达到的最远距离，然后与当前位置进行比较
     * @param nums
     * @return
     */
    bool canJump2(vector<int>& nums){
        int n = nums.size(), max = 0;
        for (int i = 0; i < n; ++i) {
            if (i > max) return false;
            max = std::max(max, i + nums[i]);
        }
        return true;
    }
};
