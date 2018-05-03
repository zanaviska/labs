#include "tree.h"

using namespace std;

class Problems_1_12
{
public:
    Tree tree;
    Problems_1_12()
    {
        srand(time(0));
        for(int i = 0; i < 15; i++)
            tree.push(rand()%199-99);
    }
    Problems_1_12(vector<int> a)
    {
        for(auto i:a)
            tree.push(i);
    }
    vector<int> get_all_keys()
    {
        vector<int> res;
        tree.get_all_keys(res, tree.begin());
        return res;
    }
    vector<int> delete_kratni(int n);
    vector<int> delete_unpair();
    vector<int> delete_higer(int comp);
    vector<int> delete_lower(int comp);
    vector<int> delete_choosen(vector<int>);
    vector<int> delete_prime();
    vector<int> delete_folded();
    vector<int> delete_interval(int from, int to);
    vector<int> delete_sum_of_digit_more(int comp);
    vector<int> delete_sum_of_digit_less(int comp);
    vector<int> delete_sum_of_digit_interval(int from, int to);
    vector<int> delete_square();
    ~Problems_1_12(){};
};

