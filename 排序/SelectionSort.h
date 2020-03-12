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
