#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "doctest.h"
#include "loop.h"

using namespace std;

TEST_CASE("creating eiler loop from empty graph")
{
    vector< vector<int> > x =
    {
        {0, 0},
        {0, 0}
    };
    EilerLoop loop = EilerLoop(x);
    loop.create_eiler_loop();
    CHECK(loop.get_graph() == x);
}

TEST_CASE("exception")
{
    vector< vector<int> > x =
    {
        {0, 0},
        {0}
    };
    vector< vector<int> > y =
    {
        {0, 0},
        {1, 0}
    };
    vector< vector<int> > z =
    {
        {0, 0},
        {0, 0}
    };
    REQUIRE_THROWS(EilerLoop loop = EilerLoop(x));
    REQUIRE_THROWS(EilerLoop loop = EilerLoop(y));
    REQUIRE_NOTHROW(EilerLoop loop = EilerLoop(z));
}

TEST_CASE("get eiler loop")
{
    vector<vector<int> > x =
    {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 2},
        {0, 0, 0, 2, 0}
    };
    EilerLoop loop = EilerLoop(x);
    vector<int> ans = loop.get_eiler_loop();
    for(int i = 1; i < ans.size(); i++)
        x[ans[i]][ans[i-1]]--,
        x[ans[i-1]][ans[i]]--;
    for(auto i:x)
        for(auto j:i)
            CHECK(j == 0);
}

TEST_CASE("get eiler loop with empty vertex")
{
    vector<vector<int> > x =
    {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    EilerLoop loop = EilerLoop(x);
    vector<int> ans = loop.get_eiler_loop();
    for(int i = 1; i < ans.size(); i++)
        x[ans[i]][ans[i-1]]--,
        x[ans[i-1]][ans[i]]--;
    for(auto i:x)
        for(auto j:i)
            CHECK(j == 0);
}

TEST_CASE("get eiler loop in empty graph")
{
    vector<vector<int> > x =
    {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    vector<int> ans;
    EilerLoop loop = EilerLoop(x);
    ans = loop.get_eiler_loop();
    for(int i = 1; i < ans.size(); i++)
        x[ans[i]][ans[i-1]]--,
        x[ans[i-1]][ans[i]]--;
    for(auto i:x)
        for(auto j:i)
            CHECK(j == 0);
}
