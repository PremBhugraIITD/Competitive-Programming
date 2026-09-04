#include <iostream>
#include <vector>
using namespace std;

long long int find(long long int q, vector<long long int> &A)
{
    long long int l = 0, r = A.size() - 1;
    long long int ans;
    while (l <= r)
    {
        long long int mid = (l + r) / 2;
        if (A[mid] >= q)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    long long int n;
    cin >> n;
    vector<long long int> A(n);
    for (long long int i = 0; i < n; i++)
    {
        cin >> A[i];
        if (i >= 1)
        {
            A[i] = A[i - 1] + A[i];
        }
    }
    long long int m;
    cin >> m;
    vector<long long int> Q(m);
    for (long long int i = 0; i < m; i++)
    {
        cin >> Q[i];
    }
    for (long long int i = 0; i < m; i++)
    {
        long long int q = Q[i];
        cout << find(q, A) + 1 << endl;
    }
}