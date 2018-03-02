#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "doctest.h"
#include <bits/stdc++.h>
#include "tree.h"

using namespace std;

TEST_CASE("Creating an empty tree")
{
    Tree tr;
	CHECK(tr.size() == 0);
}

TEST_CASE("pushing element")
{
    List a;
    REQUIRE_NOTHROW(a.push_back(-1));
    for(int i = 0; i < 5; i++)
        a.push_back(i);
    auto it = a.begin();
    for(int i = -1; i < 5; i++, it = it->next)
        CHECK(it->data == i);
    Tree tr;
    REQUIRE_NOTHROW(tr.push(-1, -1));
    for(int i = 0; i < 14; i++)
        CHECK(tr.push(i, i));
    vector<int> temp = tr.get_all_values();
    for(int i = 0; i < 15; i++)
        CHECK(i-1 == temp[i]);
}
