#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int fifo(int page[], int n, int frame)
{
    unordered_set<int> s;
    queue<int> q;
    int faults = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < frame)
        {
            if (s.find(page[i]) == s.end())
            {
                s.insert(page[i]);
                faults++;
                q.push(page[i]);
            }
        }
        else
        {
            if (s.find(page[i]) == s.end())
            {
                int val = q.front();
                q.pop();
                s.erase(val);
                s.insert(page[i]);
                q.push(page[i]);
                faults++;
            }
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
    faults = fifo(page, n, frame);
    hit = n - faults;
    cout << "No of page faults: " << faults << endl;
    cout << "No of hits: " << hit << endl;
    cout << "Hit Ratio: " << (hit / float(n)) * 100 << "%";

    return 0;
}