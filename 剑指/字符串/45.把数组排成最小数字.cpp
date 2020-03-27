//STL sort() 自定义比较函数排出最小序列
class Solution {
public:
    static bool cmp(string a,string b)
    {
        string s1=to_string(a)+to_string(b);
        string s2=to_string(b)+to_string(a);
        return s1<s2;
    }
    string minNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string res;
        for(int i=0;i<nums.size();++i)
            res+=to_string(nums[i]);
        return res;
    }
};
