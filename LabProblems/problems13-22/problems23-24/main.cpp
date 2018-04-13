#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "hash_table.h"
#include "consistent_hasing.h"
#include "doctest.h"

using namespace std;

TEST_CASE("pushing element to table")
{
    HashTable table = HashTable();
    string s1 = "abc";
    table.push(s1, 1);
    table.push("bbc", 2);
    CHECK(table.get(s1) == 1);
}

TEST_CASE("geting element")
{
    HashTable table = HashTable();
    string s1 = "a";
    for(int i = 0; i < 5; i++)
    {
        table.push(s1, i);
        s1[0]++;
    }
    s1 = "a";
    for(int i = 0; i < 5; i++)
    {
        REQUIRE_NOTHROW(table.get(s1));
        CHECK(table.get(s1) == i);
        s1[0]++;
    }
}

TEST_CASE("pushing element with the same hash")
{
    HashTable table;
    string s1 = "abc";
    string s2 = "bca";
    table.push(s1, 3);
    table.push(s2, 5);
    CHECK(table.get(s1) == 3);
    CHECK(table.get(s2) == 5);
}

TEST_CASE("getting unreal element")
{
    HashTable table;
    table.push("a", 1);
    REQUIRE_THROWS(table.get("b"));
}

TEST_CASE("erasing element")
{
    HashTable table;
    table.push("abc", 6);
    REQUIRE_NOTHROW(table.erase("abc"));
    REQUIRE_THROWS(table.get("abc"));
    table.push("abc", 5);
    CHECK(table.get("abc") == 5);
}

TEST_CASE("erasing element with the same hash")
{
    HashTable table;
    table.push("abc", 6);
    table.push("bca", 7);
    REQUIRE_NOTHROW(table.erase("abc"));
    REQUIRE_THROWS(table.get("abc"));
    REQUIRE_NOTHROW(table.get("bca"));
    CHECK(table.get("bca") == 7);
}

TEST_CASE
