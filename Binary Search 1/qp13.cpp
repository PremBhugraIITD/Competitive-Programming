#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve(long long int k, vector<long long int> &A, long long int S)
{
    vector<long long int> costs(A.size());
    for (long long int i = 0; i < A.size(); i++)
    {
        costs[i] = A[i] + k * (i + 1);
    }
    sort(costs.begin(), costs.end());
    long long int sum = 0;
    for (long long int i = 0; i < costs.size(); i++)
    {
        if (sum + costs[i] <= S)
        {
            sum += costs[i];
            k--;
        }
        else
        {
            break;
        }
    }
    if (k <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    long long int n, S;
    cin >> n >> S;
    vector<long long int> A(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    long long int k;
    long long int l = 0, r = n;
    while (l <= r)
    {
        long long int mid = (l + r) / 2;
        if (solve(mid, A, S))
        {
            k = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    long long int sum = 0;
    long long int tempK = k;
    vector<long long int> costs(n);
    for (long long int i = 0; i < n; i++)
    {
        costs[i] = A[i] + k * (i + 1);
    }
    sort(costs.begin(), costs.end());
    for (long long int i = 0; i < n; i++)
    {
        if (sum + costs[i] <= S)
        {
            if (k == 0)
            {
                break;
            }
            else
            {
                sum += costs[i];
                k--;
            }
        }
        else
        {
            break;
        }
    }
    cout << tempK << " " << sum << endl;
}