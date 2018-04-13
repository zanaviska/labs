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
    triple x({md-1, md-1, new_server});
    if(server.size() == 0)
        x.left = 0;
    server.push_back(x);
    int servers = (int)server.size();
    int per = lenght/servers;
    for(int i = servers-1; i > 0; i--)
        while(server[i].arr.size() < per)
        {
            server[i].arr[server[i-1].arr.rbegin()->first] = server[i-1].arr.rbegin()->second;
            server[i].left = server[i].arr.begin()->first;
            server[i-1].right = server[i-1].arr.rbegin()->first;
            server[i-1].arr.erase(server[i].arr.begin()->first);
        }
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
        cerr << '!';
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
    return -1;
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
}
