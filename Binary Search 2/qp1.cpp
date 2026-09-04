#include <iostream>
#include <vector>
using namespace std;
int main()
{
    string input;
    long long int count = 0;
    vector<long long int> divisors = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    long long int i = 0;
    while (i < 15)
    {
        long long int divisor = divisors[i];
        cout << divisor << endl;
        cin >> input;
        if (input == "yes")
        {
            count++;
            if (divisor * divisor <= 100)
            {
                cout << (divisor * divisor) << endl;
                cin >> input;
                if (input == "yes")
                {
                    cout << "composite" << endl;
                    break;
                }
                else
                {
                    i++;
                    continue;
                }
            }
            else
            {
                i++;
                continue;
            }
        }
        else
        {
            i++;
            continue;
        }
    }
    if (count >= 2)
    {
        cout << "composite" << endl;
    }
    else
    {
        cout << "prime" << endl;
    }
}