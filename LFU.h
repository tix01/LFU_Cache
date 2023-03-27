#pragma once
#include<iostream>
#include<unordered_map>
#include<map>
using mul_t = std::multimap<int, int>;
using under_t = std::unordered_map <int, mul_t::iterator>;

class LFU
{
private:
    mul_t bac;
    under_t hash;
    int cap;
public:

    LFU(int capacity) :cap(capacity) {}
    mul_t::iterator min_elem() {};

    int get(int key) {};

    void put(int key) {};
};

