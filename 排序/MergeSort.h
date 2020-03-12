void mergeCore(vector<int>& v, vector<int>& copy, int start, int end)
{
	if (start >= end) return;
	int mid = start + ((end - start) >> 1);
	mergeCore(v, copy,start, mid);
	mergeCore(v, copy,mid + 1, end);
	int i = start, j = mid + 1;
	int k = start;
	while (i <= mid&&j <= end)
		copy[k++] = v[i] < v[j] ? v[i++] : v[j++];
	while (i <= mid)
		copy[k++] = v[i++];
	while (j <= end)
		copy[k++] = v[j++];
	for (k = start; k <= end; k++)
		v[k] = copy[k];
}

void mergeSort(vector<int>& v)
{
	int size = v.size();
	vector<int> copy(size);
	mergeCore(v,copy, 0, size - 1);
}
    
