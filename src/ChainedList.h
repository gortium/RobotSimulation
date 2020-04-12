#include <vector>

template <typename T>
class Item
{
    public:
        Item(Item<T>* prevItem, T* payload);
        Item<T>* GetNextItem();
        Item<T>* GetPrevItem();
        void ConnectNextItem(Item<T>* nextItem);
        void DisconnectNextItem();
        void ConnectPrevItem(Item<T>* prevItem);
        void DisconnectPrevItem();
    
    private:
        Item<T>* nextItemRef = nullptr;
        Item<T>* prevItemRef = nullptr;
        void* payloadRef = nullptr;
};

template <typename T>
using ChainedList = std::vector<T, Item<T>>;
