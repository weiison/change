int partition(vector<int>& v,int start,int end)
{
	int small=start-1;
	for(int i=start;i<end;++i)
	{
		if(v[i]<v[end])//以v[end]作为随机选择到的数，进行比较
		{	
			++small;
			if(small!=i) swap(v[small],v[i]);
		}
	}
	++small;
	swap(v[end],v[small]);
	return small;//返回数组左边比v[small]小，右边大
}

void quickSort(vector<int>& v,int start,int end)
{
	if(start==end) return;
	int index=partition(v,start,end);
	if(index>start)
		quicksort(v,start,index-1);
	if(index<end)
		quicksort(v,index+1,end);
}
