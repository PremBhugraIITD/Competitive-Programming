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
#define fr(i, a, b) for (int(i) = (a); (i) < (b); (i)++)
#define frr(i, a, b) for (int(i) = (a); (i) >= (b); (i)--)
#define pb push_back
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define mod 1000000007

int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll i = 0, j = 0;
    ll ans = INT_MAX;
    mcl temp;
    fr(i, 0, n)
    {
        temp[s[i]]++;
    }
    ll k = temp.size();
    mcl count;
    while (j < n)
    {
        count[s[j]]++;
        while (i <= j && (count.size() >= k))
        {
            ans = min(ans, j - i + 1);
            count[s[i]]--;
            if (count[s[i]] == 0)
            {
                count.erase(s[i]);
            }
            i++;
        }
        j++;
    }
    cout << ans << endl;
}