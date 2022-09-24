
#include <map>
#include <iostream>
#include <list>
#include "Header.h"
#include <bitset>
#include <set>
#include <unordered_map>
#include <string>
#include <intrin.h>

//#include <pair>

template<class keyType, class valueType>
class AVL {
public:
    struct node {
        //int key;
        //int value;
        std::pair<keyType, valueType> date;
        int height;
        node* left;
        node* right;

        node(std::pair<keyType, valueType> p) {
            height = 1;
            date = p;
            left = nullptr;
            right = nullptr;
        }

        void inorder(std::list<node*>& arr)
        {

            if (left)
            {
                left->inorder(arr);
            }

            arr.push_back(this);

            if (right)
            {
                right->inorder(arr);
            }
        }

        void clear()
        {
            if (left)
            {
                left->clear();
            }

            if (right)
            {
                right->clear();
            }

            delete this;
        }
    };

    void insert(std::pair<keyType, valueType> input)
    {
        root = insertUtil(root, input);
    }

    void remove(keyType x)
    {
        root = removeUtil(root, x);
    }
    node* search(keyType x)
    {
        return searchUtil(root, x);
    }

    node* parent(node* desired, node* r)
    {
        if (!r)
        {
            return nullptr;
        }

        keyType k = r->date.first;

        if (r->right == desired || r->left == desired)
        {
            return r;
        }

        if (k > desired->date.first)
        {
            return parent(desired, r->left);
        }

        if (k < desired->date.first)
        {
            return parent(desired, r->right);
        }
    }

private:

    int height(node* head)
    {
        if (!head)
        {
            return 0;
        }

        return head->height;
    }

    node* rightRotation(node* head)
    {
        node* newhead = head->left;
        head->left = newhead->right;
        newhead->right = head;

        head->height = 1 + std::max(height(head->left), height(head->right));
        newhead->height = 1 + std::max(height(newhead->left), height(newhead->right));

        return newhead;
    }

    node* leftRotation(node* head)
    {
        node* newhead = head->right;
        head->right = newhead->left;
        newhead->left = head;

        head->height = 1 + std::max(height(head->left), height(head->right));
        newhead->height = 1 + std::max(height(newhead->left), height(newhead->right));

        return newhead;
    }

    node* insertUtil(node* head, std::pair<keyType, valueType> input)
    {
        if (!head)
        {
            n += 1;
            node* temp = new node(input);

            return temp;
        }

        if (input.first < head->date.first)
        {
            head->left = insertUtil(head->left, input);
        }
        else if (input.first > head->date.first)
        {
            head->right = insertUtil(head->right, input);
        }

        head->height = 1 + std::max(height(head->left), height(head->right));

        int bal = height(head->left) - height(head->right);

        if (bal > 1)
        {
            if (input.first < head->left->date.first)
            {
                return rightRotation(head);
            }
            else
            {
                head->left = leftRotation(head->left);

                return rightRotation(head);
            }
        }
        else if (bal < -1)
        {
            if (input.first > head->right->date.first)
            {
                return leftRotation(head);
            }
            else
            {
                head->right = rightRotation(head->right);

                return leftRotation(head);
            }
        }

        return head;
    }

    node* removeUtil(node* head, keyType x)
    {
        if (!head) return nullptr;

        if (x < head->date.first)
        {
            head->left = removeUtil(head->left, x);
        }
        else if (x > head->date.first)
        {
            head->right = removeUtil(head->right, x);
        }
        else
        {
            node* r = head->right;

            if (!head->right)
            {
                node* l = head->left;
                delete(head);
                head = l;
            }
            else if (!head->left)
            {
                delete(head);
                head = r;
            }
            else
            {
                while (r->left != NULL) r = r->left;
 
                head->date = r->date;
                head->right = removeUtil(head->right, r->date.first);
            }
        }

        if (head == NULL)
        {
            return head;
        }

        head->height = 1 + std::max(height(head->left), height(head->right));

        int bal = height(head->left) - height(head->right);

        if (bal > 1)
        {
            if (height(head->left) >= height(head->right))
            {
                return rightRotation(head);
            }
            else
            {
                head->left = leftRotation(head->left);

                return rightRotation(head);
            }
        }
        else if (bal < -1)
        {
            if (height(head->right) >= height(head->left))
            {
                return leftRotation(head);
            }
            else
            {
                head->right = rightRotation(head->right);

                return leftRotation(head);
            }
        }

        return head;
    }

