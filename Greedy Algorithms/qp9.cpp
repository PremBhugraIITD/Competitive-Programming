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
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vll finalState(26, -1);
        fr(i, 0, n)
        {
            ll curr = s[i] - 'a';
            ll target = curr - min(k, curr);
            ll j = curr;
            while (j >= target && finalState[j] == -1)
            {
                j--;
            }
            if (j < target)
            {
                k -= curr - target;
                s[i] = (char)(target + 'a');
                fr(k, target, curr + 1)
                {
                    finalState[k] = target;
                }
            }
            else
            {
                k -= curr - j;
                s[i] = (char)(finalState[j] + 'a');
                fr(k, j + 1, curr + 1)
                {
                    finalState[k] = finalState[j];
                }
            }
        }
        cout << s << endl;
    }
}