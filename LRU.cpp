#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int lru(int page[], int n, int frame)
{
    unordered_set<int> s;
    unordered_map<int, int> indexes;
    int faults = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < frame)
        {
            if (s.find(page[i]) == s.end())
            {
                s.insert(page[i]);
                faults++;
            }
            indexes[page[i]] = i;
        }
        else
        {
            if (s.find(page[i]) == s.end())
            {
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                s.erase(val);
                s.insert(page[i]);

                faults++;
            }
            indexes[page[i]] = i;
        }
    }
    return faults;
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
    faults = lru(page, n, frame);
    hit = n - faults;
    cout << "No of page faults: " << faults << endl;
    cout << "No of hits: " << hit << endl;
    cout << "Hit Ratio: " << (hit / float(n)) * 100 << "%";

    return 0;
}