    node* searchUtil(node* head, keyType x)
    {
        if (!head)
        {
            return nullptr;
        }

        keyType k = head->date.first;

        if (k == x)
        {
            return head;
        }

        if (k > x)
        {
            return searchUtil(head->left, x);
        }

        if (k < x)
        {
            return searchUtil(head->right, x);
        }
    }

    void clear()
    {
        root->clear();
    }

public:
    node* root = nullptr;
    int n;
};


template<class keyType, class ValueType>
class map
{
    AVL<keyType, ValueType> tree;
    int sz = 0;

public:
    void insert(std::pair<keyType, ValueType> input)
    {
        if (this->search(input.first).node)
        {
            return;
        }

        tree.insert(input);

        sz++;
    }

    void erase(keyType key)
    {
        if (!(this->search(key).node))
        {
            return;
        }
        
        tree.remove(key);

        sz--;
    }

    int size()
    {
        return sz;
    }



    struct list_iterator
    {
        AVL<keyType, ValueType> tree;
        std::list<typename AVL<keyType, ValueType>::node*> list;
        typename std::list<typename AVL<keyType, ValueType>::node*>::iterator it;

        list_iterator(AVL<keyType, ValueType> otherTree, bool begin)
        {
            tree = otherTree;

            tree.root->inorder(list);

            if (begin)
            {
                it = list.begin();

                typename AVL<keyType, ValueType>::node* temp = nullptr;
                list.push_back(temp);
            }
            else
            {
                typename AVL<keyType, ValueType>::node* temp = nullptr;

                list.push_back(temp);

                it = list.end();
                it--;
            }
        }

        list_iterator& operator++()
        {
            it++;

            return *this;
        }

        list_iterator& operator--()
        {
            it--;

            return *this;
        }

        bool operator==(const list_iterator& other)
        {
            return *it == *(other.it);
        }

        bool operator!=(const list_iterator& other)
        {
            return !(*this == other);
        }

        std::pair<keyType, ValueType>* operator->()
        {
            return &((*it)->date);
        }
    };

    list_iterator lbegin()
    {
        return list_iterator(tree, 1);
    }

    list_iterator lend()
    {
        return list_iterator(tree, 0);
    }


    struct iterator
    {
        typename AVL<keyType, ValueType>::node* node = nullptr;
        AVL<keyType, ValueType> tree;

        iterator() {}

        iterator(const iterator& iter)
        {
            node = iter.node;
            tree = iter.tree;
        }

        iterator(typename AVL<keyType, ValueType>::node* other, AVL<keyType, ValueType> otherTree)
        {
            node = other;
            tree = otherTree;
        }

        iterator& operator++()
        {
            typename AVL<keyType, ValueType>::node* temp = tree.root;

            while (temp->right)
            {
                temp = temp->right;
            }

            if (temp == node)
            {
                node = nullptr;

                return *this;
            }

            if (node->right != nullptr)
            {
                node = node->right;

                while (node->left)
                {
                    node = node->left;
                }
            }
            else
            {
                while (tree.parent(node, tree.root)->date.first < node->date.first)
                {
                    node = tree.parent(node, tree.root);
                }

                node = tree.parent(node, tree.root);
            }

            return *this;
        }

        iterator& operator--()
        {
            typename AVL<keyType, ValueType>::node* temp = tree.root;

            while (temp->right)
            {
                temp = temp->right;
            }

            if (node == nullptr)
            {
                node = temp;

                return *this;
            }

            if (node->left != nullptr)
            {
                node = node->left;

                while (node->right)
                {
                    node = node->right;
                }
            }
            else
            {
                while (tree.parent(node, tree.root)->date.first > node->date.first)
                {
                    node = tree.parent(node, tree.root);
                }
            }
        }

        bool operator==(const iterator& other)
        {
            return other.node == node;
        }

        bool operator!=(const iterator& other)
        {
            return !(*this == other);
        }

        keyType operator*()
        {
            return node->date.first;
        }

        std::pair<keyType, ValueType>* operator->()
        {
            return &(node->date);
        }
    };

    iterator begin()
    {
        typename AVL<keyType, ValueType>::node* temp = tree.root;

        if (!temp)
        {
            return iterator(temp, tree);
        }

        while (temp->left)
        {
            temp = temp->left;
        }

        return iterator(temp, tree);
    }

