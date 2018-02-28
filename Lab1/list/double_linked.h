using namespace std;

class List
{
    struct Node
    {
        int data;
        shared_ptr<Node> prev;
        shared_ptr<Node> next;
        ~Node(){}
    };
    int ln;// size of list
public:
    shared_ptr<Node> first;
    shared_ptr<Node> last;
    List():first(nullptr), last(nullptr), ln(0){};
    push_back(int new_element_data)
    {
        ln++;
        auto temp = make_shared<Node>(); // new element of list
        temp->data = new_element_data;
        temp->next = nullptr;
        temp->prev = nullptr;
        if(first == nullptr)
        {
            first = temp;
            last = temp;
            return 0;
        }
        temp->prev = last;
        last->next = temp;
        last = temp;
    }

    push_front(int new_element_data)
    {
        ln++;
        auto temp = make_shared<Node>(); // new element of list
        temp->data = new_element_data;
        temp->next = nullptr;
        temp->prev = nullptr;
        if(first == nullptr)
        {
            first = temp;
            last = temp;
            return 0;
        }
        temp->next = first;
        first->prev = temp;
        first = temp;
    }

    insert(int pos, int new_element_data)
    {
        ln++;
        if(pos == 0) return push_front(new_element_data);
        if(pos == ln-1) return push_back(new_element_data);
        auto temp = make_shared<Node>(); // new element of list
        temp->data = new_element_data;
        shared_ptr<Node> now = first;
        for(int i = 0; i < pos; i++)
            now = now->next;
        now->prev->next = temp;
        temp->prev = now->prev;
        now->prev = temp;
        temp->next = now;
    }

    int size()
    {
        return ln;
    }

    shared_ptr<Node> begin()
    {
        return first;
    }

    shared_ptr<Node> end()
    {
        return last;
    }

     void erase(int position)
    {
        if(position == 0)
        {
            first = first->next;
            first->prev = nullptr;
            return;
        }
        if(position == ln-1)
        {
            last = last->prev;
            last->next = nullptr;
            return;
        }
        shared_ptr<Node> now = first;
        for(int i = 0; i < position; i++)
            now = now->next;
        now->prev->next = now->next;
        now->next->prev = now->prev;
    }

    friend List merge(List a, List b);

    ~List() {}
};

void print(List a)// a is name of output List
{
    for(auto it = a.first; it != nullptr; it = it->next)
    {
        cout << it->data << "(";
        if(it->prev != nullptr)
            cout << it->prev->data << ", ";
        if(it->next != nullptr)
            cout << it->next->data;
        cout << ")\n";
    }
}

List merge(List a, List b)// merge two List in one
{
    if(a.first == nullptr) return b;
    if(b.first == nullptr) return a;
    List res = a;
    res.last->next = b.first;
    res.last->next->prev = res.last;
    res.last = b.last;
    res.ln += b.ln;
    return res;
}
