#include <iostream>
using namespace std;
#define MAXN 100010

long long arr[MAXN];

long long solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arr[n++] = 0;
    arr[n++] = 0;
    arr[n] = 0;
    arr[n+1] = 0;


    long long prev[] = {0, 0};
    for (int i = 0; i < n; i++)
    {
        arr[i] -= prev[i % 2];
        prev[i % 2] += arr[i];
    }

    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;

    long long doubles = 0, singles[2] = {0, 0};

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            if (i + 1 < n && arr[i + 1] > 0)
            {
                if (arr[i] < arr[i + 1])
                {
                    doubles += arr[i];
                    arr[i + 1] -= arr[i];
                    arr[i] = 0;
                }
                else
                {
                    doubles += arr[i + 1];
                    singles[i % 2] += arr[i] - arr[i + 1];
                    arr[i + 1] = 0;
                    arr[i] = 0;
                }
            }
            else
            {
                singles[i % 2] += arr[i];
                arr[i] = 0;
            }
        }
        else if (arr[i] < 0)
        {
            long long amt = min(doubles, -arr[i]);
            // if (i + 2 < n && arr[i + 2] > 0)
            {
              amt = min(amt, max(0ll, (arr[i + 2] <= 0 ? 0 : arr[i + 2]) - arr[i + 1]));
            }
            doubles -= amt;
            ans += amt;
            arr[i] += amt;
            if (i + 1 < n)
            {
                arr[i + 1] += amt;
            }
            if (arr[i] < 0)
            {
                singles[i % 2] += arr[i];
                ans -= arr[i];
                arr[i] = 0;

                if (singles[i % 2] < 0)
                {
                    long long amt = -singles[i % 2];
                    doubles -= amt;
                    singles[0] += amt;
                    singles[1] += amt;
                }
            }
        }

        //cout << i << ": " << ans << " " << doubles << " " << singles[0] << " " << singles[1] << endl;
    }

    return ans + doubles + singles[0] + singles[1];
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << solve() << endl;
    }
}
