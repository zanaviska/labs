#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "problems1-12.h"
#include "doctest.h"

using namespace std;

vector<int> v = {0, 20, 10, 5, 15, 30, 25, 35, -20, -10, -5, -15, -30, -25, -35};

TEST_CASE("problem1 with our tree")
{
    Problems_1_12 pr = Problems_1_12(v);
    vector<int> deleted = pr.delete_pair();
    vector<int> key = pr.get_all_keys();
    vector<int> a = v;

    CHECK(key.size() == 8);
    for(int i = 0; i < key.size(); i++)
    {
        CHECK(abs(key[i])%2 == 1);
        bool ok = 0;
        for(int j = a.size()-1; j >= 0; j--)
            if(a[j] == key[i])
                ok = 1;
        CHECK(ok == 1);
    }
    CHECK(deleted.size() == 7);
    for(int i = 0; i < deleted.size(); i++)
    {
        CHECK(deleted[i]%2 == 0);
        bool ok = 0;
        for(int j = a.size()-1; j >= 0; j--)
            if(a[j] == deleted[i])
                ok = 1;
        CHECK(ok == 1);
    }
}

TEST_CASE("problem#1 with random tree")
{
    Problems_1_12 pr = Problems_1_12();
    vector<int> a = pr.get_all_keys();
    vector<int> deleted = pr.delete_pair();
    vector<int> key = pr.get_all_keys();

    for(int i = 0; i < key.size(); i++)
    {
        CHECK(abs(key[i])%2 == 1);
        bool ok = 0;
        for(int j = a.size()-1; j >= 0; j--)
            if(a[j] == key[i])
                ok = 1;
        CHECK(ok == 1);
    }
    for(int i = 0; i < deleted.size(); i++)
    {
        CHECK(deleted[i]%2 == 0);
        bool ok = 0;
        for(int j = a.size()-1; j >= 0; j--)
            if(a[j] == deleted[i])
                ok = 1;
        CHECK(ok == 1);
    }
}

TEST_CASE("problem2 with our tree")
{
    Problems_1_12 pr = Problems_1_12(v);
    vector<int> deleted = pr.delete_unpair();
    vector<int> key = pr.get_all_keys();
    vector<int> a = v;

    CHECK(key.size() == 7);
    for(int i = 0; i < key.size(); i++)
    {
        CHECK(abs(key[i])%2 == 0);
        bool ok = 0;
        for(int j = a.size()-1; j >= 0; j--)
            if(a[j] == key[i])
                ok = 1;
        CHECK(ok == 1);
    }
    CHECK(deleted.size() == 8);
    for(int i = 0; i < deleted.size(); i++)
    {
        CHECK(abs(deleted[i])%2 == 1);
        bool ok = 0;
        for(int j = a.size()-1; j >= 0; j--)
            if(a[j] == deleted[i])
                ok = 1;
        CHECK(ok == 1);
    }
}

TEST_CASE("problem#2 with random tree")
{
    Problems_1_12 pr = Problems_1_12();
    vector<int> a = pr.get_all_keys();
    vector<int> deleted = pr.delete_unpair();
    vector<int> key = pr.get_all_keys();

    for(int i = 0; i < key.size(); i++)
    {
        CHECK(abs(key[i])%2 == 0);
        bool ok = 0;
        for(int j = a.size()-1; j >= 0; j--)
            if(a[j] == key[i])
                ok = 1;
        CHECK(ok == 1);
    }
    for(int i = 0; i < deleted.size(); i++)
    {
        CHECK(abs(deleted[i])%2 == 1);
        bool ok = 0;
        for(int j = a.size()-1; j >= 0; j--)
            if(a[j] == deleted[i])
                ok = 1;
        CHECK(ok == 1);
    }
}

TEST_CASE("problem#3 with our tree")
{
    Problems_1_12 pr = Problems_1_12(v);
    vector<int> deleted = pr.delete_higer(3);
    vector<int> key = pr.get_all_keys();
    CHECK(deleted.size() == 7);
    CHECK(key.size() == 8);
    for(auto i:deleted)
        CHECK(i > 3);
    for(auto i:key)
        CHECK(i < 3);
}

TEST_CASE("problem#3 with random tree")
{
    Problems_1_12 pr = Problems_1_12();
    int comp = rand();
    vector<int> deleted = pr.delete_higer(comp);
    vector<int> key = pr.get_all_keys();
    CHECK(deleted.size() + key.size() == 15);
    for(auto i:deleted)
        CHECK(i > comp);
    for(auto i:key)
        CHECK(i <= comp);
}

TEST_CASE("problem#4 with our tree")
{
    Problems_1_12 pr = Problems_1_12(v);
    vector<int> deleted = pr.delete_lower(3);
    vector<int> key = pr.get_all_keys();
    CHECK(deleted.size() == 8);
    CHECK(key.size() == 7);
    for(auto i:deleted)
        CHECK(i < 3);
    for(auto i:key)
        CHECK(i > 3);
}

