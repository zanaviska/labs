#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "doctest.h"
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

TEST_CASE("pushing element")
{
    List a;//created List with which we will work in function
    REQUIRE_NOTHROW(a.push_back(-1));
    for(int i = 0; i < 5; i++)
        a.push_back(i);
    auto it = a.begin();
    for(int i = -1; i < 5; i++, it = it->next)
        CHECK(it->data == i);

    List b;//created List with which we will work in function
    REQUIRE_NOTHROW(b.push_front(-1));
    for(int i = 0; i < 5; i++)
        b.push_front(i);
    it = b.begin();
    for(int i = -1; i < 5; i++, it = it->next)
        CHECK(it->data == 3-i);
}

TEST_CASE("inserting element")
{
    List a;//created List with which we will work in function
    for(int i = 0; i < 10; i++)
        a.push_back(i);
    a.insert(3, 20);
    auto now = a.begin();
    for(int i = 0; i < 3; i++, now = now->next)
        CHECK(now->data == i);
    CHECK(now->data == 20);
    now = now->next;
    for(int i = 4; i < 11; i++, now = now->next)
        CHECK(now->data == i-1);
}

TEST_CASE("deleting element")
{
    List a;//created List with which we will work in function
    for(int i = 0; i < 10; i++)
        a.push_back(i);
    CHECK_NOTHROW(a.erase(5));

    auto now = a.begin();
    for(int i = 0; i < 5; i++, now = now->next)
        CHECK(now->data == i);
    for(int i = 6; i < 10; i++, now = now->next)
        CHECK(now->data == i);
}

TEST_CASE("Merging empty and non-empty Lists")
{
    List a;//created List with which we will work in function
    List b;
    for(int i = 0; i < 10; i++)
        a.push_back(i);

    REQUIRE_NOTHROW(merge(a, b));
    List uni = merge(a, b);
    CHECK(uni.begin() == a.begin());
    CHECK(uni.end() == a.end());
    CHECK(uni.size() == a.size());

    REQUIRE_NOTHROW(merge(b, a));
    uni = merge(b, a);
    CHECK(uni.begin() == a.begin());
    CHECK(uni.end() == a.end());
    CHECK(uni.size() == a.size());
    int i = 0;
    for(auto x = a.begin(), y = uni.begin(); i < a.size(); i++, x = x->next, y = y->next)
        CHECK(x->data == y->data);
}

TEST_CASE("Merging empty Lists")
{
    List a;//created List with which we will work in function
    List b;//created 2 any List
    List unity = merge(a, b);
    CHECK(unity.size() == 0);
    CHECK(unity.begin() == nullptr);
}

TEST_CASE("Inserting an object: empty and nonempty lists") // Checking whether the properties are up-to-date after the insertion
{
    int f = 10;
    int s = 20;
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
    int amount = 10;
	for( int i = 0; i <= amount; i++)
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
	times = 10;
	int mer = 5;

	for (int i = 0 ; i < times; i++)
	{
       REQUIRE_NOTHROW(list1.push_back(i));
       REQUIRE_NOTHROW(list2.push_back(i));
	}

    for (int i = 0 ; i < del; i++)
	{
		REQUIRE_NOTHROW(list1 = merge(list2, list1));
	}
}

