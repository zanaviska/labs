#include <bits/stdc++.h>

using namespace std;

double z(double x, double y)
{
    if(x > y)
        return x*x/(x-5)/(x-5)/(x-5);
    return (x-2)*(x-2)/y/(x-5)/(x-5)/(x-5)/(x-5);
}

int main()
{
    for(int y = -4; y <= 3; y += 1)
    {
        int cnt = 0;
        for(int x = 1; x <= 10; x += 2)
        {
            double res = z(x, y);
            cnt += (res > 0);
            cout << "For y == " << y << ", and x == " << x << " z == " << res << '\n';
        }
        cout << "For y == " << y << ", there is " << cnt << " positive z\n";
    }
}
