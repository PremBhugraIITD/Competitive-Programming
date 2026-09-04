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

long long int sumFromTo(long long int a, long long int b)
{
    a = max(a, (long long int)1);
    return ((b * (b + 1)) / 2) - ((a * (a - 1)) / 2);
}
long long minMaxSubarraySum(vector<ll> &nums, int k)
{
    long long int n = nums.size();
    vector<long long int> previousSmaller(n, -1);
    stack<long long int> ps;
    for (long long int i = 0; i < n; i++)
    {
        while (!ps.empty() && nums[ps.top()] > nums[i])
        {
            ps.pop();
        }
        if (!ps.empty())
        {
            previousSmaller[i] = ps.top();
        }
        ps.push(i);
    }
    vector<long long int> nextSmaller(n, n);
    stack<long long int> ns;
    for (long long int i = n - 1; i >= 0; i--)
    {
        while (!ns.empty() && nums[ns.top()] >= nums[i])
        {
            ns.pop();
        }
        if (!ns.empty())
        {
            nextSmaller[i] = ns.top();
        }
        ns.push(i);
    }
    long long int sum = 0;
    for (long long int i = 0; i < n; i++)
    {
        long long int curr = nums[i];
        long long int x = i - previousSmaller[i] - 1;
        long long int y = nextSmaller[i] - i - 1;
        x = min(x, (long long int)k - 1);
        y = min(y, (long long int)k - 1);
        sum += x * curr;
        sum += y * curr;
        sum += curr;
        if (k <= 2)
        {
            continue;
        }
        else
        {
            if (x == k - 1 && y == k - 1)
            {
                sum += curr * sumFromTo(1, k - 2);
            }
            else if (x == k - 1 && y < k - 1)
            {
                if (y == 0)
                {
                    continue;
                }
                else
                {
                    sum += curr * sumFromTo(k - (y + 1), k - 2);
                }
            }
            else if (x < k - 1 && y == k - 1)
            {
                if (x == 0)
                {
                    continue;
                }
                else
                {
                    sum += curr * sumFromTo(k - (x + 1), k - 2);
                }
            }
            else
            {
                if (x == 0 || y == 0)
                {
                    continue;
                }
                else
                {
                    sum += curr * y * min(x, k - (y + 1));
                    x -= (k - (y + 1));
                    if (x > 0)
                    {
                        sum += curr * sumFromTo(y - x, y - 1);
                    }
                }
            }
        }
    }
    vector<long long int> previousGreater(n, -1);
    stack<long long int> pg;
    for (long long int i = 0; i < n; i++)
    {
        while (!pg.empty() && nums[pg.top()] < nums[i])
        {
            pg.pop();
        }
        if (!pg.empty())
        {
            previousGreater[i] = pg.top();
        }
        pg.push(i);
    }
    vector<long long int> nextGreater(n, n);
    stack<long long int> ng;
    for (long long int i = n - 1; i >= 0; i--)
    {
        while (!ng.empty() && nums[ng.top()] <= nums[i])
        {
            ng.pop();
        }
        if (!ng.empty())
        {
            nextGreater[i] = ng.top();
        }
        ng.push(i);
    }
    for (long long int i = 0; i < n; i++)
    {
        long long int curr = nums[i];
        long long int x = i - previousGreater[i] - 1;
        long long int y = nextGreater[i] - i - 1;
        x = min(x, (long long int)k - 1);
        y = min(y, (long long int)k - 1);
        sum += x * curr;
        sum += y * curr;
        sum += curr;
        if (k <= 2)
        {
            continue;
        }
        else
        {
            if (x == k - 1 && y == k - 1)
            {
                sum += curr * sumFromTo(1, k - 2);
            }
            else if (x == k - 1 && y < k - 1)
            {
                if (y == 0)
                {
                    continue;
                }
                else
                {
                    sum += curr * sumFromTo(k - (y + 1), k - 2);
                }
            }
            else if (x < k - 1 && y == k - 1)
            {
                if (x == 0)
                {
                    continue;
                }
                else
                {
                    sum += curr * sumFromTo(k - (x + 1), k - 2);
                }
            }
            else
            {
                if (x == 0 || y == 0)
                {
                    continue;
                }
                else
                {
                    sum += curr * y * min(x, k - (y + 1));
                    x -= (k - (y + 1));
                    if (x > 0)
                    {
                        sum += curr * sumFromTo(y - x, y - 1);
                    }
                }
            }
        }
    }
    return sum;
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
    cout << minMaxSubarraySum(A, k) << endl;
}