TEST_CASE("problem#4 with random tree")
{
    Problems_1_12 pr = Problems_1_12();
    int comp = rand();
    vector<int> deleted = pr.delete_lower(comp);
    vector<int> key = pr.get_all_keys();
    CHECK(deleted.size() + key.size() == 15);
    for(auto i:deleted)
        CHECK(i <= comp);
    for(auto i:key)
        CHECK(i > comp);
}

TEST_CASE("problem#5 with our tree")
{
    Problems_1_12 pr = Problems_1_12(v);
    vector<int> dop = {0, 1, 2, 3, 4, 5};
    vector<int> deleted = pr.delete_choosen(dop);
    vector<int> key = pr.get_all_keys();
    CHECK(deleted.size() == 2);
    CHECK(key.size() == 13);
    for(int i = -7; i >= -1; i++)
        CHECK(key[i+7] == -5*i);
    for(int i = 2; i < 8; i++)
        CHECK(key[i+5] == 5*i);
    CHECK(deleted[0] == 0);
    CHECK(deleted[1] == 5);
}

TEST_CASE("problem#5 with random tree")
{
    Problems_1_12 pr = Problems_1_12();
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_choosen({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
    vector<int> key = pr.get_all_keys();
    CHECK(key.size()+deleted.size() == 15);
    int pos = -1;
    while(++pos < key.size() && key[pos] < 0)
        CHECK(key[pos] == all[pos]);
    int i = -1;
    while(++i < deleted.size() && all[i] < 10)
        CHECK(all[i+pos] == deleted[i]);
    pos--;
    while(++pos < key.size())
        CHECK(all[pos+i] == key[pos]);
}

TEST_CASE("problem#6 with our tree")
{
    Problems_1_12 pr = Problems_1_12(v);
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_prime();
    vector<int> key = pr.get_all_keys();
    CHECK(deleted.size() + key.size() == 15);
    function<bool(int)> is_prime = [](int x)
    {
        if(abs(x) == 1 || x == 0)
            return 0;
        for(int i = 2; i <= sqrt(abs(x)); i++)
            if(x%i == 0)
                return 0;
        return 1;
    };
    for(auto i:key)
        cout << i << "! ";
    for(auto i:deleted)
        cout << i << ' ';
    for(auto i:key)
        CHECK(is_prime(i) == 0);
    for(auto i:deleted)
        CHECK(is_prime(i) == 1);
}

TEST_CASE("problem#6 with random tree")
{
    Problems_1_12 pr = Problems_1_12();
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_prime();
    vector<int> key = pr.get_all_keys();
    CHECK(deleted.size() + key.size() == 15);
    function<bool(int)> is_prime = [](int x)
    {
        if(abs(x) == 1 || x == 0)
            return 0;
        for(int i = 2; i <= sqrt(abs(x)); i++)
            if(x%i == 0)
                return 0;
        return 1;
    };
    for(auto i:key)
        CHECK(is_prime(i) == 0);
    for(auto i:deleted)
        CHECK(is_prime(i) == 1);
}

TEST_CASE("problem#7 with our tree")
{
    Problems_1_12 pr = Problems_1_12(v);
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_folded();
    vector<int> key = pr.get_all_keys();
    CHECK(deleted.size() + key.size() == 15);
    function<bool(int)> is_prime = [](int x)
    {
        for(int i = 2; i <= sqrt(abs(x)); i++)
            if(x%i == 0)
                return 0;
        return 1;
    };
    for(auto i:key)
        CHECK(is_prime(i) == 1);
    for(auto i:deleted)
        CHECK(is_prime(i) == 0);
}

TEST_CASE("problem#7 with random tree")
{
    Problems_1_12 pr = Problems_1_12();
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_folded();
    vector<int> key = pr.get_all_keys();
    CHECK(deleted.size() + key.size() == 15);
    function<bool(int)> is_prime = [](int x)
    {
        for(int i = 2; i <= sqrt(abs(x)); i++)
            if(x%i == 0)
                return 0;
        return 1;
    };
    for(auto i:key)
        CHECK(is_prime(i) == 1);
    for(auto i:deleted)
        CHECK(is_prime(i) == 0);
}

TEST_CASE("problem#8 with our tree")
{
    Problems_1_12 pr = Problems_1_12(v);
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_interval(0, 50);
    vector<int> key = pr.get_all_keys();
    CHECK(key.size()+deleted.size() == 15);
    for(int i = 0; i < key.size(); i++)
        CHECK(key[i] == all[i]);
    for(int i = 0; i < deleted.size(); i++)
        CHECK(all[i+key.size()] == deleted[i]);
}

TEST_CASE("problem#8 with random tree")
{
    Problems_1_12 pr = Problems_1_12();
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_interval(0, 50);
    vector<int> key = pr.get_all_keys();
    CHECK(key.size()+deleted.size() == 15);
    int i = 0;
    for(; key[i] < 0; i++)
        CHECK(key[i] == all[i]);
    int j = 0;
    for(; j < deleted.size(); j++)
        CHECK(deleted[j] == all[i+j]);
    for(; i < key.size(); i++)
    {
        CHECK(key[i] > 50);
        CHECK(all[i+j] == key[i]);
    }
}

TEST_CASE("problem9# with our tree")
{
    Problems_1_12 pr = Problems_1_12(v);
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_sum_of_digit_more(5);
    vector<int> key = pr.get_all_keys();
    function<int(int)> sum = [](int x)
    {
        int ans = 0;
        x = abs(x);
        while(x != 0)
        {
            ans += x%10;
            x /= 10;
        }
        return ans;
    };
    CHECK(key.size()+deleted.size() == 15);
    for(auto i:deleted)
        CHECK(sum(i) >= 5);
    for(auto i:key)
        CHECK(sum(i) < 5);
}

TEST_CASE("problem9# with random tree")
{
    Problems_1_12 pr = Problems_1_12();
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_sum_of_digit_more(5);
    vector<int> key = pr.get_all_keys();
    function<int(int)> sum = [](int x)
    {
        int ans = 0;
        x = abs(x);
        while(x != 0)
        {
            ans += x%10;
            x /= 10;
        }
        return ans;
    };
    CHECK(key.size()+deleted.size() == 15);
    for(auto i:deleted)
        CHECK(sum(i) >= 5);
    for(auto i:key)
        CHECK(sum(i) < 5);

}

TEST_CASE("problem10# with our tree")
{
    Problems_1_12 pr = Problems_1_12(v);
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_sum_of_digit_less(5);
    vector<int> key = pr.get_all_keys();
    function<int(int)> sum = [](int x)
    {
        int ans = 0;
        x = abs(x);
        while(x != 0)
        {
            ans += x%10;
            x /= 10;
        }
        return ans;
    };
    CHECK(key.size()+deleted.size() == 15);
    for(auto i:deleted)
        CHECK(sum(i) <= 5);
    for(auto i:key)
        CHECK(sum(i) > 5);
}

TEST_CASE("problem10# with random tree")
{
    Problems_1_12 pr = Problems_1_12();
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_sum_of_digit_less(5);
    vector<int> key = pr.get_all_keys();
    function<int(int)> sum = [](int x)
    {
        int ans = 0;
        x = abs(x);
        while(x != 0)
        {
            ans += x%10;
            x /= 10;
        }
        return ans;
    };
    CHECK(key.size()+deleted.size() == 15);
    for(auto i:deleted)
        CHECK(sum(i) <= 5);
    for(auto i:key)
        CHECK(sum(i) > 5);
}

TEST_CASE("problem11# with our tree")
{
    Problems_1_12 pr = Problems_1_12(v);
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_sum_of_digit_interval(3, 7);
    vector<int> key = pr.get_all_keys();
    function<int(int)> sum = [](int x)
    {
        int ans = 0;
        x = abs(x);
        while(x != 0)
        {
            ans += x%10;
            x /= 10;
        }
        return ans;
    };
    CHECK(key.size()+deleted.size() == 15);
    for(auto i:key)
        CHECK((sum(i) < 3 || sum(i) > 7));
    for(auto i:deleted)
        CHECK((3 <= sum(i) && sum(i) <= 7));
}

TEST_CASE("problem11# with random tree")
{
    Problems_1_12 pr = Problems_1_12();
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_sum_of_digit_interval(3, 7);
    vector<int> key = pr.get_all_keys();
    function<int(int)> sum = [](int x)
    {
        int ans = 0;
        x = abs(x);
        while(x != 0)
        {
            ans += x%10;
            x /= 10;
        }
        return ans;
    };
    CHECK(key.size()+deleted.size() == 15);
    for(auto i:key)
        CHECK((sum(i) < 3 || sum(i) > 7));
    for(auto i:deleted)
        CHECK((3 <= sum(i) && sum(i) <= 7));
}

TEST_CASE("problem12# with our tree")
{
    Problems_1_12 pr = Problems_1_12(v);
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_square();
    vector<int> key = pr.get_all_keys();
    CHECK(key.size()+deleted.size() == 15);
    for(auto i:deleted)
        CHECK((int)sqrt(abs(i)) == sqrt(abs(i)));
    for(auto i:key)
        CHECK((int)sqrt(abs(i)) != sqrt(abs(i)));
}

TEST_CASE("problem12# with random tree")
{
    Problems_1_12 pr = Problems_1_12();
    vector<int> all = pr.get_all_keys();
    vector<int> deleted = pr.delete_square();
    vector<int> key = pr.get_all_keys();
    CHECK(key.size()+deleted.size() == 15);
    for(auto i:deleted)
        CHECK((int)sqrt(abs(i)) == sqrt(abs(i)));
    for(auto i:key)
        CHECK((int)sqrt(abs(i)) != sqrt(abs(i)));
}



