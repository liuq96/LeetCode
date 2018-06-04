//
// Created by 刘强 on 2018/6/4.
//
#include <vector>
#include <stack>
using std::vector;
using std::stack;

class PlusOne {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.empty())
            return digits;
        bool carry = digits[digits.size()-1] == 9;
        if (!carry) digits[digits.size()-1] = digits[digits.size()-1] + 1;
        else {
            digits[digits.size()-1] = 0;
            bool insert = true;
            for(int i = digits.size()-2;i >= 0;i --){
                if (digits[i] + 1 == 10) {
                    digits[i] = 0;
                } else {
                    digits[i] ++;
                    insert = false;
                    break;
                }
            }
            if (insert) digits.insert(digits.begin(), 1);
        }
        return digits;
    }

    vector<int> plusOne2(vector<int> &digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i --){
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] ++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }

};
