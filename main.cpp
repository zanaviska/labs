#include <bits/stdc++.h>

#define files(x) ((x != "")? (freopen(x".dat", "r", stdin), freopen(x".sol", "w", stdout)):(0))
#define fast ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);
#define pb push_back
#define ft first
#define sd second

using namespace std;

struct Node
{
    Node* prev;
    string name;
    Node* next;

};

class List
{
    public:
        Node* first;
        Node* last;
        List()
        {
            last = NULL;
            first = NULL;
        }
        push(string s)
        {
            Node* a = new Node();
            if(first == NULL)
            {
                cerr << '!';
                a->prev = a;
                a->name = s;
                a->next = a;
                first = a;
            }
            else
            {
                a->prev = a;
                a->name = s;
                a->next = a;
                last->next = a;
            }
            last = a;
        }
        print()
        {
            cout << '\n';
            Node* now = first;
            while(now != now->next)
            {
            cerr << '#';
                cout << now->name << '\n';
                now = now->next;
            }
            cout << now->name << '\n';
        }
};

void Lmerge(List &a, List &b)
{
    a.last->next = b.first;
    a.last = b.last;
    b.first = a.first;
}

int main()
{
    #ifdef ANDRII
        freopen("main.in", "r", stdin);
        freopen("main.out", "w", stdout);
    #else
        files("");
    #endif // ANDRII
    List a = List();
    a.push("first");
    a.print();
    a.push("second");
    a.print();
    List b = List();
    b.push("third");
    b.push("fourth");
    Lmerge(a, b);
    a.print();
}
