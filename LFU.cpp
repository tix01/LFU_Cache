#include "LFU.h"
mul_t::iterator LFU::min_elem() {
     return bac.begin();
}
int LFU::get(int key) {
    auto touch = hash.find(key);
    if (touch == hash.end()) {
        return false;
    }
    mul_t::iterator it = touch->second;
    int temp = it->first + 1;
    bac.erase(it);
    it = bac.insert(std::pair<int, int>(temp, key));
    hash[key] = it;
}
void LFU::put(int key) {
    if (bac.size() >= cap) {
        mul_t::iterator d_elem = min_elem();
        hash.erase(d_elem->second);
        bac.erase(d_elem);
    }
    mul_t::iterator it = bac.insert(std::pair<int, int>(1, key));
    hash[key] = it;
}