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
#define pll <pair<long long int, long long int>>
#define mll map<long long int, long long int>
#define mcl map<char, long long int>
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int minKBitFlips(vector<ll> &nums, int k)
{
    int n = nums.size();
    vector<int> flips(n, 0);
    for (int i = 0; i < n; i++)
    {
        int curr = nums[i];
        if (i > 0)
        {
            int ops = flips[i - 1] + (i - k >= 0 ? flips[i - k] : 0);
            if (ops & 1)
            {
                curr ^= 1;
            }
            flips[i] = flips[i - 1];
        }
        if (curr == 0)
        {
            if (i + k - 1 <= n - 1)
            {
                flips[i]++;
            }
            else
            {
                return -1;
            }
        }
    }
    return flips[n - 1];
}

int main()
{
    ll n, k;
    cin >> n >> k;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    cout << minKBitFlips(A, k) << endl;
}