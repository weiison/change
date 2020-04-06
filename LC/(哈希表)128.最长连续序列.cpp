//[4,99,1,3,2,100]最长连续序列[1,2,3,4]长度4
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size=nums.size();
        if(size==0) return 0;
        unordered_set<int> st(size);
        for(auto n:nums)
        {
            st.insert(n);
        }
        int res=0;
        for(auto n:nums)
        {
            if(st.find(n-1)==st.end())//遍历数组，以当前数字为起点，判断是否可以是起始位置
            {
                int next=n+1;
                int nowSize=1;
                while(st.find(next)!=st.end())//找到终止位置
                {
                    ++nowSize;
                    ++next;
                }
                res=max(res,nowSize);
            }
        }
        return res;
    }
};
