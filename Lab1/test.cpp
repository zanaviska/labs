#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "doctest.h"
#include <bits/stdc++.h>
#include "double_linked.h"

using namespace std;


int f, s, t, amount, times, del;

TEST_CASE("Creating an empty list")
{

    List list1;
    List list2;
    CHECK(list1.size() == 0);
    CHECK(list2.size() == 0);
}

TEST_CASE("Accessing empty object's values")
{
    List list1;
    List list2;
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
    REQUIRE_NOTHROW(a.insert(3, 20));
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

TEST_CASE("inserting element to negative position")
{
    List list1;
    for(int i = 0; i < 5; i++)
        list1.push_back(i);
    REQUIRE_THROWS(list1.insert(-5, -5));
}

TEST_CASE("erasing element to negative position")
{
    List list1;
    for(int i = 0; i < 5; i++)
        list1.push_back(i);
    REQUIRE_THROWS(list1.erase(-5));
}

TEST_CASE("Merging empty and non-empty Lists")
{
    List list1 = List();//created List with which we will work in function
    List list2 = List();
    for(int i = 0; i < 10; i++)
        list1.push_back(i);
    List temp = list1;
    temp.merge(list2);
    CHECK(list1.begin() == temp.begin());
    CHECK(list1.end() == temp.end());
    CHECK(list1.size() == temp.size());

    list2.merge(list1);
    CHECK(list2.begin()->data == list1.begin()->data);
    CHECK(list2.rbegin()->data == list1.rbegin()->data);
    CHECK(list2.size() == list1.size());
    int i = 0;
    for(auto x = list1.begin(), y = list2.begin(); i < list1.size(); i++, x = x->next, y = y->next)
        CHECK(x->data == y->data);
}

TEST_CASE("Merging empty Lists")
{
    List a = List();//created List with which we will work in function
    List b = List();//created 2 any List
    a.merge(b);
    CHECK(a.size() == 0);
    CHECK(a.begin() == nullptr);
}

TEST_CASE("Inserting an object: empty and nonempty lists") // Checking whether the properties are up-to-date after the insertion
{
    int f = 10;
    int s = 20;
    List list1 = List();
    List list2 = List();
    list1.push_back(f);
    list2.push_back(f);
    
    CHECK(list1.begin()->data == f);
    CHECK(list2.begin()->data == f);
    CHECK(list1.begin() == list1.rbegin());
    CHECK(list2.begin() == list2.rbegin());
    
    list1.push_back(s);
    list2.push_back(s);
    
    CHECK(list1.rbegin()->data == s);
    CHECK(list2.rbegin()->data == s);
}

TEST_CASE("Updating list's size")
{
    List list1 = List();
    List list2 = List();
    int amount = 10;
    for( int i = 0; i <= amount; i++)
    {
        list1.push_back(i);
        list2.push_back(i);
    }
    int n = list1.size() + list2.size();

    list2.merge(list1);

    CHECK(list2.size() == n);
    auto now = list2.begin();
    for(int i = 0; i < n/2; i++, now = now->next)
        CHECK(now->data == i);
}
