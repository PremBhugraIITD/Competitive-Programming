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
#define mod 1000000007

int countKSubsequencesWithMaxBeauty(string s, int k)
{
    long long int n = s.length();
    vector<long long int> count(26, 0);
    for (long long int i = 0; i < n; i++)
    {
        count[s[i] - 'a']++;
    }
    long long int unique = 0;
    for (long long int i = 0; i < 26; i++)
    {
        if (count[i])
        {
            unique++;
        }
    }
    if (unique < k)
    {
        return 0;
    }
    else
    {
        sort(count.begin(), count.end());
        reverse(count.begin(), count.end());
        long long int score = 0;
        long long int product = 1;
        for (long long int i = 0; i < k; i++)
        {
            score += count[i];
            product = (product * count[i]) % mod;
        }
        long long int target = count[k - 1];
        long long int a = 0, b = 0;
        for (long long int i = 0; i < 26; i++)
        {
            if (count[i] == target)
            {
                a++;
                if (i < k)
                {
                    b++;
                }
            }
        }
        long long int temp = 1;
        for (long long int i = 1; i <= b; i++)
        {
            temp = ((temp * (a - b + i)) / i) % mod;
        }
        long long int ans = (product * temp) % mod;
        return ans;
    }
}

int main()
{
    string s;
    cin >> s;
    ll k;
    cin >> k;
    cout << countKSubsequencesWithMaxBeauty(s, k) << endl;
}