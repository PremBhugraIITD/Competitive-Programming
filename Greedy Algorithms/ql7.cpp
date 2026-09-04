#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
#include <iomanip>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define ll long long int
#define ld long double
#define vll vector<long long int>
#define vpll vector<pair<long long int, long long int>>
#define pll pair<long long int, long long int>
#define mll map<long long int, long long int>
#define fr(i, a, b) for (long long int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit)
{
    int n = deadline.size();
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++)
    {
        A[i].first = deadline[i];
        A[i].second = profit[i];
    }
    sort(A);
    priority_queue<int, vector<int>, greater<int>> mini;
    for (int i = 0; i < n; i++)
    {
        int d = A[i].first;
        int p = A[i].second;
        mini.push(p);
        if (mini.size() > d)
        {
            mini.pop();
        }
    }
    int size = mini.size(), sum = 0;
    while (!mini.empty())
    {
        sum += mini.top();
        mini.pop();
    }
    return {size, sum};
}

int main()
{
    ll n;
    cin >> n;
    vector<int> deadline(n), profit(n);
    fr(i, 0, n)
    {
        cin >> deadline[i];
    }
    fr(i, 0, n)
    {
        cin >> profit[i];
    }
    vector<int> ans = jobSequencing(deadline, profit);
    cout << ans[0] << " " << ans[1] << endl;
}