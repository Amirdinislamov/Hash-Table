#include "GroupContainer.h"

GroupContainer::GroupContainer(MemoryManager& mem) : Container(mem)
{
    size_of_arr = 10;
    arr_items = (List**)_memory.allocMem(size_of_arr * sizeof(List*));
    for (int i = 0; i < size_of_arr; i++)
    {
        arr_items[i] = new List(_memory);
    }
}
size_t d_hash(const void* key, size_t keySize)
{
    const uint8_t* data = static_cast<const uint8_t*>(key);
    size_t hash = 5381;

    for (size_t i = 0; i < keySize; i++) {
        hash = ((hash << 5) + hash) + data[i];
    }

    return hash;
}
size_t GroupContainer::hash_func(void* key, size_t keySize)
{
    return d_hash(key, keySize);
}
int GroupContainer::size()
{
    return quantity_elem;
}
size_t GroupContainer::max_bytes()
{
    return _memory.size();
}
void GroupContainer::clear()
{
    if (quantity_elem == 0)
    {
        return;
    }
    for (int i = 0; i < size_of_arr; i++)
    {
        if (!arr_items[i]->empty())
        {
            arr_items[i]->clear();
        }
    }
    quantity_elem = 0;
}
bool GroupContainer::empty()
{
    if (quantity_elem == 0) {
        return true;
    }
    else {
        return false;
    }
}
