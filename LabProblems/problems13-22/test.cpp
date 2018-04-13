#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "problems13-22.h"
#include "doctest.h"

TEST_CASE("problem13 with our arr")
{
    Problems_13_22 pr;
    vector<int> x = {0, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> b = pr.problem13(x);
    CHECK(b.size() == x.size());
    for(int i = 1; i < b.size(); i++)
        CHECK(b[i-1] > b[i]);
}

TEST_CASE("problem13 with random arr")
{
    srand(time(0));
    Problems_13_22 pr;
    vector<int> a;
    for(int i = 0; i < rand()%100; i++)
        a.push_back(rand());
    vector<int> b = pr.problem13(a);
    CHECK(b.size() == a.size());
    for(int i = 1; i < b.size(); i++)
        CHECK(b[i-1] > b[i]);
}

TEST_CASE("problem14 with our arr")
{
    Problems_13_22 pr;
    vector<int> a = {0, 1, 2, 4, 5, 6};
    pr.problem14(a, 3);
    CHECK(a.size() == 7);
    for(int i = 0; i < 7; i++)
        CHECK(i == a[i]);
}

TEST_CASE("problem14 with random arr")
{
    srand(time(0));
    Problems_13_22 pr;
    vector<int> a;
    for(int i = 0; i < 20; i++)
        a.push_back(i*100+rand()%100);
    pr.problem14(a, rand());
    CHECK(a.size() == 21);
    for(int i = 1; i < 21; i++)
        CHECK(a[i-1] <= a[i]);
}

TEST_CASE("problem15 with our arr")
{
    Problems_13_22 pr;
    vector<int> a = {0, 1, 2, 3, 4, 5};
    pr.problem15(a);
    CHECK(a.size() == 6);
    for(int i = 0; i < 6; i++)
        CHECK(a[i] == 5-i);
}

TEST_CASE("problem15 with random arr")
{
    srand(time(0));
    Problems_13_22 pr;
    vector<int> a;
    for(int i = 0; i < 20; i++)
        a.push_back(i*100+rand()%100);
    pr.problem15(a);
    CHECK(a.size() == 20);
    for(int i = 1; i < 20; i++)
        CHECK(a[i-1] >= a[i]);
}

TEST_CASE("problem16 with our arr")
{
    Problems_13_22 pr;
    vector<int> a = {3, -2, 0, -1, 5};
    pr.problem16(a);
    CHECK(a.size() == 3);
    CHECK(a[0] == 0);
    CHECK(a[1] == 3);
    CHECK(a[2] == 5);
}

TEST_CASE("problem16 with random arr")
{
    srand(time(0));
    Problems_13_22 pr;
    vector<int> a;
    for(int i = 0; i < 20; i++)
        a.push_back(rand());
    pr.problem16(a);
    if(a.size() > 0)
        CHECK(a[0] >= 0);
    for(int i = 1; i < a.size(); i++)
        CHECK(a[i-1] <= a[i]);
}

TEST_CASE("problem17 with our arr")
{
    Problems_13_22 pr;
    vector<int> a = {0, 5, 2, 3, 1, 4};
    vector<int> b = pr.problem17(a);
    CHECK(b.size() == 6);
    for(int i = 0; i < 6; i++)
        b[i] == i;
}

TEST_CASE("problem17 with random arr")
{
    srand(time(0));
    Problems_13_22 pr;
    vector<int> a;
    for(int i = 0; i < 20; i++)
        a.push_back(rand());
    vector<int> b = pr.problem17(a);
    CHECK(b.size() == 20);
    for(int i = 1; i < 20; i++)
        CHECK(b[i-1] < b[i]);
}

TEST_CASE("problem18 with our arr")
{
    Problems_13_22 pr;
    vector<string> a = {"timur", "max", "orel", "olena"};
    pr.problem18(a);
    CHECK(a.size() == 4);
    CHECK(a[0] == "max");
    CHECK(a[1] == "olena");
    CHECK(a[2] == "orel");
    CHECK(a[3] == "timur");
}

TEST_CASE("problem18 with random arr")
{
    srand(time(0));
    Problems_13_22 pr;
    vector<string> a;
    string dop = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < 20; i++)
    {
        string s = "";
        for(int j = 0; j < 20; j++)
            s.push_back(dop[rand()%26]);
        a.push_back(s);
    }
    pr.problem18(a);
    CHECK(a.size() == 20);
    vector<string> b = a;
    sort(b.begin(), b.end());
    CHECK(a == b);
}

