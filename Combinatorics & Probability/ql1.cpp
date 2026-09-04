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
#define mcl map<char, long long int>
#define fr(i, a, b) for (long long int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (long long int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int uniquePaths(int m, int n)
{
    if (n == 1 || m == 1)
    {
        return 1;
    }
    long long int N = n + m - 2, k = min(n - 1, m - 1);
    long long int ans = 1;
    for (long long int i = 1; i <= k; i++)
    {
        ans = (ans * (N - k + i)) / i;
    }
    return ans;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    cout << uniquePaths(n, m) << endl;
}