//
// Created by dai on 2024/5/16.
//
#pragma once
#ifndef CPP_PROJECT_LIST_H
#define CPP_PROJECT_LIST_H



#include <iostream>
#include <fstream>
template<typename T>
class List {
private:
    /**
     * Node class
     */
    class Node {
    public:
        T data;
        Node *next;
        Node *prev;

        Node() : data(), next(nullptr), prev(nullptr) {}

        explicit Node(T data) : data(data), next(nullptr), prev(nullptr) {}
    };

    /**
     * List information
     */
    Node *head;
    Node *tail;
    unsigned int size;
public:
    /**
     * 构造与析构函数
     */
    List();                     //默认构造函数
    explicit List(T data);               //带参数的构造函数
    List(const List<T> &list);  //拷贝构造函数
    ~List();                    //析构函数

    /**
     * 运算符重载
     */
    List<T> &operator=(const List<T> &list); //赋值运算符重载
    template<class U>
    friend bool operator==(const List<U> &list1, const List<U> &list2); //比较运算符重载
    template<class U>
    friend List<U> &operator+(const List<U> &list1, const List<U> &list2); //加法运算符重载
    template<class U>
    friend std::ostream &operator<<(std::ostream &os, const List<U> &list); //输出运算符重载
    template<class U>
    friend std::istream &operator>>(std::istream &is, List<U> &list); //输入运算符重载
    template<class U>
    friend std::ofstream &operator<<(std::ofstream &os, const List<U> &list); //输出运算符重载
    template<class U>
    friend std::ifstream &operator>>(std::ifstream &is, List<U> &list); //输入运算符重载

    /**
     * 常见链表操作
     */
    void pushBack(T data);     //尾插
    void pushFront(T data);    //头插
    void popBack();            //尾删
    void popFront();           //头删

    void insert(T data, int index);     //插入
    void erase(int index);              //删除
    void clear();                       //清空

    T get(int index);                   //获取
    void set(int index, T data);        //修改
    unsigned int getSize();             //获取链表长度
    bool isEmpty();                     //判断是否为空
    int find(T data);                   //查找
    void print();                       //打印

    /**
     * 链表类外其余操作
     */
    template<class U>
    friend List<U> find(const List<U> &list, T data); //精确查找
    template<class U>
    friend List<U> find(const List<U> &list, T data, bool (*cmp)(U, U)); //自定义查找
    template<class U>
    friend List<U> sort(List<U> &lists); //排序
    template<class U>
    friend List<U> sort(List<U> &lists, bool (*cmp)(U, U)); //自定义排序
};



/**
* 构造与析构函数
*/
template<typename T>
List<T>::List() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<typename T>
List<T>::List(T data) {
    head = new Node(data);
    tail = head;
    size = 1;
}

template<typename T>
List<T>::List(const List<T> &lists) {
    head = nullptr;
    tail = nullptr;
    size = 0;

    Node *ptr = lists.head;
    while (ptr != nullptr) {
        Node *node = new Node(ptr->data);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        ptr = ptr->next;
        size++;
    }
}

