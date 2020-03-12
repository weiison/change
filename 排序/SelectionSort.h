//{有序,无序} 每次遍历无序从中选最小的放在有序末尾 放置位置定，找元素
//而插入排序则是遍历有序，插入第一个无序数         放置元素定，找位置
void selectionSort(vector<int>& v)
{
	int size=v.size();
	for(int i=0;i<size;++i)
	{
		int min=i;
		for(int j=i+1;j<size;++j)
		{
			if(v[j]<v[min])
				min=j;
		}
		if(min!=i)
			swap(v[min],v[i]);
	}
}
