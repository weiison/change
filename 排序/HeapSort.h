{最大堆,已排序}
void max_heap(vector<int>& v,int start,int end)//将给定范围内排成最大堆
{	
	int dad=start;
	int son=2*dad+1;
	while(son<=end)
	{
		if(son+1<=end&&v[son]<v[son+1]) 
			++son;
		if(v[dad]>v[son])
			return;//设定子树已经是最大堆，在初始化处完成
		else
		{
			swap(v[dad],v[son]);
			dad=son;
			son=2*dad+1;
		}
	}
}

void heap_sort(vector<int>& v)
{
	int size=v.size();
	for(int i=size>>1-1;i>=0;--i)//初始化，从最后一个dad开始调整为最大堆
		max_heap(v,i,size-1);
	for(int i=size-1;i>0;--i)
	{
		swap(v[0],v[i]);//每次拿出堆顶元素放在已排序的序列头部（与已排好的前一位交换）
		max_heap(v,0,i-1);
	}
}
