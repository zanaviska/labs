#include <bits/stdc++.h>

using namespace std;

class EilerLoop
{
    vector< vector<int> > adjacency_matrix;
public:
    EilerLoop():
        adjacency_matrix({})
    {}
    vector< vector<int> > get_graph()
    {
        return adjacency_matrix;
    }
    EilerLoop(vector< vector<int> > a):
        adjacency_matrix(a)
    {
        for(int i = 0; i < adjacency_matrix.size(); i++)
        {
            if(adjacency_matrix[i].size() != adjacency_matrix.size())
                throw invalid_argument("It is not matrix");
            for(int j = 0; j < adjacency_matrix[i].size(); j++)
                if(adjacency_matrix[i][j] != adjacency_matrix[j][i])
                    throw invalid_argument("It is not graph");
        }
    }
    void create_eiler_loop();
    vector<int> get_eiler_loop();
    ~EilerLoop(){}
};
