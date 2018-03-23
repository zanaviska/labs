#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "doctest.h"
#include <bits/stdc++.h>
#include "tree.h"

using namespace std;

TEST_CASE("creating empty tree")
{
    Tree tr;
    CHECK(tr.size() == 0);
}

TEST_CASE("pushing element")
{
    Tree tr;
    for(int i = 0; i < 15; i++)
        tr.push(i, i);
    vector<int> temp;
    tr.get_all_values(temp);
    CHECK(temp.size() == 15);
    for(int i = 0; i < 15; i++)
        CHECK(i == temp[i]);
}

TEST_CASE("find min element")
{
    Tree tr;
    for(int i = 0; i < 15; i++)
        tr.push(i, 14-i);
    REQUIRE_NOTHROW(tr.find_min());
    CHECK(tr.find_min() == 0);
}

TEST_CASE("find max element")
{
    Tree tr;
    for(int i = 0; i < 15; i++)
        tr.push(i, 14-i);
    REQUIRE_NOTHROW(tr.find_max());
    CHECK(tr.find_max() == 14);
}

TEST_CASE("find min element in empty tree")
{
    Tree tr;
    REQUIRE_THROWS(tr.find_min());
}

TEST_CASE("find max element in empty tree")
{
    Tree tr;
    REQUIRE_THROWS(tr.find_max());
}

TEST_CASE("get all values")
{
    Tree tr;
    tr.push(4, 5);
    tr.push(2, 3);
    tr.push(1, 2);
    tr.push(3, 4);
    tr.push(6, 7);
    tr.push(5, 6);
    tr.push(7, 8);
    vector<int> temp;
    temp.clear();
    tr.get_all_values(temp);
    CHECK(temp.size() == 37);
    for(int i = 1; i < 8; i++)
        CHECK(temp[i-1] == i);
}

TEST_CASE("get all leaf")
{
    Tree tr;
    tr.push(4, 5);
    tr.push(2, 3);
    tr.push(1, 1);
    tr.push(3, 2);
    tr.push(6, 7);
    tr.push(5, 3);
    tr.push(7, 4);
    vector<int> temp;
    tr.get_all_leaf(temp, 1);
    CHECK(temp.size() == 4);
    for(int i = 0; i < 4; i++)
        CHECK(temp[i] == i+1);
}