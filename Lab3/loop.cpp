#include <bits/stdc++.h>
#include "loop.h"

using namespace std;

void create_eiler_loop(vector< vector<int> > &adjacency_matrix, vector<int> &stepin, vector<int> unpair)
{
    cout << "There isn't Eiler loop. To make Eiler loop you have to add next edges:\n";
    for(int i = 2; i < (int)unpair.size(); i+=2)
    {
        cout << unpair[i] << ' ' << unpair[i+1] << '\n';
        stepin[unpair[i]]++;
        stepin[unpair[i+1]]++;
        adjacency_matrix[unpair[i]][unpair[i+1]]++;
        adjacency_matrix[unpair[i+1]][unpair[i]]++;
    }
}

vector<int> dfs(vector< vector<int> > &adjacency_matrix, int now, int finish, vector<int>& stepin)
{
    cerr << now << '\n';
    if(now == finish && stepin[now] == 0)
        return {now};
    for(int i = 0; i < adjacency_matrix.size(); i++)
        if(adjacency_matrix[now][i] > 0)
        {
            adjacency_matrix[now][i]--;
            adjacency_matrix[i][now]--;
            stepin[now]--;
            stepin[i]--;
            vector<int> way = dfs(adjacency_matrix, i, finish, stepin);
            way.push_back(now);
            return way;
        }
    return {-2};
}

vector<int> get_eiler_loop(vector< vector<int> > adjacency_matrix, int graph_size)
{
    vector<int> unpair;
    vector<int> stepin(graph_size);
    for(int i = 0; i < graph_size; i++)
    {
        int cnt = 0;
        for(int j = 0; j < graph_size; j++)
            cnt += adjacency_matrix[i][j];
        if(cnt&1)
            unpair.push_back(i);
        stepin[i] = cnt;
    }
    if(unpair.size() > 2)
        create_eiler_loop(adjacency_matrix, stepin, unpair);
    int start = 0;
    int finish = 0;
    if(unpair.size() >= 2)
    {
        start = unpair[0];
        finish = unpair[1];
    }
    vector<int> res;
    res.reserve(graph_size*graph_size);
    auto insert_pos = res.begin();
    while(start != -1 && finish != -1)
    {
        cerr << start << ' ' << finish << '\n';
        vector<int> add_to_res = dfs(adjacency_matrix, start, finish, stepin);
        if(res.empty())
        {
            res = add_to_res;
            //insert_pos = res.begin();
        }
        else
            res.insert(insert_pos, add_to_res.begin(), --add_to_res.end());
        start = -1;
        finish = -1;
        for(auto i:res)
            cerr << i << ' ';
        cerr << '\n';
        for(auto i:adjacency_matrix)
        {
            for(auto j:i)
                cerr << j << ' ';
            cerr << '\n';
        }

        while(insert_pos != res.end())
        {
            cerr << '!' << *insert_pos << '\n';
            if(stepin[*insert_pos] != 0)
            {
                start = *insert_pos;
                finish = *insert_pos;
                break;
            }
            insert_pos++;
        }
        system("pause");
    }
    return res;
}