template<typename T>
List<T>::~List() {
    Node *ptr = head;
    Node *temp;
    while (ptr != nullptr) {
        temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
}

/**
 * 运算符重载
 */
template<typename T>
List<T>& List<T>::operator=(const List<T> &list) {
    if(this==&list) {
        return *this;
    }
    clear();
    Node *ptr = list.head;
    while (ptr != nullptr) {
        pushBack(ptr->data);
        ptr = ptr->next;
    }
    return *this;
}

template<typename T>
bool operator==(const List<T> &list1, const List<T> &list2) {
    if (list1.size != list2.size) {
        return false;
    }
    typename List<T>::Node *ptr1 = list1.head;
    typename List<T>::Node *ptr2 = list2.head;
    while (ptr1 != nullptr) {
        if (ptr1->data != ptr2->data) {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}

template<typename T>
List<T>& operator+(const List<T> &list1, const List<T> &list2) {
    List<T> newList;
    newList = new List<T>(list1);
    typename List<T>::Node *ptr = list2.head;
    while (ptr != nullptr) {
        newList.pushBack(ptr->data);
        ptr = ptr->next;
    }
    return *newList;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const List<T> &list) {
    if(list.head == nullptr) {
        return os;
    }
    typename List<T>::Node *ptr = list.head;
    while (ptr != nullptr) {
        os << ptr->data << std::endl;
        ptr = ptr->next;
    }
    return os;
}

template<typename T>
std::istream &operator>>(std::istream &is, List<T> &list) {
    T data;
    is >> data;
    list.pushBack(data);
    return is;
}

template<typename T>
std::ofstream &operator<<(std::ofstream &os, const List<T> &list) {
    if(list.head == nullptr) {
        return os;
    }
    typename List<T>::Node *ptr = list.head;
    while (ptr != nullptr) {
        os << ptr->data << std::endl;
        ptr = ptr->next;
    }
    return os;
}
template<typename T>
std::ifstream &operator>>(std::ifstream &is, List<T> &list) {
    T data;
    is >> data;
    list.pushBack(data);
    return is;
}
/**
 * 常见链表操作
 */

template<typename T>
void List<T>::pushBack(T data) {
    Node *node = new Node(data);
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    size++;
}

template<typename T>
void List<T>::pushFront(T data) {
    Node *node = new Node(data);
    if (head == nullptr) {
        head = node;
        tail = node;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
    size++;
}

template<typename T>
void List<T>::popBack() {
    if (head == nullptr) {
        return;
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node *node = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete node;
    }
    size--;
}

template<typename T>
void List<T>::popFront() {
    if (head == nullptr) {
        return;
    }
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        Node *node = head;
        head = head->next;
        head->prev = nullptr;
        delete node;
    }
    size--;
}

template<typename T>
void List<T>::insert(T data, int index) {
    if (index < 0 || index > size) {
        return;
    }
    if (index == 0) {
        pushFront(data);
    } else if (index == size) {
        pushBack(data);
    } else {
        Node *node = new Node(data);
        Node *ptr = head;
        for (int i = 0; i < index; i++) {
            ptr = ptr->next;
        }
        node->next = ptr;
        node->prev = ptr->prev;
        ptr->prev->next = node;
        ptr->prev = node;
        size++;
    }
}

template<typename T>
void List<T>::erase(int index) {
    if (index < 0 || index >= size) {
        return;
    }
    Node *ptr = head;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    if (ptr == head) {
        popFront();
    } else if (ptr == tail) {
        popBack();
    } else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
        size--;
    }
}

template<typename T>
void List<T>::clear() {
    Node *ptr = head;
    Node *temp;
    while (ptr != nullptr) {
        temp = ptr->next;
        delete ptr;
        ptr = temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<typename T>
T List<T>::get(int index) {
    if (index < 0 || index >= size) {
        return T();
    }
    Node *ptr = head;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    return ptr->data;
}

template<typename T>
void List<T>::set(int index, T data) {
    if (index < 0 || index >= size) {
        return;
    }
    Node *ptr = head;
    for (int i = 0; i < index; i++) {
        ptr = ptr->next;
    }
    ptr->data = data;
}

template<typename T>
unsigned int List<T>::getSize() {
    return size;
}

template<typename T>
bool List<T>::isEmpty() {
    return size == 0;
}

template<typename T>
int List<T>::find(T data) {
    Node *ptr = head;
    int index = 0;
    while (ptr != nullptr) {
        if (ptr->data == data) {
            return index;
        }
        ptr = ptr->next;
        index++;
    }
    return -1;
}

template<typename T>
void List<T>::print() {
    Node *ptr = head;
    while (ptr != nullptr) {
        std::cout << ptr->data << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

/**
 * 链表类外其余操作
 */

template<typename T>
List<T> find(const List<T> &list, T data) {
    List<T> newList;
    typename List<T>::Node *ptr = list.head;
    while (ptr != nullptr) {
        if (ptr->data == data) {
            newList.pushBack(ptr->data);
        }
        ptr = ptr->next;
    }
    return newList;
}

template<typename T>
List<T> find(const List<T> &list, T data, bool (*cmp)(T, T)) {
    List<T> newList;
    typename List<T>::Node *ptr = list.head;
    while (ptr != nullptr) {
        if (cmp(ptr->data, data)) {
            newList.pushBack(ptr->data);
        }
        ptr = ptr->next;
    }
    return newList;
}

template<typename T>
List<T> sort(List<T> &lists) {
    List<T> newList(lists);
    typename List<T>::Node *ptr1 = newList.head;
    while (ptr1 != nullptr) {
        typename List<T>::Node *ptr2 = ptr1->next;
        while (ptr2 != nullptr) {
            if (ptr1->data > ptr2->data) {
                T temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return newList;
}

template<typename T>
List<T> sort(List<T> &lists, bool (*cmp)(T, T)) {
    List<T> newList(lists);
    typename List<T>::Node *ptr1 = newList.head;
    while (ptr1 != nullptr) {
        typename List<T>::Node *ptr2 = ptr1->next;
        while (ptr2 != nullptr) {
            if (cmp(ptr1->data, ptr2->data)) {
                T temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return newList;
}

#endif //CPP_PROJECT_LIST_H
