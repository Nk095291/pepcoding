#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int counter = 0;

void printPath(vector<int> &res, vector<int> &s)
{
    queue<pair<int, string>> q;
    q.push(make_pair(res.size() - 1, ""));
    while (q.size() > 0)
    {
        pair<int, string> rem = q.front(); // get
        q.pop();                           // remove
        if (rem.first == 0)                // work
        {
            cout << rem.second << endl;
        }
        else
        {
            for (auto x : s)
                if (rem.first >= x && res[rem.first - x] != 0) // add valid children
                    q.push(make_pair(rem.first - x, rem.second + to_string(x)));
        }
    }
}

void coinchangePer(vector<int> &s, int n)
{
    vector<int> res(n + 1, 0);
    res[0] = 1;
    // array and then set loop
    for (int i = 1; i < res.size(); i++)
    {
        for (auto x : s)
        {
            if (i >= x)
                res[i] += res[i - x];
        }
    }
    for (auto x : res)
        cout << x << " ";
    cout << endl;
    printPath(res, s);
}
void coinchangeComb(vector<int> &s, int n)
{
    vector<int> res(n + 1, 0);
    res[0] = 1;
    // set and then array loop , 2 rise to the power n method
    for (auto x : s)
    {
        for (int i = 1; i < res.size(); i++)
        {
            if (i >= x)
            {
                res[i] += res[i - x];
            }
        }
    }
    for (auto x : res)
        cout << x << " ";
    cout << endl;
}
int main()
{
    vector<int> s{2, 3, 5, 6};
    coinchangeComb(s, 7);
    coinchangePer(s, 7);
}