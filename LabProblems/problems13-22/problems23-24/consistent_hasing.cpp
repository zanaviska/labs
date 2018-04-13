#include "consistent_hasing.h"

int ConsistentHash::gesh(string str)
{
    long long res = 0;
    long long stepin = 1;
    for(int i = 0; i < str.size(); i++, stepin = (stepin*47)%md)
        res = (res + (str[i]-'a'+1)*stepin)%md;
    return res;
}

void ConsistentHash::add_server()
{
    map<int, int> new_server;
    triple x({md, md, new_server});
    if(server.size() == 0)
    {
        x.left = 0;
        server.push_back(x);
        return;
    }
    auto pos = server.begin();
    for(auto i = server.begin(); i != server.end(); i++)
        if(i->arr.size() > pos->arr.size())
            pos = i;
    x.left = pos->right;
    x.right = pos->right;
    //cerr << "!\n";
    for(auto it = pos->arr.rbegin(); 2*x.arr.size() < pos->arr.size(); it--)
        //cerr << x.arr.size() << ' ' << pos->arr.size() << ' ' << it->first << ' ' << it->second << '\n',
        x.arr[it->first] = it->second;
    for(auto i:x.arr)
        pos->arr.erase(--(pos->arr.end()));
    x.left = x.arr.begin()->first;
    pos->right = x.left;
    server.insert(++pos, x);
}

void ConsistentHash::del_server()
{
    int serv = (int)server.size();
    if(serv == 1)
        throw length_error("too short list of servers");
    server[serv-2].right = md-1;
    for(auto i:server[serv-1].arr)
        server[serv-2].arr[i.first] = i.second;
    server.pop_back();
}

void ConsistentHash::add_node(string key, int data)
{
    int l = 0;
    int r = server.size();
    int mid;
    int hash = gesh(key);
    while(l < r)
    {
        mid = (l+r)/2;
        if(server[mid].left <= hash)
            l = mid+1;
        else
            r = mid;
    }
    l--;
    server[l].arr[hash] = data;
}

int ConsistentHash::get_node(string key)
{
    int l = 0;
    int r = server.size();
    int mid;
    int hash = gesh(key);
    while(l < r)
    {
        mid = (l+r)/2;
        if(server[mid].left <= hash)
            l = mid+1;
        else
            r = mid;
    }
    l--;
    auto it = server[l].arr.lower_bound(hash);
    if(it->first == hash)
        return it->second;
    throw invalid_argument("there is no node with that hash");
}

void ConsistentHash::del_node(string key)
{
    int l = 0;
    int r = server.size();
    int mid;
    int hash = gesh(key);
    while(l < r)
    {
        mid = (l+r)/2;
        if(server[mid].left <= hash)
            l = mid+1;
        else
            r = mid;
    }
    l--;
    auto it = server[l].arr.lower_bound(hash);
    if(it->first == hash)
        server[l].arr.erase(hash);
    else
        throw invalid_argument("there is no node with that key");
}
