#include "ConsHashing.h"

int ConsHashing::add_int(int x)
{
    int hash;
    string intstr = Stringify(node);
    for (unsigned int r = 0; r < replicas_; r++) {
        hash = hash_((nodestr + Stringify(r)).c_str());
        ring_[hash] = node;
    }
    return hash;
}
