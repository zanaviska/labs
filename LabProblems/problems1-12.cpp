#include "problems1-12.h"

using namespace std;

vector<int> Problems_1_12::delete_kratni(int n)
{
    vector<int> key = {};
    tree.get_all_keys(key, tree.begin());
    vector<int> ans;
    for(auto i:key)
        if(abs(i)%n == 0)
            ans.push_back(tree.erase(i));
    return ans;
}

vector<int> Problems_1_12::delete_unpair()
{
    vector<int> key;
    tree.get_all_keys(key, tree.begin());
    vector<int> ans;
    for(auto i:key)
        if(abs(i)%2 == 1)
        {
            //cerr << '!';
            ans.push_back(tree.erase(i));
            //if(ans.back() == -1000) cerr << i << '\n';
        }
    return ans;
}

vector<int> Problems_1_12::delete_higer(int comp)
{
    vector<int> key;
    tree.get_all_keys(key, tree.begin());
    vector<int> ans;
    for(int i = (int)key.size()-1; i >= 0 && key[i] > comp; i--)
        ans.push_back(tree.erase(key[i]));
    return ans;
}

vector<int> Problems_1_12::delete_lower(int comp)
{
    vector<int> key;
    tree.get_all_keys(key, tree.begin());
    vector<int> ans;
    for(auto i:key)
        if(i < comp)
            ans.push_back(tree.erase(i));
    return ans;
}

vector<int> Problems_1_12::delete_choosen(vector<int>choose)
{
    vector<int> ans;
    for(int i = 0; i < choose.size(); i++)
    {
        ans.push_back(tree.erase(choose[i]));
        if(ans.back() == -1000)
            ans.pop_back();
    }
    return ans;
}

vector<int> Problems_1_12::delete_prime()
{
    vector<int> key;
    tree.get_all_keys(key, tree.begin());
    vector<int> ans;
    for(int i = 0; i < 15; i++)
    {
        int temp = abs(key[i]);
        if(temp == 0 || temp == 1)
            continue;
        int root = sqrt(temp);
        bool ok = 1;
        for(int i = 2; i <= root; i++)
            if(temp%i == 0)
                ok = 0;
        if(ok)
            ans.push_back(tree.erase(key[i]));
    }
    return ans;
}

vector<int> Problems_1_12::delete_folded()
{
    vector<int> key;
    tree.get_all_keys(key, tree.begin());
    vector<int> ans;
    for(int i = 0; i < 15; i++)
    {
        int temp = abs(key[i]);
        if(temp == 0 || temp == 1)
            continue;
        int root = sqrt(temp);
        bool ok = 0;
        for(int i = 2; i <= root; i++)
            if(temp%i == 0)
                ok = 1;
        if(ok)
            ans.push_back(tree.erase(key[i]));
    }
    return ans;
}

vector<int> Problems_1_12::delete_interval(int from, int to)
{
    vector<int> key;
    tree.get_all_keys(key, tree.begin());
    vector<int> ans;
    for(int i = 0; i < 15; i++)
        if(from <= key[i] && key[i] <= to)
            ans.push_back(tree.erase(key[i]));
    return ans;
}

vector<int> Problems_1_12::delete_sum_of_digit_more(int comp)
{
    vector<int> key;
    tree.get_all_keys(key, tree.begin());
    vector<int> ans;
    for(int i = 0; i < 15; i++)
    {
        int temp = abs(key[i]);
        int sum = 0;
        while(temp != 0)
        {
            sum += temp%10;
            temp /= 10;
        }

        if(sum >= comp)
            ans.push_back(tree.erase(key[i]));
    }
    return ans;
}

vector<int> Problems_1_12::delete_sum_of_digit_less(int comp)
{
    vector<int> key;
    tree.get_all_keys(key, tree.begin());
    vector<int> ans;
    for(int i = 0; i < 15; i++)
    {
        int temp = abs(key[i]);
        int sum = 0;
        while(temp != 0)
        {
            sum += temp%10;
            temp /= 10;
        }
        if(sum <= comp)
            ans.push_back(tree.erase(key[i]));
    }
    return ans;
}

vector<int> Problems_1_12::delete_sum_of_digit_interval(int from, int to)
{
    vector<int> key;
    tree.get_all_keys(key, tree.begin());
    vector<int> ans;
    for(int i = 0; i < 15; i++)
    {
        int temp = abs(key[i]);
        int sum = 0;
        while(temp != 0)
        {
            sum += temp%10;
            temp /= 10;
        }
        if(from <= sum && sum <= to)
            ans.push_back(tree.erase(key[i]));
    }
    return ans;
}

vector<int> Problems_1_12::delete_square()
{
    vector<int> key;
    tree.get_all_keys(key, tree.begin());
    vector<int> ans;
    for(int i = 0; i < 15; i++)
    {
        float temp = sqrt(abs(key[i]));
        if(temp == (int)temp)
            ans.push_back(tree.erase(key[i]));
    }
    return ans;
}

