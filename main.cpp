#include<iostream>
using namespace std;

#define delimiter "\n----------------------------------\n"

void FillRand(int** Arr, const int m, const int n);
void Print(int** Arr, const int m, const int n);

void Push_row_back(int **& Arr, int& m, const int n);
void Push_row_front(int **& Arr, int& m, const int n);
void Insert_row(int **& Arr, int& m, const int n, int index);
void Pop_row_back(int **& Arr, int& m, const int n);
void Pop_row_front(int **& Arr, int& m, const int n);
void Erase_row(int **& Arr, int& m, const int n, int index);

void Push_col_back(int** Arr, const int m, int& n);
void Push_col_front(int** Arr, const int m, int& n);
void Insert_col(int** Arr, const int m, int& n, int index);
void Pop_col_back(int** Arr, const int m, int& n);
void Pop_col_front(int** Arr, const int m, int& n);
void Erase_col(int** Arr, const int m, int& n, int index);

void main()
{
	setlocale(LC_ALL, "rus");

	// ��������� ������������ ������:
	int m; //���������� ����� ����������� ������;
	int n; //���������� ��������� ������ (��������);
	cout << "������� ���������� �����: "; cin >> m;
	cout << "������� ���������� ��������� ������ (��������): "; cin >> n;
	//	����������� ���:
	//1) ������ ������ ����������:
	int** Arr = new int*[m];
	// 2) �������� ������ ��� ������:
	for (int i = 0; i < m; i++)
	{
		Arr[i] = new int[n];
	}

	// ���������� � ��������� ���:
	FillRand(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Push_row_back(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Push_row_front(Arr, m, n);
	Print(Arr, m, n);

	int index;
	cout << delimiter << endl;
	cout << "....? "; cin >> index;
	Insert_row(Arr, m, n, index);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Pop_row_back(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Pop_row_front(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	cout << "������� ������ ��������� ������: "; cin >> index;
	Erase_row(Arr, m, n, index);
	Print(Arr, m, n);

	cout << delimiter << endl;
	Push_col_back(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Push_col_front(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	cout << "....? "; cin >> index;
	Insert_col(Arr, m, n, index);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Pop_col_back(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Pop_col_front(Arr, m, n);
	Print(Arr, m, n);
	cout << delimiter << endl;
	Erase_col(Arr, m, n, index);
	Print(Arr, m, n);
	//		�������� ���:
	//1) ������� ������:
	for (int i = 0; i < m; i++)
	{
		delete[] Arr[i];
	}
	//2) �������� ������� ����������:
	delete[] Arr;
}

void FillRand(int** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Arr[i][j] = rand() % 100;
		}
	}
}

void Print(int** Arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << Arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void Push_row_back(int **& Arr, int& m, const int n)
{
	int** Buffer = new int*[m + 1];

	for (int i = 0; i < m; i++)
	{
		Buffer[i] = Arr[i];
	}
	delete[]Arr;
	Arr = Buffer;
	Arr[m] = new int[n + 1]{};
	m++;
}

void Push_row_front(int **& Arr, int& m, const int n)
{
	int** Buffer = new int*[m + 1];

	for (int i = 0; i < m; i++)
	{
		Buffer[i + 1] = Arr[i];
	}
	delete[]Arr;
	Arr = Buffer;
	Arr[0] = new int[n] {};
	m++;
}
void Insert_row(int **& Arr, int& m, const int n, int index)
{
	int** Buffer = new int*[m + 1];

	for (int i = 0; i < index; i++)
	{
		Buffer[i] = Arr[i];
	}
	for (int i = index; i < m; i++)
	{
		Buffer[i + 1] = Arr[i];
	}
	delete[]Arr;
	Arr = Buffer;
	Arr[index] = new int[n] {};
	m++;
}

void Pop_row_back(int **& Arr, int& m, const int n)
{
	int** Buffer = new int*[--m];
	for (int i = 0; i < m; i++)
	{
		Buffer[i] = Arr[i];
	}
	delete[]Arr;
	Arr = Buffer;
}

void Pop_row_front(int **& Arr, int& m, const int n)
{
	int** Buffer = new int*[--m];

	for (int i = 0; i < m; i++)
	{
		Buffer[i] = Arr[i + 1];
	}
	delete[]Arr;
	Arr = Buffer;
}

void Erase_row(int **& Arr, int& m, const int n, int index)
{
	int** Buffer = new int*[--m];
	for (int i = 0; i < index; i++)
	{
		Buffer[i] = Arr[i];
	}
	for (int i = index; i < m; i++)
	{
		Buffer[i] = Arr[i + 1];
	}
	delete[]Arr;
	Arr = Buffer;
}

void Push_col_back(int** Arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			Buffer[j] = Arr[i][j];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n++;
	//return Arr;
}

void Push_col_front(int** Arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n + 1]{};
		for (int j = 0; j < n; j++)
		{
			Buffer[j + 1] = Arr[i][j];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n++;
	//return Arr;
}
void Insert_col(int** Arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n + 1]{};
		for (int j = 0; j < index; j++)
		{
			Buffer[j] = Arr[i][j];
		}
		for (int j = index; j < n; j++)
		{
			Buffer[j + 1] = Arr[i][j];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n++;
	//return Arr;
}
void Pop_col_back(int** Arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int[n] {};
		for (int j = 0; j < n; j++)
		{
			Buffer[j] = Arr[i][j];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n--;
}
void Pop_col_front(int** Arr, const int m, int& n)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int [n] {};
		for (int j = 0; j < n; j++)
		{
			Buffer[j] = Arr[i][j + 1];
		}
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	n--;

}
void Erase_col(int** Arr, const int m, int& n, int index)
{
	for (int i = 0; i < m; i++)
	{
		int* Buffer = new int [n] {};
		for (int j = 0; j < index; j++)
		{
			Buffer[j] = Arr[i][j];
		}
		for (int j = index; j < n; j++)
		{
			Buffer[j] = Arr[i][j + 1];
		}
	}
	n--;
}