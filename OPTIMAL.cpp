#include <iostream>

#include <vector>
#include <algorithm>
using namespace std;

int predict(int page[], vector<int> &v, int n, int index)
{
    int res = -1, farthest = index;
    for (int i = 0; i < v.size(); i++)
    {
        int j;
        for (j = index; j < n; j++)
        {
            if (v[i] == page[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        if (j == n)
            return i;
    }

    return (res == -1) ? 0 : res;
}
int optimal(int page[], int n, int frame)
{
    vector<int> v;
    int hit = 0;
    for (int i = 0; i < n; i++)
    {
        if (find(v.begin(), v.end(), page[i]) != v.end())
        {

            hit++;
            continue;
        }

        if (v.size() < frame)
        {
            v.push_back(page[i]);
        }
        else
        {
            int j = predict(page, v, n, i + 1);
            v[j] = page[i];
        }
    }
    return hit;
}
int main()
{
    int n;
    cout << "Enter number of pages: " << endl;
    cin >> n;
    int page[n];
    cout << "Enter all pages: " << endl;
    for (int i = 0; i < n; i++)
        cin >> page[i];
    int frame;
    cout << "Enter total number of frames: " << endl;
    cin >> frame;
    int faults, hit;
    hit = optimal(page, n, frame);
    faults = n - hit;
    cout << "No of page faults: " << faults << endl;
    cout << "No of hits: " << hit << endl;
    cout << "Hit Ratio: " << (hit / float(n)) * 100 << "%";

    return 0;
}