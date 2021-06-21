#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the number of pages : " << endl;
	cin >> n;

	int page[n];
	cout << "Enter all the pages" << endl;
	for (int i = 0; i < n; i++)
		cin >> page[i];

	int m;
	cout << "Enter total number of frames" << endl;
	cin >> m;
	int frames[m];
	for (int i = 0; i < m; i++)
		frames[i] = INT_MAX;

	int hit = 0;
	int fault = 0;
	int count = 0; //to count number of frames available.

	for (int it = 0; it < m; it++)
		cout << "F" << it << " ";
	cout << "\t"
		 << "PNO"
		 << "\tHit/Miss" << endl;

	bool miss = true;

	for (int i = 0; i < n; i++)
	{
		int nextPage = page
			[i];

		int j;
		for (j = 0; j < count; j++)
		{
			if (frames[j] == nextPage)
				break;
		}

		if (j == count)
		{
			miss = true;
			fault++;
			if (count != m)
			{
				frames[count] = nextPage;
				count++;
			}
			else
			{
				int temp[m] = {}; //to count the frequency
				for (int k = 0; k < m; k++)
				{
					for (int l = i - 1; l >= 0; l--)
					{
						if (page[l] == frames[k])
							temp[k]++;
					}
				}

				int minIndex = -1;
				for (int k = 0; k < m; k++)
				{
					if (temp[k] < temp[minIndex] || minIndex == -1)
						minIndex = k;
				}

				frames[minIndex] = nextPage;
			}
		}
		else
		{
			miss = false;
			hit++;
		}

		for (int it = 0; it < m; it++)
		{
			if (frames[it] != INT_MAX)
				cout << frames[it] << "  ";
			else
				cout << "   ";
		}

		cout << "\t" << nextPage << "\t";
		if (miss)
			cout << "Miss" << endl;
		else
			cout << "Hit" << endl;
	}

	cout << "Number of page hits : " << hit << endl;
	cout << "Number of page faults : " << fault << endl;
	cout << "Hit Ratio: " << (hit / float(n)) * 100 << "%";

	return 0;
}