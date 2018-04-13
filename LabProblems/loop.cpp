#include "loop.h"

using namespace std;

void EilerLoop::create_eiler_loop()
{
    vector<int> unpair = {0};
    for(auto i:adjacency_matrix)
    {
        for(auto j:i)
            unpair.back() += j;
        if(unpair.back()&1)
            unpair.push_back(0);
        else
            unpair.back() = 0;
    }
    unpair.pop_back();
    if(unpair.size() < 3) return;
    for(int i = 2; i < (int)unpair.size(); i+=2)
    {
        //cout << unpair[i] << ' ' << unpair[i+1] << '\n';
        adjacency_matrix[unpair[i]][unpair[i+1]]++;
        adjacency_matrix[unpair[i+1]][unpair[i]]++;
    }
}

vector<int> dfs(vector< vector<int> > &adjacency_matrix, int now, int finish, vector<int>& stepin)
{
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

vector<int> EilerLoop::get_eiler_loop()
{
    vector< vector<int> > graph = adjacency_matrix;
    int graph_size = adjacency_matrix.size();
    vector<int> stepin(graph_size);
    for(int i = 0; i < adjacency_matrix.size(); i++)
        for(int j = 0; j < adjacency_matrix[i].size(); j++)
            stepin[i] += adjacency_matrix[i][j];
    int start = 0;
    int finish = 0;
    for(int i = 0; i < graph_size; i++)
        if(stepin[i]&1)
            finish = start,
            start = i;
    vector<int> res;
    res.reserve(graph_size*graph_size);
    auto insert_pos = res.begin();
    while(start != -1 && finish != -1)
    {
        vector<int> add_to_res = dfs(graph, start, finish, stepin);
        if(res.empty())
            res = add_to_res;
        else
            res.insert(insert_pos, add_to_res.begin(), --add_to_res.end());
        start = -1;
        finish = -1;

        while(insert_pos != res.end())
        {
            if(stepin[*insert_pos] != 0)
            {
                start = *insert_pos;
                finish = *insert_pos;
                break;
            }
            insert_pos++;
        }
    }
    return res;
}
