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

void balance(multiset<int> &low, multiset<int> &high, long long int &leftSum, long long int &rightSum)
{
    if (low.size() < high.size())
    {
        low.insert(*high.begin());
        leftSum += *high.begin();
        rightSum -= *high.begin();
        high.erase(high.find(*high.begin()));
    }
    else if (low.size() > high.size() + 1)
    {
        high.insert(*low.rbegin());
        rightSum += *low.rbegin();
        leftSum -= *low.rbegin();
        low.erase(low.find(*low.rbegin()));
    }
}

vector<long long int> medianSlidingWindow(vector<long long int> &nums, int k)
{
    multiset<int> low, high;
    vector<long long int> ans;
    long long int leftSum = 0, rightSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (low.empty() || (nums[i] < *low.rbegin()))
        {
            low.insert(nums[i]);
            leftSum += nums[i];
        }
        else
        {
            high.insert(nums[i]);
            rightSum += nums[i];
        }
        balance(low, high, leftSum, rightSum);
        if (i >= k)
        {
            if (nums[i - k] <= *low.rbegin())
            {
                low.erase(low.find(nums[i - k]));
                leftSum -= nums[i - k];
            }
            else
            {
                high.erase(high.find(nums[i - k]));
                rightSum -= nums[i - k];
            }
        }
        balance(low, high, leftSum, rightSum);
        if (i >= k - 1)
        {
            long long int median = *low.rbegin();
            ans.push_back(abs(leftSum - ((k + 1) / 2) * median) + abs(rightSum - (k / 2) * median));
        }
    }
    return ans;
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
    vector<long long int> ans = medianSlidingWindow(A, k);
    fr(i, 0, ans.size())
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}