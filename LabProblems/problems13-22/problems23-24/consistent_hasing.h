#include <bits/stdc++.h>

using namespace std;

class ConsistentHash
{
    struct triple
    {
        int left;
        int right;
        map<int, int> arr;
    };
    const int md = 1e9+7;
    vector<triple> server;
    int lenght;
    int gesh(string data);
public:
    ConsistentHash():
        lenght(0),
        server({{0, md, {}}})
    {};
    void add_server();
    void del_server();
    void add_node(string key, int data);
    int get_node(string key);
    void del_node(string key);
    ~ConsistentHash()
    {
        server.clear();
    }
};
