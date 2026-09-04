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
    ll n;
    cin >> n;
    vll A(n);
    fr(i, 0, n)
    {
        cin >> A[i];
    }
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else
    {
        ll i = 0;
        ll ans = 0;
        vll color(n, 0);
        // fr(i, 0, n)
        // {
        //     cout << color[i] << " ";
        // }
        // cout << endl;
        while (i < n && A[i] != 0)
        {
            color[i] = 1;
            i++;
        }
        // fr(i, 0, n)
        // {
        //     cout << color[i] << " ";
        // }
        // cout << endl;
        if (i == n)
        {
            ans++;
        }
        else
        {
            if (i > 0)
            {
                color[i] = 1;
                ans++;
            }
            while (i < n)
            {
                if (A[i] == 0)
                {
                    if (color[i] == 1)
                    {
                        if (i + 1 <= n - 1)
                        {
                            // not the last element
                            if (A[i + 1] != 0)
                            {
                                ll j = i + 1;
                                while (j < n && A[j] != 0)
                                {
                                    color[j] = 1;
                                    j++;
                                }
                                i = j - 1;
                                ans++;
                                if (j != n)
                                {
                                    color[j] = 1;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (i + 1 <= n - 1)
                        {
                            // not the last element
                            color[i] = 1;
                            if (A[i + 1] == 0)
                            {
                                ans++;
                            }
                            else
                            {
                                bool has2 = false;
                                ll j = i + 1;
                                while (j < n && A[j] != 0)
                                {
                                    if (A[j] == 2)
                                    {
                                        has2 = true;
                                    }
                                    color[j] = 1;
                                    j++;
                                }
                                i = j - 1;
                                if (j == n)
                                {
                                    ans++;
                                }
                                else
                                {
                                    ans++;
                                    if ((color[j] == 0) && has2)
                                    {
                                        color[j] = 1;
                                    }
                                }
                            }
                        }
                        else
                        {
                            // last element
                            color[i] = 1;
                            ans++;
                        }
                    }
                }
                // cout << i << " " << ans << endl;
                // fr(k, 0, n)
                // {
                //     cout << color[k] << " ";
                // }
                // cout << endl;
                i++;
            }
            // fr(i, 0, n)
            // {
            //     cout << color[i] << " ";
            // }
            // cout << endl;
        }
        cout << ans << endl;
    }
}