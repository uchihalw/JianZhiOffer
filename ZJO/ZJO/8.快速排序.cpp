/*
 * @file   8.��������.cpp
 * @date   2019.3.12.
 * @author GBW
 * @Description: 
 
 * @Note:
	1.�ؼ���������������ѡ��һ������
	2.�������е����ַ�Ϊ������
	  ��ѡ�������С���Ƶ��������ߣ���ѡ������ִ�������Ƶ�������ұ�
 */
int Partition(int data[], int length, int start, int end)
{
	if (data == NULL || length < 0 || start < 0 || end >= length)
		throw new std::exception("Invalid Parameters");
	int index = RandomInRange(start, end);
	Swap(&data[index], &data[end]);
	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				Swap(&data[index], &data[small);
		}
	}
	++small;
	Swap(&data[small], &data[end]);
	return small;
}
void QuickSort(int data[], int length, int start, int end)
{
	if (start == end)
		return;
	int index = Partition(data, length, start, end);
	if (index > start)
		QuickSort(data, length, start, index - 1);
	if (index < start)
		QuickSort(data, length, index + 1, end);
}

// �Թ�˾����Ա������������
void sortAges(int ages[], int length)
{
	if (ages == nullptr || length <= 0)
		return;

	const int oldOfAge = 99;
	int timeOfAge[oldOfAge + 1];
	for (int i = 0; i <= oldOfAge; ++i)
		timeOfAge[i] = 0;

	for (int i = 0; i < length; ++i)
	{
		int age = ages[i];
		if (age<0 || age > oldOfAge)
			throw new exception("age out of range");
		++timeOfAge[age];
	}
	int index = 0;
	for (int i = 0; i <= oldOfAge; ++i)
	{
		for (int j = 0; j < timeOfAge[i]; ++j)
		{
			ages[index] = i;
			++index;
		}
	}

}


void InsertSort(int* a, int len)//ֱ�Ӳ�������
{
	int temp;
	int i, j;
	for (i = 1; i < len; i++)
	{
		temp = a[i];
		if (a[i - 1] > a[i])
		{
			for (j = i - 1; j >= 0 && a[j] > temp; j--)
			{
				a[j + 1] = a[j];
			}
			a[j + 1] = temp;
		}
	}
}

void Shell(int *a, int len, int d)
{
	int temp;
	int i, j;
	for (i = d; i < len; i++)
	{
		temp = a[i];
		if (a[i - d] > a[i])
		{
			for (j = i - d; j >= 0 && a[j] > temp; j--)
			{
				a[j + d] = a[j];
			}
			a[j + d] = temp;
		}
	}
}

void ShellSort(int *a, int len)//ϣ������
{
	int d[3] = { 5,3,1 };
	int len1 = sizeof(d) / sizeof(int);
	int i;
	for (i = 0; i < len1; i++)
	{
		Shell(a, len, d[i]);
	}
}

void Qsort(int *a, int left, int right)//����
{
	int key = a[left];
	int i = left;
	int j = right;
	if (left < right)
	{
		while (i < j)
		{
			while (i < j&&a[j] >= key)
			{
				j--;
			}
			a[i] = a[j];
			while (i < j&&a[i] <= key)
			{
				i++;
			}
			a[j] = a[i];
		}
		a[j] = key;
		Qsort(a, left, j - 1);
		Qsort(a, j + 1, right);
	}
}

void Adjust(int *a, int root, int len)
{
	int j = 2 * root + 1;
	int key = a[root];
	while (j <= len)
	{
		if (j < len&&a[j] < a[j + 1])
		{
			j++;
		}
		if (key < a[j])
		{
			a[(j - 1) / 2] = a[j];
			j = j * 2 + 1;
		}
		else
		{
			break;
		}
	}
	a[(j - 1) / 2] = key;
}

void Swap(int *a, int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void HeapSort(int *a, int len)//������
{
	int i;
	for (i = (len - 2) / 2; i >= 0; i--)//������  ���㿪ʼ��len/2-1   ��1��ʼ��len/2  
	{
		Adjust(a, i, len - 1);
	}

	for (i = len - 1; i > 0; i--)
	{
		Swap(a, 0, i);
		Adjust(a, 0, i - 1);
	}
}

void Merage(int *a, int first, int mid, int last)
{
	int *temp = (int*)malloc(sizeof(int)*(last - first + 1));
	int i = first;
	int j = mid + 1;
	int k = 0;

	while (i <= mid&&j <= last)
	{
		if (a[i] < a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while (i <= mid)
	{
		temp[k++] = a[i++];
	}
	while (j <= last)
	{
		temp[k++] = a[j++];
	}

	for (i = 0; i < k; i++)
	{
		a[first + i] = temp[i];
	}
	free(temp);
}


void MerageSort(int *a, int first, int last)//2·�鲢����
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		MerageSort(a, first, mid);
		MerageSort(a, mid + 1, last);
		Merage(a, first, mid, last);
	}
}

int DigitalOfMaxNum(int *a, int len)
{
	int max = a[0];
	int i;
	int num = 0;
	for (i = 1; i < len; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	while (max != 0)
	{
		max /= 10;
		num++;
	}
	return num;//a������������ֵ�λ��
}

void Distribute(int *a, int b[][10], int n, int len)
{
	int num = 1;
	int i;
	num = (int)pow(10, n);
	for (i = 0; i < len; i++)
	{
		int temp = a[i] / num % 10;
		b[temp][0]++;  //���Ӧ�������ж��ٸ���
		b[temp][b[temp][0]] = a[i]; //��ÿ������λ����Ӧ�����ִ�ŵ���Ӧ��������ȥ
	}
}

void Collect(int *a, int b[][10])//����λͬ����֮�������ŵ�a������ȥ
{
	int i, j, k = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 1; j <= b[i][0]; j++)
		{
			a[k++] = b[i][j];
		}
	}
}

void RadixSort(int *a, int len)//��������
{

	int digital = DigitalOfMaxNum(a, len);//�������λ��
	int i;
	int b[10][10] = { 0 };
	for (i = 0; i < digital; i++)
	{

		Distribute(a, b, i, len);//������Ͱ��

		Collect(a, b);//�ռ�
		memset(b, 0, sizeof(b));//����������  ���¿�ʼ
	}
}

void PigeonholeSort(int *a, int len)//��z����
{
	int i, j, k = 0;
	int b[10] = { 0 };//a�����е�������Ƕ��٣�b[j]�е�j���Ƕ���
	for (i = 0; i < len; i++)
	{
		b[a[i]]++;
	}
	for (i = 0; i < 10; i++)//�����е�����i��������������ŵ�b[i]�У����һ�δ���a����
	{
		for (j = 0; j < b[i]; j++)
		{
			a[k++] = i;
		}
	}
}
void SelectSort(int *r, int n)
{
	int i, j, k;
	int  x;
	for (i = 0; i <= n - 1; i++)
	{
		k = i;
		for (j = i + 1; j <= n; j++)
			if (r[j] < r[k])
				k = j;
		if (k != i)
		{
			x = r[i];
			r[i] = r[k];
			r[k] = x;
		}
	}

}