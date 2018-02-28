#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <bits/stdc++.h>
#include "double_linked.h"

using namespace std;

List list1;
List list2;

int f, s, t, amount, times, del;

TEST_CASE("Creating an empty list")
{
	CHECK(list1.size() == 0);
	CHECK(list2.size() == 0);
}

TEST_CASE("Accessing empty object's values")
{
	CHECK(list1.end() == nullptr);
	CHECK(list2.end() == nullptr);
	CHECK(list1.begin() == nullptr);
	CHECK(list2.begin() == nullptr);
}

TEST_CASE("Inserting an object: empty and nonempty lists") // Checking whether the properties are up-to-date after the insertion
{
	srand( time(0));
    int f = rand()%100;
    int s = rand()%100;
    list1.push_back(f);
	list2.push_back(f);

	CHECK(list1.begin()->data == f);
	CHECK(list2.begin()->data == f);
	CHECK(list1.begin() == list1.end());
	CHECK(list2.begin() == list2.end());

	list1.push_back(s);
	list2.push_back(s);

	CHECK(list1.end()->data == s);
	CHECK(list2.end()->data == s);
}

TEST_CASE("Updating list's size")
{
	amount = rand()%15;
	for( int i = 0; i <= amount ; i++)
	{
		list1.push_back(i);
		list2.push_back(i);
	}
	int n = list1.size() + list2.size();

	List list3 = merge(list1, list2);

	CHECK(list3.size() == n);
}

TEST_CASE("Random")
{
	times = rand()%20;
	del = rand()%10;

	for ( int i = 0 ; i < times; i++)
	{
       REQUIRE_NOTHROW(list1.push_back(i));
       REQUIRE_NOTHROW(list2.push_back(i));
	}

    for ( int i = 0 ; i < del; i++)
	{
		REQUIRE_NOTHROW(merge(list2, list1));
	}
}

