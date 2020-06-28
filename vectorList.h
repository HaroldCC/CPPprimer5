//
// vectorList.h
//

#ifndef VECTORLIST_H
#define VECTORLIST_H

#include <vector>
#include <iostream>

template <typename T>
class VectorList;

/* 链表节点类 */
template <typename T>
class Node
{
public:
    T data;      // 数据
    int current; // 游标
};

const int SIZE = 10;

/* 静态链表 */
template <typename T>
class VectorList
{
    friend std::ostream &operator<<(std::ostream &out, const VectorList<T> &theList)
    {
        if (theList.is_empty())
        {
            out << "empty list.";
            return out;
        }

        int currentIndex = (*theList.m_vecLst[SIZE - 1]).current;
        out << "the list is: " << std::endl;
        for (int i = 1; i <= theList.m_length; ++i)
        {
            out << (theList.m_vecLst[currentIndex]->data) << " ";
            currentIndex = (*theList.m_vecLst[currentIndex]).current;
        }
        return out;
    }

private:
    std::vector<Node<T> *> m_vecLst;
    int m_length;

private:
    // 工具函数
    bool is_full() const;
    bool is_empty() const;
    int new_space();
    void delete_space(int index);

public:
    VectorList();
    ~VectorList();

    bool insert_val(const T &theValue, int index = 1);
    bool delete_val(T &theValue, int index = 1);
    int find(const T &theValue) const;
};

/*方法定义*/

#include <algorithm> // for for_each()

template <typename T>
VectorList<T>::VectorList()
{
    for (int index = 0; index < SIZE - 1; ++index)
    {
        Node<T> *node = new Node<T>();
        m_vecLst.push_back(node);
    }

    for (T index = 0; index < SIZE - 1; ++index)
        (*m_vecLst[index]).current = index + 1;

    Node<T> *node = new Node<T>();
    m_vecLst.push_back(node);
    (*m_vecLst[SIZE - 1]).current = 0;

    m_length = 0;
}

template <typename T>
VectorList<T>::~VectorList()
{
    std::for_each(m_vecLst.begin(), m_vecLst.end(),
                  [](Node<T> *node) { delete node; });
}

template <typename T>
bool VectorList<T>::insert_val(const T &theValue, int index)
{
    if (is_full())
    {
        std::cout << "the list is full." << std::endl;
        return false;
    }

    if (index < 1 || index > m_length + 1)
    {
        std::cout << "invalid index." << std::endl;
        return false;
    }

    int newSpace = new_space();
    int size = SIZE - 1;
    if (newSpace)
    {
        (*m_vecLst[newSpace]).data = theValue;
        for (int i = 1; i <= index - 1; ++i)
            size = (*m_vecLst[size]).current;

        (*m_vecLst[newSpace]).current = (*m_vecLst[size]).current;
        (*m_vecLst[size]).current = newSpace;
        ++m_length;
        return true;
    }
    return false;
}

template <typename T>
bool VectorList<T>::delete_val(T &theValue, int index)
{
    if (is_empty())
    {
        std::cout << "empty list." << std::endl;
        return false;
    }

    if (index < 1 || index > m_length)
    {
        std::cout << "invalid index." << std::endl;
        return false;
    }

    int size = SIZE - 1;
    int i = 1;
    while (i <= index - 1)
    {
        size = (*m_vecLst[size]).current;
        ++i;
    }
    i = (*m_vecLst[size]).current;
    (*m_vecLst[size]).current = (*m_vecLst[i]).current;
    theValue = (*m_vecLst[i]).data;
    delete_space(i);
    --m_length;
    return true;
}

template <typename T>
int VectorList<T>::find(const T &theValue) const
{
    if (is_empty())
    {
        std::cout << "empty list." << std::endl;
        return -1;
    }
    int index = 1;
    while (index != 0 && (*m_vecLst[(*m_vecLst[index]).current]).data != theValue)
    {
        index = (*m_vecLst[index]).current;
    }
    if (0 == index)
    {
        std::cout << "can't find the value " << theValue << " in the list." << std::endl;
        return -1;
    }

    ++index;

    return index;
}

template <typename T>
bool VectorList<T>::is_full() const
{
    if (m_length > SIZE - 2)
        return true;
    return false;
}

template <typename T>
bool VectorList<T>::is_empty() const
{
    return (0 == m_length);
}

template <typename T>
int VectorList<T>::new_space()
{
    int index = (*m_vecLst[0]).current;
    if ((*m_vecLst[0]).current)
    {
        (*m_vecLst[0]).current = (*m_vecLst[index]).current;
    }
    return index;
}

template <typename T>
void VectorList<T>::delete_space(int index)
{
    (*m_vecLst[index]).current = (*m_vecLst[0]).current;
    (*m_vecLst[0]).current = index;
}

#endif