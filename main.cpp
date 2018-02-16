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
                a->prev = a;
                a->name = s;
                a->next = a;
                first = a;
            }
            else
            {
                a->prev = last;
                a->name = s;
                a->next = a;
                last->next = a;
            }
            last = a;
        }
        print() // print al members of List from first to last;
        {
            cout << '\n';
            Node* now = first;
            while(now != now->next)
            {
                cout << now->name << '\n';
                now = now->next;
            }
            cout << now->name << '\n';
        }
};

void Lmerge(List &a, List &b)// merge two List in one
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
    int n, m;//n - size of first List, m - size of second List
    cin >> n >> m;
    List a = List();
    List b = List();
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        a.push(s);
    }
    a.print();
    for(int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        b.push(s);
    }
    b.print();
    Lmerge(a, b);
    cout << "Merged:\n";
    a.print();
}