    iterator end()
    {
        typename AVL<keyType, ValueType>::node* temp = nullptr;

        return iterator(temp, tree);
    }

    iterator search(keyType key)
    {
        typename AVL<keyType, ValueType>::node* temp = tree.search(key);

        return iterator(temp, tree);  
    }

    ValueType& operator[](keyType key)
    {
        typename AVL<keyType, ValueType>::node* temp = tree.search(key);
        
        if (temp)
        {
            return temp->date.second;
        }
        else
        {
            tree.insert(std::make_pair(key, ValueType()));

            sz++;

            return tree.search(key)->date.second;
        }
    }
};




template<class keyType, class ValueType = keyType>
class set
{
    AVL<keyType, ValueType> tree;
    int sz = 0;

public:
    void insert(keyType input)
    {
        if (this->search(input).node)
        {
            return;
        }

        tree.insert(std::make_pair(input, input));

        sz++;
    }

    void erase(keyType key)
    {
        tree.remove(key);

        sz--;
    }

    int size()
    {
        return sz;
    }



    struct list_iterator
    {
        AVL<keyType, ValueType> tree;
        std::list<typename AVL<keyType, ValueType>::node*> list;
        typename std::list<typename AVL<keyType, ValueType>::node*>::iterator it;

        list_iterator(AVL<keyType, ValueType> otherTree, bool begin)
        {
            tree = otherTree;

            tree.root->inorder(list);

            if (begin)
            {
                it = list.begin();

                typename AVL<keyType, ValueType>::node* temp = nullptr;
                list.push_back(temp);
            }
            else
            {
                typename AVL<keyType, ValueType>::node* temp = nullptr;

                list.push_back(temp);

                it = list.end();
                it--;
            }
        }

        list_iterator& operator++()
        {
            it++;

            return *this;
        }

        list_iterator& operator--()
        {
            it--;

            return *this;
        }

        bool operator==(const list_iterator& other)
        {
            return *it == *(other.it);
        }

        bool operator!=(const list_iterator& other)
        {
            return !(*this == other);
        }

        keyType operator*() const
        {
            return (*it)->date.first;
        }
    };

    list_iterator lbegin()
    {
        return list_iterator(tree, 1);
    }

    list_iterator lend()
    {
        return list_iterator(tree, 0);
    }


    struct iterator
    {
        typename AVL<keyType, ValueType>::node* node = nullptr;
        AVL<keyType, ValueType> tree;

        iterator() {}

        iterator(const iterator& iter)
        {
            node = iter.node;
            tree = iter.tree;
        }

        iterator(typename AVL<keyType, ValueType>::node* other, AVL<keyType, ValueType> otherTree)
        {
            node = other;
            tree = otherTree;
        }

        iterator& operator++()
        {
            typename AVL<keyType, ValueType>::node* temp = tree.root;

            while (temp->right)
            {
                temp = temp->right;
            }

            if (temp == node)
            {
                node = nullptr;

                return *this;
            }

            if (node->right != nullptr)
            {
                node = node->right;

                while (node->left)
                {
                    node = node->left;
                }
            }
            else
            {
                while (tree.parent(node, tree.root)->date.first < node->date.first)
                {
                    node = tree.parent(node, tree.root);
                }

                node = tree.parent(node, tree.root);
            }

            return *this;
        }

        iterator& operator--()
        {
            typename AVL<keyType, ValueType>::node* temp = tree.root;

            while (temp->right)
            {
                temp = temp->right;
            }

            if (node == nullptr)
            {
                node = temp;

                return *this;
            }

            if (node->left != nullptr)
            {
                node = node->left;

                while (node->right)
                {
                    node = node->right;
                }
            }
            else
            {
                while (tree.parent(node, tree.root)->date.first > node->date.first)
                {
                    node = tree.parent(node, tree.root);
                }
            }
        }

        bool operator==(const iterator& other)
        {
            return other.node == node;
        }

        bool operator!=(const iterator& other)
        {
            return !(*this == other);
        }

        keyType operator*() const 
        {
            return node->date.first;
        }
    };

    iterator begin()
    {
        typename AVL<keyType, ValueType>::node* temp = tree.root;

        while (temp->left)
        {
            temp = temp->left;
        }

        return iterator(temp, tree);
    }

    iterator end()
    {
        typename AVL<keyType, ValueType>::node* temp = nullptr;

        return iterator(temp, tree);
    }

