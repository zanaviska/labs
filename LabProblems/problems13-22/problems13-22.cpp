#include "problems13-22.h"

using namespace std;

vector<>

template<class param>
void Problems_13_22::stupid_shell_sort(vector<param> &a, function<bool(param, param)> comparator)
{
    for(int d = a.size()-1; d > 0; d /= 2)
        for(int i = d; i < a.size(); i++)
            for(int j = i; j-d >= 0 && comparator(a[j], a[j-d]); j -= d)
                swap(a[j], a[j-d]);
}

vector<int> Problems_13_22::problem13(vector<int> a)
{
    vector<int> res = a;
    function<bool(int, int)> func = [](int x, int y){return x > y;};
    stupid_shell_sort(res, func);
    return res;
}

void Problems_13_22::problem14(vector<int> &a, int num)
{
    auto it = a.begin();
    while(it != a.end() && *it < num)
        it++;
    a.insert(it, num);
}

void Problems_13_22::problem15(vector<int> &a)
{
    reverse(a.begin(), a.end());
}

void Problems_13_22::problem16(vector<int> &a)
{
    for(int i = 0; i < a.size(); i++)
        if(a[i] < 0)
        {
            swap(a[i], a.back());
            a.pop_back();
        }
    function<bool(int, int)> func = [](int x, int y){return x < y;};
    stupid_shell_sort(a, func);
}

vector<int> Problems_13_22::problem17(vector<int> a)
{
    vector<int> res;
    res.reserve(a.size());
    for(auto i:a)
        res.insert(upper_bound(res.begin(), res.end(), i), i);
    return res;
}

void Problems_13_22::problem18(vector<string> &s)
{
    function<bool(string, string)> compar = [](string x, string y)
    {
        for(int i = 0; i < min(x.length(), y.length()); i++)
            if(x[i] != y[i])
                return x[i] < y[i];
        return x.length() < y.length();
    };
    stupid_shell_sort(s, compar);
}

void Problems_13_22::problem19(vector<pair<int, string>> &a)
{
    function<bool(pair<int, string>, pair<int, string>)> compare = [](pair<int, string> x, pair<int, string> y)
    {
        return x.first < y.first;
    };
    stupid_shell_sort(a, compare);
}

void Problems_13_22::problem20(vector<string> &s)
{
    function<bool(string, string)> comparator = [](string a, string b){return a.length() < b.length();};
    stupid_shell_sort(s, comparator);
}

void Problems_13_22::problem21(vector<int> &a)
{
    function<bool(int, int)> func = [](int a, int b){return abs(a) < abs(b);};
    stupid_shell_sort(a, func);
}

void Problems_13_22::problem22(vector<double> &a)
{
    if(a.empty()) return;
    queue<double> q;
    q.push(a[0]);
    for(int i = 1; i < (int)a.size(); i++)
        q.push((a[i]+a[i-1])/2),
        q.push(a[i]);
    a.clear();
    while(!q.empty())
    {
        a.push_back(q.front());
        q.pop();
    }
}
