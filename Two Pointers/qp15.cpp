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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    ll n;
    cin >> n;
    set<string> st;
    ll maxBoring = 0;
    while (n--)
    {
        string b;
        cin >> b;
        maxBoring = max((ll)b.length(), maxBoring);
        reverse(b);
        st.insert(b);
    }
    ll start = 0;
    ll ansLength = 0, ansStart = 0;
    n = s.length();
    fr(i, 0, n)
    {
        ll j = i;
        ll count = 0;
        string temp;
        while (j >= start && count < maxBoring)
        {
            temp.pb(s[j]);
            if (st.find(temp) != st.end())
            {
                if (i - start > ansLength)
                {
                    ansLength = i - start;
                    ansStart = start;
                }
                start = j + 1;
                // cout << i << " " << start << endl;
                break;
            }
            count++;
            j--;
        }
    }
    if (n - start > ansLength)
    {
        ansLength = n - start;
        ansStart = start;
    }
    cout << ansLength << " " << ansStart << endl;
}