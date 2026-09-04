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
        string s;
        cin >> s;
        vll count(26, 0);
        ll n = s.length();
        fr(i, 0, n)
        {
            count[s[i] - 'a']++;
        }
        ll l = 0, r = n - 1;
        vector<char> ans(n, '.');
        string temp;
        fr(i, 0, 26)
        {
            char c = (char)('a' + i);
            ll freq = count[i];
            if (freq & 1)
            {
                freq--;
                while (freq)
                {
                    ans[l++] = ans[r--] = c;
                    freq -= 2;
                }
                temp.pb(c);
                fr(j, i + 1, 26)
                {
                    c = (char)('a' + j);
                    freq = count[j];
                    while (freq--)
                    {
                        temp.pb(c);
                    }
                }
                break;
            }
            while (freq)
            {
                ans[l++] = ans[r--] = c;
                freq -= 2;
            }
        }
        // cout << "ans: ";
        // fr(i, 0, n)
        // {
        //     cout << ans[i];
        // }
        // cout << endl;
        if (temp.size() == 1)
        {
            ans[l] = temp[0];
        }
        else if (temp.size())
        {
            // cout<<temp<<endl;
            char first = temp[0];
            char second = temp[1];
            n = temp.size();
            bool found = false;
            fr(i, 0, n)
            {
                if (temp[i] != first && temp[i] != second)
                {
                    found = true;
                }
            }
            if (found)
            {
                ll j = 1;
                fr(i, l, r)
                {
                    ans[i] = temp[j++];
                }
                ans[r] = first;
            }
            else
            {
                // cout<<"Ssfs"<<endl;
                ll freq = count[second - 'a'];
                // cout<<l<<" "<<r<<endl;
                while (freq)
                {
                    ans[l++] = second;
                    freq--;
                    if (freq)
                    {
                        ans[r--] = second;
                        freq--;
                    }
                }
                ans[r] = first;
            }
        }
        // vector<char> reverse_ans = ans;
        // reverse(reverse_ans);
        // ans = max(ans, reverse_ans);
        // cout << "ans: ";
        fr(i, 0, ans.size())
        {
            cout << ans[i];
        }
        cout << endl;
    }
}