TEST_CASE("problem19 with our arr")
{
    Problems_13_22 pr;
    vector<pair<int, string>> a =
    {
        {3801234567, "max"},
        {3801034567, "orel"},
        {3801237567, "olena"},
        {3801234569, "timur"}
    };
    pr.problem19(a);
    CHECK(a.size() == 4);
    for(int i = 1; i < 4; i++)
        CHECK(a[i-1].first < a[i].first);
}

TEST_CASE("problem19 with random arr")
{
    srand(time(0));
    Problems_13_22 pr;
    string dop = "abcdefghijklmnopqrstuvwxyz";
    vector<pair<int, string>> a;
    for(int i = 0; i < 20; i++)
    {
        string s = "";
        for(int j = 0; j < 20; j++)
            s.push_back(dop[rand()%26]);
        a.push_back({rand(), s});
    }
    pr.problem19(a);
    CHECK(a.size() == 20);
    for(int i = 1; i < 20; i++)
        CHECK(a[i-1].first < a[i].first);
}

TEST_CASE("problem20 with our arr")
{
    Problems_13_22 pr;
    vector<string> a = {"aaaa", "a", "aa", "aaa"};
    pr.problem20(a);
    CHECK(a.size() == 4);
    CHECK(a[0].length() == 1);
    CHECK(a[1].length() == 2);
    CHECK(a[2].length() == 3);
    CHECK(a[3].length() == 4);
}

TEST_CASE("problem20 with random arr")
{
    srand(time(0));
    Problems_13_22 pr;
    vector<string> a;
    for(int i = 0; i < 20; i++)
    {
        string s;
        for(int j = 0; j < rand()%100; j++)
            s.push_back('a');
        a.push_back(s);
    }
    pr.problem20(a);
    CHECK(a.size() == 20);
    for(int i = 1; i < 20; i++)
        CHECK(a[i-1].length() <= a[i].length());
}

TEST_CASE("problem21 with our arr")
{
    Problems_13_22 pr;
    vector<int> a = {3, -2, 5, 0 , -1};
    pr.problem21(a);
    CHECK(a.size() == 5);
    CHECK(a[0] == 0);
    CHECK(a[1] == -1);
    CHECK(a[2] == -2);
    CHECK(a[3] == 3);
    CHECK(a[4] == 5);
}

TEST_CASE("problem21 with random arr")
{
    srand(time(0));
    Problems_13_22 pr;
    vector<int> a;
    for(int i = 0; i < 20; i++)
        a.push_back(rand());
    pr.problem21(a);
    CHECK(a.size() == 20);
    for(int i = 1; i < 20; i++)
        CHECK(abs(a[i-1]) <= abs(a[i]));
}

TEST_CASE("problem22 with our arr")
{
    Problems_13_22 pr;
    vector<double> a = {0, 1, 2, 3, 4, 5};
    pr.problem22(a);
    CHECK(a.size() == 11);
    for(int i = 1; i < a.size(); i += 2)
        CHECK((a[i-1] < a[i] && a[i] < a[i+1]));
}

TEST_CASE("problem22 with random arr")
{
    srand(time(0));
    Problems_13_22 pr;
    vector<double> a;
    for(int i = 0; i < 20; i++)
        a.push_back(100*i+rand()%100);
    pr.problem22(a);
    CHECK(a.size() == 39);
    for(int i = 1; i < 39; i += 2)
        CHECK((a[i-1] < a[i] && a[i] < a[i+1]));
}
