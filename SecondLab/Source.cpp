#include <iostream>
#include <time.h>
#include <chrono>
#include <cmath>

using namespace std;

const short N = 100;
int basicArray[N];
int sortedArray[N];
int idzArray[N];

int maxElem(int arr[])
{
	int max = arr[0];
	for (int i = 1; i < N; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

int minElem(int arr[])
{
	int min = arr[0];
	for (int i = 1; i < N; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}

void quickSort(int arr[], short left, short right)
{
	short mid;
	short l = left;
	short r = right;
	mid = arr[(l + r) / 2];
	while (l < r)
	{
		while (arr[l] < mid)
			l++;
		while (arr[r] > mid)
			r--;
		if (l <= r)
		{
			swap(arr[l], arr[r]);
			l++;
			r--;
		}
	}
	if (left < r)
		quickSort(arr, left, r);
	if (right > l)
		quickSort(arr, l, right);
}

void shellSort(int arr[], short n)
{
	int i, j, d;
	d = n / 2;
	while (d > 0)
	{
		for (i = 0; i < n - d; i++)
		{
			j = i;
			while ((j >= 0) && (arr[j] > arr[j + d]))
			{
				swap(arr[j], arr[j + d]);
				j--;
			}
		}
		d /= 2;
	}
}

short binarySearch(int arr[], short value, short start, short end)
{
	short mid;
	if (end >= start)
	{
		mid = (start + end) / 2;
		if (arr[mid] == value)
		{
			return mid;
		}
		if (arr[mid] > value)
		{
			return binarySearch(arr, value, start, mid - 1);
		}
		return binarySearch(arr, value, mid + 1, end);
	}
	return -1;
}

void task1()
{
	srand(time(NULL));
	int start = -99;
	int end = 99;
	for (int i = 0; i < N; i++)
	{
		basicArray[i] = rand() % (end - start + 1) + start;
		sortedArray[i] = basicArray[i];
		idzArray[i] = basicArray[i];
	}
}

void task2()
{
	auto clockStart = chrono::high_resolution_clock::now();
	quickSort(sortedArray, 0, N - 1);
	auto clockStop = chrono::high_resolution_clock::now();
	cout << "����� quick sort: " << (chrono::duration_cast<chrono::nanoseconds>(clockStop - clockStart).count()) << " ����������\n";

	clockStart = chrono::high_resolution_clock::now();
	shellSort(idzArray, N);
	clockStop = chrono::high_resolution_clock::now();
	cout << "����� Shell sort: " << (chrono::duration_cast<chrono::nanoseconds>(clockStop - clockStart).count()) << " ����������";
}

void task3()
{
	auto clockStart = chrono::steady_clock::now();
	int minValue = sortedArray[0];
	int maxValue = sortedArray[N - 1];
	auto clockStop = chrono::steady_clock::now();
	cout << "������������ �������: " << maxValue << '\n' << "����������� �������: " << minValue <<'\n';
	cout << "����� (sorted): " << (chrono::duration_cast<chrono::nanoseconds>(clockStop - clockStart).count()) << " ����������";
	
	cout << '\n';

	clockStart = chrono::steady_clock::now();
	minValue = minElem(basicArray);
	maxValue = maxElem(basicArray);
	clockStop = chrono::steady_clock::now();
	cout << "������������ �������: " << maxValue << '\n' << "����������� �������: " << minValue << '\n';
	cout << "����� (unsorted): " << (chrono::duration_cast<chrono::nanoseconds>(clockStop - clockStart).count()) << " ����������";
}

void task4()
{
	auto clockStart = chrono::steady_clock::now();
	int average = round((float)(sortedArray[0] + sortedArray[N - 1]) / 2);
	short count = 0;
	short i = 0;
	cout << "������� �������� ������������� � ������������ ���������:" << average << '\n';
	cout << "������� ���������, ������ ����������� ��������:";
	while (sortedArray[i] <= average)
	{
		if (sortedArray[i] == average)
		{
			count++;
			cout << i << " ";
		}
		i++;
	}
	auto clockStop = chrono::steady_clock::now();
	if (!count)
	{
		cout << "����� ��������� �� �������";
	}
	else
	{
		cout << "����� ������� " << count << " ����� ���������";
	}
	cout << '\n';
	cout << "�����: " << (chrono::duration_cast<chrono::nanoseconds>(clockStop - clockStart).count()) << " ����������";

	cout << '\n';

	clockStart = chrono::steady_clock::now();
	average = round((float)(maxElem(basicArray) + minElem(basicArray)) / 2);
	count = 0;
	cout << "������� �������� ������������� � ������������ ���������:" << average << '\n';
	cout << "������� ���������, ������ ����������� ��������:";
	for (int j = 0; j < N; j++)
	{
		if (basicArray[j] == average)
		{
			count++;
			cout << j << " ";
		}
	}
	clockStop = chrono::steady_clock::now();
	if (!count)
	{
		cout << "����� ��������� �� �������";
	}
	else
	{
		cout << "����� ������� " << count << " ����� ���������";
	}
	cout << '\n';
	cout << "�����: " << (chrono::duration_cast<chrono::nanoseconds>(clockStop - clockStart).count()) << " ����������";
}

void task5()
{
	short a;
	cout << "������� ����� �����" << '\n';
	cin >> a;
	short i = 0;
	while ((sortedArray[i] < a) && (i < N))
	{
		i++;
	}
	cout << "���������� ���������, ������� ���������� �����: " << i;
}

void task6()
{
	short a;
	cout << "������� ����� �����" << '\n';
	cin >> a;
	short i = N - 1;
	while ((sortedArray[i] > a) && (i >= 0))
	{
		i--;
	}
	cout << "���������� ���������, ������� ���������� �����: " << N - 1 - i;
}

void task7()
{
	short c;
	short value;
	cout << "������� �����, ������� ������ �����" << '\n';
	cin >> value;
	auto clockStart = chrono::steady_clock::now();
	c = binarySearch(sortedArray, value, 0, N - 1);
	if (c == -1)
	{
		cout << "������ ����� ��� � �������";
	}
	else
	{
		cout << "���� ����� �������, ��� ��� ������: " << c;
	}
	auto clockStop = chrono::steady_clock::now();
	cout << '\n';
	cout << "�����: " << (chrono::duration_cast<chrono::nanoseconds>(clockStop - clockStart).count()) << " ����������";

	cout << '\n';

	clockStart = chrono::steady_clock::now();
	short i;
	for (i = 0; i < N; i++)
	{
		if (sortedArray[i] == value)
		{
			cout << "���� ����� �������, ��� ��� ������: " << i;
			i = N + 1;
		}
	}
	if (i == N)
	{
		cout << "������ ����� ��� � �������";
	}
	clockStop = chrono::steady_clock::now();
	cout << '\n';
	cout << "�����: " << (chrono::duration_cast<chrono::nanoseconds>(clockStop - clockStart).count()) << " ����������";
}

void task8()
{
	short x, y;
	cout << "������� ������� ��������� (����� �� 0 �� 99), ������� ������ �������� �������" << '\n';
	cin >> x >> y;
	auto clockStart = chrono::steady_clock::now();
	if ((x >= N) || (y >= N) || (x < 0) || (y < 0))
	{
		cout << "� ���������, ���� ����� �� �������� ��������� �������, ���������� ��� ���";
	}
	cout << "X = " << sortedArray[x] << " Y = " << sortedArray[y] << " ������ �������..." << '\n';
	int t;
	t = sortedArray[x];
	sortedArray[x] = sortedArray[y];
	sortedArray[y] = t;
	cout << "X = " << sortedArray[x] << " Y = " << sortedArray[y] << '\n';

	auto clockStop = chrono::steady_clock::now();
	cout << '\n';
	cout << "�����: " << (chrono::duration_cast<chrono::nanoseconds>(clockStop - clockStart).count()) << " ����������";
}

int main()
{
	setlocale(0, "");
	while (true)
	{
		short menu;
		cout << "\n 1. Task 1\n 2. Task 2\n 3. Task 3\n 4. Task 4\n 5. Task 5\n 6. Task 6\n 7. Task 7\n 8. Task 8\n 0. Exit\n";
		cin >> menu;
		switch (menu)
		{
		case(1):
			task1();
			cout << "������ ������� ���������, ������������ � ����.\n";
			break;
		case(2):
			task2();
			break;
		case(3):
			task3();
			break;
		case(4):
			task4();
			break;
		case(5):
			task5();
			break;
		case(6):
			task6();
			break;
		case(7):
			task7();
			break;
		case(8):
			task8();
			break;
		default:
			cout << "����� �� ���������...";
			exit(0);
		}
	}
	return 0;
}