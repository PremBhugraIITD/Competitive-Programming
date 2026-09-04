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
    ll n = s.length();
    vll freq(26, 0);
    fr(i, 0, n)
    {
        freq[s[i] - 'a']++;
    }
    vector<vector<vll>> count(26, vector<vll>(n, vll(26, 0)));
    ll favourable = 0;
    fr(i, 0, n)
    {
        ll j = 0;
        while (j < n)
        {
            count[s[i] - 'a'][j][s[(i + j) % n] - 'a']++;
            j++;
        }
    }
    ld ans = 0;
    fr(i, 0, 26)
    {
        if (freq[i] == 0)
        {
            // cout<<"dzd"<<endl;
            continue;
        }
        else if (freq[i] == 1)
        {
            // cout<<"dxvfx"<<endl;
            ans = ans + (1.0 / n);
        }
        else
        {
            ld prob = (freq[i] * 1.0) / n;
            ld maxi = 0;
            fr(j, 1, n)
            {
                ll total = 0, ones = 0;
                fr(k, 0, 26)
                {
                    ll temp = count[i][j][k];
                    total += temp;
                    if (temp == 1)
                    {
                        ones++;
                    }
                }
                if (total > 0)
                {
                    maxi = max(maxi, ((ld)ones) / total);
                }
            }
            ans = ans + prob * maxi;
            // cout << ans << " " << prob << endl;
        }
    }
    cout << setprecision(10) << ans << endl;
}