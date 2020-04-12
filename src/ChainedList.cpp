#include "ChainedList.h"

template <typename T>
Item<T>::Item(Item<T>* prevItem, T* payload)
{
    ConnectPrevItem(prevItem);
}

template <typename T>
Item<T>* Item<T>::GetNextItem()
{
    return nextItemRef;
}

template <typename T>
Item<T>* Item<T>::GetPrevItem()
{
    return prevItemRef;
}

template <typename T>
void Item<T>::ConnectNextItem(Item<T>* nextItem)
{
    if( nextItemRef != nextItem)
    {
        nextItemRef = nextItem;
        nextItemRef->ConnectPrevItem(this);
    }
}

template <typename T>
void Item<T>::DisconnectNextItem()
{
    if( nextItemRef != nullptr )
    {
        nextItemRef->DisconnectPrevItem();
        nextItemRef = nullptr;
    }
}

template <typename T>
void Item<T>::ConnectPrevItem(Item<T>* prevItem)
{
    if( prevItemRef != prevItem)
    {
        prevItemRef = prevItem;
        prevItemRef->ConnectNextItem(this);
    }
}

template <typename T>
void Item<T>::DisconnectPrevItem()
{
    if( prevItemRef != nullptr )
    {
        prevItemRef->DisconnectPrevItem();
        prevItemRef = nullptr;
    }
}