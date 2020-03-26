class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> index;
        if(nums.size()==0) return res;
        for(int i=0;i<k;++i)
        {
            while(!index.empty()&&nums[i]>nums[index.back()])
                index.pop_back();//每次插入一个数字下标到队列来，确保在它前面比他小的都出队
            index.push_back(i);
        }
        for(int i=k;i<nums.size();++i)
        {
            res.push_back(nums[index.front()]);//放入窗口滑动前的最大值
            if(!index.empty()&&i-index.front()>=k)
                index.pop_front();//队首元素已经不在窗口内
            while(!index.empty()&&nums[i]>nums[index.back()])
                index.pop_back();//每次插入一个数字下标到队列来，确保在它前面比他小的都出队
            index.push_back(i);
        }
        res.push_back(nums[index.front()]);
        return res;
    }
};
