//
// Created by 刘强 on 2018/6/1.
//
#include <vector>
#include <queue>
using std::vector;
using std::queue;

class JumpGame2 {
public:
    /**
     * 贪心策略：尽量走到最大步数才增加步数，保证局部最优解，从而获得全局最优解
     */
    int jump2(vector<int>& nums){
        int n = nums.size(), max = 0;
        int steps = 0;
        int tmpMax = 0;
        for (int i = 0; i < n-1; ++i) {
            tmpMax = std::max(tmpMax, i + nums[i]);
            if (i == max) { //当到达之前可以达到的最远位置，则步数增加，并更新最远位置
                steps ++;
                max = tmpMax;
            }
        }
        return steps;
    }

    /**
     * 使用暴力搜索+剪支的方法，但还是会超时
     * @param nums
     * @return
     */
    int jump(vector<int>& nums) {
        int n = nums.size();
        Point begin(n-1, 0);
        queue<Point> q;
        q.push(begin);
        int times = INF;
        vector<int> vis(n, 0);
        vis[n-1] = 1;
        while (!q.empty()){
            Point p = q.front();
            q.pop();
            if (p.pos == 0) {
                times = std::min(times, p.times);
            }
            for (int i = 0; i < p.pos; ++i) {
                if (i + nums[i] >= p.pos && !vis[i]) {
                    q.push(Point(i, p.times+1));
                    vis[i] = 1;
                }
            }
        }
        return times;
    }

private:
    int INF = 100001;

    struct Point {
        Point(int pos, int times) {
            this->pos = pos;
            this->times = times;
        }

        int pos;
        int times;
    };
};