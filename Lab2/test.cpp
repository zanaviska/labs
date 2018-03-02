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
    Tree tr;
    REQUIRE_NOTHROW(tr.push(-1, -1));
    for(int i = 0; i < 14; i++)
        tr.push(i, i);
    vector<int> temp;
    tr.get_all_values(temp);
    for(int i = 0; i < 15; i++)
        CHECK(i-1 == temp[i]);
}

TEST_CASE("Nothing wrong")
{
    Tree some_random_wrieble_that_must_has_some_strong_name;
    //CHECK(((some_random_wrieble_that_must_has_some_strong_name)));
}

TEST_CASE("getting all values")
{
    Tree tr;
    tr.push(8, 8);
    tr.push(4, 4);
    tr.push(2, 2);
    tr.push(1, 1);
    tr.push(3, 3);
    tr.push(6, 6);
    tr.push(5, 5);
    tr.push(7, 7);
    tr.push(12, 12);
    tr.push(10, 10);
    tr.push(9, 9);
    tr.push(11, 11);
    tr.push(14, 14);
    tr.push(13, 13);
    tr.push(15, 15);
    vector<int> temp;
    REQUIRE_NOTHROW(tr.get_all_values(temp));
    for(int i = 0; i < 15; i++)
        CHECK(i+1 == temp[i]);
}

TEST_CASE("find min")
{
    Tree tr;
    for(int i = 0; i < 15; i++)
        tr.push(i, i+1);
    REQUIRE_NOTHROW(tr.find_min());
    CHECK(tr.find_min() == 1);
}

TEST_CASE("find max")
{
    Tree tr;
    for(int i = 0; i < 15; i++)
        tr.push(i, i+1);
    REQUIRE_NOTHROW(tr.find_max());
    CHECK(tr.find_max() == 15);
}

TEST_CASE("find all leaves")
{
    Tree tr;
    tr.push(8, 9);
    tr.push(4, 10);
    tr.push(2, 11);
    tr.push(1, 1);
    tr.push(3, 2);
    tr.push(6, 12);
    tr.push(5, 3);
    tr.push(7, 4);
    tr.push(12, 13);
    tr.push(10, 14);
    tr.push(9, 5);
    tr.push(11, 6);
    tr.push(14, 15);
    tr.push(13, 7);
    tr.push(15, 8);
    vector<int> temp;
    REQUIRE_NOTHROW(tr.get_all_leave(temp));
    for(int i = 0; i < 8; i++)
        CHECK(temp[i] == i+1);
}