    iterator search(keyType key)
    {
        typename AVL<keyType, ValueType>::node* temp = tree.search(key);

        return iterator(temp, tree);
    }

    /*ValueType& operator[](keyType key)
    {
        typename AVL<keyType, ValueType>::node* temp = tree.search(key);

        if (temp)
        {
            return temp->date.second;
        }
        else
        {
            tree.insert(std::make_pair(key, ValueType()));

            sz++;

            return tree.search(key)->date.second;
        }
    }*/
};

#include <forward_list>

template<class keyType, class valueType, class hash = std::hash<keyType>>
class unordered_map
{

    std::list<std::pair<keyType, valueType>> pairList;
    std::forward_list<std::pair<keyType, valueType>>* hashTable = nullptr;
    int sz = 0;
    int cap = 100;
    double maxFillFactor = 0.6;
    double numberBucket = 0.0;

public:

    unordered_map()
    {
        hashTable = new std::forward_list<std::pair<keyType, valueType>>[100];
    }

    void insert(std::pair<keyType, valueType> input)
    {
        if (contains(input.first))
        {
            return;
        }

        if (numberBucket / cap >= maxFillFactor)
        {
            this->rehash(cap * 2);
        }

        if (hashTable[hash{}(input.first) % cap].empty())
        {
            numberBucket++;
        }
        
        hashTable[hash{}(input.first) % cap].push_front(input);

        pairList.push_back(input);
        sz++;
    }

    void erase(const keyType& key)
    {
        int keyHash = hash{}(key) % cap;

        typename std::forward_list<std::pair<keyType, valueType>>::iterator it = hashTable[keyHash].begin();
        typename std::forward_list<std::pair<keyType, valueType>>::iterator itSpare = hashTable[keyHash].begin();


        for (int i = 0; it != hashTable[keyHash].end(); it++, i++)
        {
            if(i != 0)
            {
                itSpare++;
            }

            if (key == it->first)
            {
                if(i == 0)
                {
                    hashTable[keyHash].pop_front();
                }
                else
                {
                    hashTable[keyHash].erase_after(itSpare);
                }


                pairList.remove(std::make_pair(key, (*(this->find(key))).second));

                if (hashTable[keyHash].empty())
                {
                    numberBucket--;
                }

                sz--;

                break;
            }
        }
    }

    bool contains(keyType key)
    {
        int keyHash = hash{}(key) % cap;

        typename std::forward_list<std::pair<keyType, valueType>>::iterator it = hashTable[keyHash].begin();

        for (; it != hashTable[keyHash].end(); it++)
        {
            if (key == it->first)
            {
                return true;
            }
        }

        return false;
    }

    struct iterator
    {
        typename std::list<std::pair<keyType, valueType>>::iterator it;
        
        iterator(typename std::list<std::pair<keyType, valueType>>::iterator iter)
        {
            it = iter;
        }

        bool operator==(const iterator& other)
        {
            return it == other.it;
        }

        bool operator!=(const iterator& other)
        {
            return it != other.it;
        }


        iterator& operator++()
        {
            it++;

            return *this;
        }

        iterator& operator--()
        {
            it--;

            return *this;
        }

        std::pair<keyType, valueType>* operator->()
        {
            return &(*it);
        }

        std::pair<keyType, valueType> operator*()
        {
            return *it;
        }
    };

    iterator begin()
    {
        return iterator(pairList.begin());
    }

    iterator end()
    {
        return iterator(pairList.end());
    }

    int size()
    {
        return sz;
    }

    iterator find(keyType key)
    {
        typename std::list<std::pair<keyType, valueType>>::iterator it = pairList.begin();

        for (; it != pairList.end(); it++)
        {
            if (it->first == key)
            {
                return iterator(it);
            }
        }

        return iterator(it);
    }

    void rehash(const int newCap)
    {
        std::forward_list<std::pair<keyType, valueType>>* newHashTable = new std::forward_list<std::pair<keyType, valueType>>[newCap];

        iterator oldIt = begin();

        for (; oldIt != end(); ++oldIt)
        {
            newHashTable[hash{}(oldIt->first) % newCap].push_front(*oldIt);
        }

        cap = newCap;
        hashTable = newHashTable;
    }

    valueType& operator[](keyType key)
    {
        iterator it = this->find(key);

        if (it == end())
        {
            this->insert(std::make_pair(key, valueType()));

            return this->find(key)->second;
        }
        else
        {
            return it->second;
        }
    }
};



