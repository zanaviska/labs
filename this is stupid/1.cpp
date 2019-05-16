#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);

int main()
{
    const int R = 2;
    const int r = 1;
    const int H = 5;
    double l = sqrt(H*H+(R-r));
    double s = pi*(R+r) + pi*R*R + pi*r*r;
    double v = pi/3*(R*R+r*r+r*R)*H;
    cout << s << ' ' << v << '\n'; 
}
