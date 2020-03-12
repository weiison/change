//{有序，无序}把无序第一个插入到有序序列中
void insertSort(vector<int>& v)
{
	int size=v.size();
	for(int i=0;i<size-1;++i)
	{
		for(int j=i;j>=0;--j)
		{
			if(v[j]>v[j+1])
				swap(v[j],v[j+1]);
			else
				break;
		}	
	}
}