#include <cstring>

template<size_t size>
class bitset
{
    static const int elemSize = 8 * sizeof(unsigned long long);
    static const size_t arraySize = (size - 1) / elemSize + 1;
    unsigned long long bits[arraySize];

    

    struct reference
    {
        friend bitset<size>;

        bitset<size>* arr;
        size_t pos;

        reference(bitset<size>& set, size_t position)
        {
            arr = &set;
            pos = position;
        }

        reference& operator=(bool val)
        {
            unsigned long long& currentElem = arr->bits[pos / arr->elemSize], temp = 1;

            if (val)
            {
                currentElem |= (temp << (pos % arr->elemSize));
            }
            else
            {
                currentElem &= ~(temp << (pos % arr->elemSize));
            }

            return *this;
        }

        operator bool()
        {
            return arr->test(pos);
        }
    };

public:

    bitset()
    {
        for (int i = 0; i < arraySize; i++)
        {
            bits[i] = 0;
        }
    }

    reference operator[](int pos)
    {
        return reference(*this, pos);
    }

    /*bool operator[](int pos) const
    {
        return test[pos];
    }*/

    bitset(unsigned long long input)
    {
        bits[0] = input;
    }

    bitset(const bitset& other)
    {
        for (int i = 0; i < arraySize; i++)
        {
            bits[i] = other.bits[i];
        }
    }

    bool all()
    {
        bool complited = ((size % elemSize) == 0);

        for (int i = 0; i < arraySize + complited - 1; i++)
        {
            if (bits[i] != ULLONG_MAX)
            {
                return false;
            }
        }

        unsigned long long temp = 1;

        return complited || bits[arraySize - 1] == ((temp << (size % elemSize)) - 1);
    }

    bool any()
    {
        for (int i = 0; i < arraySize; i++)
        {
            if (bits[i] != 0)
            {
                return true;
            }
        }

        return false;
    }

    size_t count()
    {
        size_t number = 0;

        /*for (int i = 0; i < size; i++)
        {
            if (test(i))
            {
                number++;
            }
        }*/

        for(int i = 0; i < arraySize; i++)
        {
            number += __popcnt64(bits[i]);
        }

        return number;
    }

    void flip()
    {
        for (int i = 0; i < arraySize; i++)
        {
            bits[i] = ~bits[i];
        }

        unsigned long long temp = 1;

        bits[arraySize - 1] &= ((temp << (size % elemSize)) - 1);
    }

    void flip(int pos)
    {
        reference(*this, pos) = !test(pos);
    }

    bool none()
    {
        return !any();
    }

    void reset()
    {
        for (int i = 0; i < arraySize; i++)
        {
            bits[i] = 0;
        }
    }

    void reset(int pos)
    {
        reference(*this, pos) = 0;
    }

    void set()
    {
        for (int i = 0; i < arraySize; i++)
        {
            bits[i] = ULLONG_MAX;
        }
    }

    void set(int pos)
    {
        reference(*this, pos) = 1;
    }

    bool test(size_t pos)
    {
        unsigned long long temp = 1;

        return bits[pos / elemSize - (pos % 64 == 0 && pos)] & (temp << (pos % elemSize));
    }

    size_t getSize()
    {
        return size;
    }

    std::string to_string()
    {
        std::string out;

        for (int i = size - 1; i >= 0; i--)
        {
            out.push_back(test(i) + '0');
        }

        return out;
    }

    unsigned long to_ulong()
    {
        return static_cast<unsigned long>(bits[0]);
    }

    unsigned long long to_ullong()
    {
        return bits[0];
    }

    bitset& operator&=(const bitset& other)
    {
        for (size_t i = 0; i < arraySize; i++)
        {
            bits[i] &= other.bits[i];
        }

        return *this;
    }

    bitset& operator|=(const bitset& other)
    {
        for (size_t i = 0; i < arraySize; i++)
        {
            bits[i] |= other.bits[i];
        }

        return *this;
    }

    bitset& operator^=(const bitset& other)
    {
        for (size_t i = 0; i < arraySize; i++)
        {
            bits[i] ^= other.bits[i];
        }

        return *this;
    }
};


int main()
{
    bitset<64> m;

    m = bitset<64>(5);
    

    std::cout << m.to_string() << " " << m.all();;
}



