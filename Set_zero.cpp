#include <iostream>
void set(int a[][10], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0)
			{
				a[i][0] = 0;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i][0] == 0)
		{
			for (int j = 1; j < n; j++)
			{
				a[i][j] = 0;
			}
		}
	}
}

int main(){
	int a[10][10], size;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> a[i][j];
		}
	}
	set(a, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << a[i][j] << " ";
		}
		cout<<endl;
	}
	return 0;
}