#include <bits/stdc++.h>
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
#define printVector(v)    \
    for (auto &x : v)     \
        cout << x << ' '; \
    cout << endl;
#define printPairVector(v) \
    for (auto &x : v)      \
        cout << x.first << ' ' << x.second << endl;
#define mod 1000000007

class vvll : public vector<vector<ll>>
{
public:
    vvll(ll rows, ll cols, ll val) : vector<vector<ll>>(rows, vector<ll>(cols, val)) {}
};

bool isPalindrome(string s)
{
    ll l = 0, r = s.length() - 1;
    while (l < r)
    {
        if (s[l] == s[r])
        {
            l++, r--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        set<string> curr = {""};
        fr(i, 0, n)
        {
            set<string> next;
            for (auto &p : curr)
            {
                if (s[i] == '0' || s[i] == '?')
                {
                    string new_p = p + '0';
                    if (new_p.length() >= 5)
                    {
                        if (isPalindrome(new_p.substr(new_p.length() - 5, 5)) || (new_p.length() >= 6 && isPalindrome(new_p.substr(new_p.length() - 6, 6))))
                        {
                            continue;
                        }
                        else
                        {
                            next.insert(new_p.substr(new_p.length() - 5, 5));
                        }
                    }
                    else
                    {
                        next.insert(new_p);
                    }
                }
                if (s[i] == '1' || s[i] == '?')
                {
                    string new_p = p + '1';
                    if (new_p.length() >= 5)
                    {
                        if (isPalindrome(new_p.substr(new_p.length() - 5, 5)) || (new_p.length() >= 6 && isPalindrome(new_p.substr(new_p.length() - 6, 6))))
                        {
                            continue;
                        }
                        else
                        {
                            next.insert(new_p.substr(new_p.length() - 5, 5));
                        }
                    }
                    else
                    {
                        next.insert(new_p);
                    }
                }
            }
            curr = next;
            if (curr.empty())
            {
                break;
            }
        }
        if (curr.empty())
        {
            cout << "IMPOSSIBLE" << endl;
        }
        else
        {
            cout << "POSSIBLE" << endl;
        }
    }
}