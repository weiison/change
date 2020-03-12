//大的数字往下沉，标志位为真表示该次循环有序（未发生交换）
void bubbleSort(vector<int>& v)
{ 
    int size=v.size();
    bool flag=false;
    for(int i=0;i<size-1&&!flag;++i)
    {
        flag=true;
        for(int j=0;j<size-1-i;++j)
          if(v[j]>v[j+1])
          {
            flag=false;
            swap(v[j],v[j+1]);
          }
    }
          
}
