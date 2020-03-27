class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        for(int i=0;i<popped.size();++i)//对弹出序列遍历
        {
            while(st.empty()||(st.top()!=popped[i]&&j<pushed.size()))//如果栈顶不等于当前出栈数字，若压入序列还有则压入
                st.push(pushed[j++]);
            if(st.top()!=popped[i]) return false;//全部压完还是不等，则错误
            else st.pop();//弹出栈顶进行下一轮
        }
        if(st.empty()) return true;
        else return false;
    }
};
