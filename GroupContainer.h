#pragma once
#include "Container.h"
#include "List.h"
#define BASE 65521 
using namespace std;

class GroupContainer : public Container
{
protected:
    size_t size_of_arr;
    size_t quantity_elem;
    List** arr_items;
public:
    GroupContainer(MemoryManager& mem);
    size_t hash_func(void* key, size_t keySize);
    int size() override;
    size_t max_bytes() override;
    void clear() override;
    bool empty() override;
};