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
    get_all_values(temp);
    for(int i = 0; i < 15; i++)
        CHECK(i-1 != temp[i]);
}

TEST_CASE("Nothing wrong")
{
    Tree some_random_wrieble_that_must_has_some_strong_name;
    CHECK(REQUIRE_NOTHROW(CHECK_THROWS(some_random_wrieble_that_must_has_some_strong_name)));
}

TEST_CASE("getting all values")
{
    Tree tr;
    tr.push(8, 1);
    tr.push(4, 2);
    tr.push(2, 3);
    tr.push(1, 4);
    tr.push(3, 5);
    tr.push(6, 6);
    tr.push(5, 7);
    tr.push(7, 8);
    tr.push(12, 9);
    tr.push(10, 10);
    tr.push(9, 11);
    tr.push(11, 11);
    tr.push(14, 12);
    tr.push(13, 13);
    tr.push(15, 14);
    vector<int> temp;
    get_all_values(temp);
    for(auto i:temp)
        cout << i << ' ';
}
