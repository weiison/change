//给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。
class Solution {
public:
    int countNum(vector<vector<int>>& matrix,int target)
    {
        int cnt=0;
        int i=matrix.size()-1;
        int j=0;
        while(i>=0&&j<matrix[0].size())
        {
            if(matrix[i][j]<=target)
            {
                cnt+=i+1;
                ++j;
            }
            else --i;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int l=matrix[0][0];
        int r=matrix[rows-1][cols-1];//值域二分，结果一定在这个范围内
        while(l<r)
        {
            int mid=(l+r)>>1;
            if(countNum(matrix,mid)<k)//矩阵中小于等于mid的数字不到k，则结果一定在mid+1后的值
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return l;
    }
};
