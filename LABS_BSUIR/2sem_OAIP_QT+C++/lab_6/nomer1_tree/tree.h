#ifndef TREE_H
#define TREE_H

#include "string"
#include <QTreeWidget>
#include "../../../libs/crutch_list/crutch_list.h"

//using namespace std;

/*template<class T>
struct treeNode
{
    treeNode* left = nullptr;
    treeNode* rigth = nullptr;
    std::string key;
    T value;
    int height = 0;

    treeNode() {}

    treeNode(std::string inputKey, T inputValue)
    {
        key = inputKey;
        value = inputValue;
    }



    /*int getBFactor()
    {
        int hleft = 0, hrigth = 0;

        if(left)
            {
            hleft = left->height;
        }

        if(rigth)
        {
            hrigth = rigth->height;
        }

        return hrigth - hleft;
    }

    treeNode* rotateRigth()
    {
        treeNode* p = this;
        treeNode* q = p->left;
        p->left = q->rigth;
        q->rigth = p;

        p->updateHeight();
        q->updateHeight();

        return q;
    }

    treeNode* rotateLeft()
    {
        treeNode* q = this;
        treeNode* p = q->rigth;
        q->rigth = p->left;
        p->left = q;

        q->updateHeight();
        p->updateHeight();


        return p;
    }

    void updateHeight()
    {
        int hleft = 0, hrigth = 0;

        if(left)
        {
            hleft = left->height;
        }

        if(rigth)
        {
            hrigth = rigth->height;
        }

        if(hleft > hrigth)
        {
            height = hleft + 1;
        }
        else
        {
            height = hrigth + 1;
        }
    }

    treeNode* balance()
    {
        this->updateHeight();

        if(getBFactor() == 2)
        {
            if(rigth->getBFactor() < 0)
            {
                rigth = rigth->rotateRigth();
            }

            return this->rotateLeft();
        }

        if(getBFactor() == -2)
        {
            if(left->getBFactor() > 0)
            {
                left = left->rotateLeft();
            }

            return this->rotateRigth();
        }

        return this;
    }



    treeNode* addNode(treeNode* input)
    {
        if(input->key < key)
        {
            if(!left)
            {
                left = input;
            }
            else
            {
                left->addNode(input);
            }
        }
        else
        {
            if(!rigth)
            {
                rigth = input;
            }
            else
            {
                rigth->addNode(input);
            }
        }

        return this->balance();
    }

    treeNode* search(std::string desired)
    {
        if(key == desired)
        {
            return this;
        }

        if(key > desired)
        {
            if(left)
            {
                return left->search(desired);
            }
            else
            {
                return nullptr;
            }
        }
        else
        {
            if(rigth)
            {
                return rigth->search(desired);
            }
            else
            {
                return nullptr;
            }
        }
    }

    treeNode* delet(treeNode* current, std::string deleteKey)
    {
        if(!current)
        {
            return current;
        }

        if(deleteKey < key)
        {
            left = delet(left, deleteKey);
        }
        else if(deleteKey > key)
        {
            rigth = delet(rigth, deleteKey);
        }
        else
        {
            if(!current->left && !current->rigth)
            {
                delete current;
                current = nullptr;
            }
            else if(!current->left)
            {
                treeNode* temp = current;
                current = current->rigth;
                delete temp;
            }
            else if(!current->rigth)
            {
                treeNode* temp = current;
                current = current->left;
                delete temp;
            }
            else
            {
                treeNode* temp = current->rigth;

                while(temp->left)
                {
                    temp = temp->left;
                }

                current->key = temp->key;
                current->value = temp->value;

                current->rigth = delet(current->rigth, deleteKey);
            }
        }

        return current;
    }

    void preorder(list<T>& arr)
    {
        arr.push_back(value);

        if(left)
        {
            left->preorder(arr);
        }

        if(rigth)
        {
            rigth->preorder(arr);
        }
    }

    void inorder(list<T>& arr)
    {
        if(left)
        {
            left->inorder(arr);
        }

        arr.push_back(value);

        if(rigth)
        {
            rigth->inorder(arr);
        }
    }

    void postorder(list<T>& arr)
    {
        if(left)
        {
            left->postorder(arr);
        }

        if(rigth)
        {
            rigth->postorder(arr);
        }

        arr.push_back(value);
    }

    unsigned int heght(treeNode* p)
    {
        return p?p->height  : 0;
    }

    int bfactor(treeNode* p)
    {
        return heght(p->rigth)-heght(p->left);
    }

    void fixheight(treeNode* p)
    {
        unsigned int hl = heght(p->left);
        unsigned int hr = heght(p->rigth);
        p->height = (hl>hr?hl:hr)+1;
    }

    treeNode* rotateright(treeNode* p) // правый поворот вокруг p
    {
        treeNode* q = p->left;
        p->left = q->rigth;
        q->rigth = p;
        fixheight(p);
        fixheight(q);
        return q;
    }

    treeNode* rotateleft(treeNode* q) // левый поворот вокруг q
    {
        treeNode* p = q->rigth;
        q->rigth = p->left;
        p->left = q;
        fixheight(q);
        fixheight(p);
        return p;
    }

    treeNode* balance(treeNode* p) // балансировка узла p
    {
        fixheight(p);

        if( bfactor(p)==2 )
        {
            if( bfactor(p->rigth) < 0 )
                p->rigth = rotateright(p->rigth);
            return rotateleft(p);
        }
        if( bfactor(p)==-2 )
        {
            if( bfactor(p->left) > 0  )
                p->left = rotateleft(p->left);
            return rotateright(p);
        }
        return p; // балансировка не нужна
    }

    treeNode* insert(treeNode* p, treeNode* k) // вставка ключа k в дерево с корнем p
    {
        if( !p ) return k;
        if(k->key < p->key)
            p->left = insert(p->left,k);
        else
            p->rigth = insert(p->rigth,k);
        return balance(p);
    }

    treeNode* findmin(treeNode* p) // поиск узла с минимальным ключом в дереве p
    {
        return p->left?findmin(p->left):p;
    }

    treeNode* removemin(treeNode* p) // удаление узла с минимальным ключом из дерева p
    {
        if( p->left==0 )
            return p->rigth;
        p->left = removemin(p->left);
        return balance(p);
    }

    treeNode* remove(treeNode* p, std::string k) // удаление ключа k из дерева p
    {
        if( !p ) return 0;
        if( k < p->key )
            p->left = remove(p->left,k);
        else if( k > p->key )
            p->rigth = remove(p->rigth,k);
        else // k == p->key
        {
            treeNode* q = p->left;
            treeNode* r = p->rigth;
            delete p;
            if( !r ) return q;
            treeNode* min = findmin(r);
            min->rigth = removemin(r);
            min->left = q;
            return balance(min);
        }
        return balance(p);
    }
};


template<class T>
class tree
{
    treeNode<T>* root = nullptr;

public:

    tree()
    {

    }

    void addNode(std::string key, T value)
    {
        if(!root)
        {
            root = new treeNode<T>(key, value);
        }
        else
        {
            root = root->insert(root, new treeNode<T>(key, value));
        }
    }

    /*treeNode<T>* search(std::string desired)
    {
        return root->search(desired);
    }

    list<T> preorder()
    {
        list<T> temp;

        root->preorder(temp);

        return temp;
    }

    list<T> inorder()
    {
        list<T> temp;

        root->inorder(temp);

        return temp;
    }

    list<T> postorder()
    {
        list<T> temp;

        root->postorder(temp);

        return temp;
    }

    void delet(std::string deleteKey)
    {
        root = root->remove(root, deleteKey);
    }
};*/






/*class BST
{
    struct node
    {
        int data;
        node* left;
        node* right;
        int height;

        void preorder(list<int>& arr)
        {
            arr.push_back(data);

            if(left)
            {
                left->preorder(arr);
            }

            if(right)
            {
                right->preorder(arr);
            }
        }

        void inorder(list<int>& arr)
        {

            if(left)
            {
                left->preorder(arr);
            }

            arr.push_back(data);

            if(right)
            {
                right->preorder(arr);
            }
        }

        void postorder(list<int>& arr)
        {

            if(left)
            {
                left->preorder(arr);
            }

            if(right)
            {
                right->preorder(arr);
            }

            arr.push_back(data);

        }
    };

    node* root;

    void makeEmpty(node* t)
    {
        if(t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
        {
            t->left = insert(x, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(x < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(x > t->data)
        {
            t->right = insert(x, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(x > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = std::max(height(t->left), height(t->right))+1;
        return t;
    }

    node* singleRightRotate(node* &t)
    {
        if (t->left != NULL) {
            node* u = t->left;
            t->left = u->right;
            u->right = t;
            t->height = std::max(height(t->left), height(t->right)) + 1;
            u->height = std::max(height(u->left), t->height) + 1;
            return u;
        }
        return t;
    }
    node* singleLeftRotate(node* &t)
    {
            if (t->right != NULL) {
            node* u = t->right;
            t->right = u->left;
            u->left = t;
            t->height = std::max(height(t->left), height(t->right)) + 1;
            u->height = std::max(height(t->right), t->height) + 1;
            return u;
            }
            return t;
    }

    node* doubleLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node* doubleRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t)
    {
        node* temp;

        // Element not found
        if(t == NULL)
            return NULL;

        // Searching for element
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);

        // Element found
        // With 2 children
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        // With one or zero child
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        if(t == NULL)
            return t;

        t->height = std::max(height(t->left), height(t->right))+1;

        // If node is unbalanced
        // If left node is deleted, right case
        if(height(t->left) - height(t->right) == -2)
        {
            // right right case
            if(height(t->right->right) - height(t->right->left) == 1)
                return singleLeftRotate(t);
            // right left case
            else
                return doubleLeftRotate(t);
        }
        // If right node is deleted, left case
        else if(height(t->right) - height(t->left) == 2)
        {
            // left left case
            if(height(t->left->left) - height(t->left->right) == 1){
                return singleRightRotate(t);
            }
            // left right case
            else
                return doubleRightRotate(t);
        }
        return t;
    }



    int height(node* t)
    {
        return (t == NULL ? -1 : t->height);
    }

    int getBalance(node* t)
    {
        if(t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }


public:
    BST()
    {
        root = NULL;
    }

    void insert(int x)
    {
        root = insert(x, root);
    }

    void remove(int x)
    {
        root = remove(x, root);
    }

    list<int> preorder()
    {
        list<int> temp;

        root->preorder(temp);

        return temp;
    }

    list<int> inorder()
    {
        list<int> temp;

        root->inorder(temp);

        return temp;
    }

    list<int> postorder()
    {
        list<int> temp;

        root->postorder(temp);

        return temp;
    }
};*/



class AVL{
public:
    struct node{
        int key;
        int value;
        int height;
        node * left;
        node * right;

        node(int k, int val){
            height = 1;
            key = k;
            value = val;
            left = nullptr;
            right = nullptr;
        }

        void preorder(list<int>& arr)
        {
            arr.push_back(value);

            if(left)
            {
                left->preorder(arr);
            }

            if(right)
            {
                right->preorder(arr);
            }
        }

        void vis(QTreeWidgetItem* r)
        {
            if(r->childCount() != 3)
            {
                r->addChild(new QTreeWidgetItem);
                r->child(0)->setText(0, "key " + QString::number(key) + " value " + QString::number(value));

                r->addChild(new QTreeWidgetItem);
                r->child(1)->setText(0, "left");

                r->addChild(new QTreeWidgetItem);
                r->child(2)->setText(0, "rigth");
            }

            if(left)
            {
                left->vis(r->child(1));
            }

            if(right)
            {
                right->vis(r->child(2));
            }
        }

        int count(int& number)
        {
            if(left && right)
            {
                number++;
            }

            if(left)
            {
                left->count(number);
            }

            if(right)
            {
                right->count(number);
            }
        }

        void inorder(list<int>& arr)
        {

            if(left)
            {
                left->inorder(arr);
            }

            arr.push_back(value);

            if(right)
            {
                right->inorder(arr);
            }
        }

        void postorder(list<int>& arr)
        {

            if(left)
            {
                left->postorder(arr);
            }

            if(right)
            {
                right->postorder(arr);
            }

            arr.push_back(value);

        }

        void clear()
        {
            if(left)
            {
                left->clear();
            }

            if(right)
            {
                right->clear();
            }

            delete this;
        }
    };

    void insert(int x, int val)
    {
        root = insertUtil(root, x, val);
    }

    void remove(int x)
    {
        root = removeUtil(root, x);
    }
    node* search(int x)
    {
        return searchUtil(root,x);
    }

    list<int> preorder()
    {
        list<int> temp;

        root->preorder(temp);

        return temp;
    }

    list<int> inorder()
    {
        list<int> temp;

        root->inorder(temp);

        return temp;
    }

    list<int> postorder()
    {
        list<int> temp;

        root->postorder(temp);

        return temp;
    }

private:

    int height(node* head)
    {
        if(!head)
        {
            return 0;
        }

        return head->height;
    }

    node* rightRotation(node* head)
    {
        node*  newhead = head->left;
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

        head->height = 1+std::max(height(head->left), height(head->right));
        newhead->height = 1+std::max(height(newhead->left), height(newhead->right));

        return newhead;
    }

    node* insertUtil(node* head, int x, int val)
    {
        if(!head)
        {
            n += 1;
            node* temp = new node(x, val);

            return temp;
        }

        if(x < head->key)
        {
            head->left = insertUtil(head->left, x, val);
        }
        else if(x > head->key)
        {
            head->right = insertUtil(head->right, x, val);
        }

        head->height = 1 + std::max(height(head->left), height(head->right));

        int bal = height(head->left) - height(head->right);

        if(bal > 1)
        {
            if(x < head->left->key)
            {
                return rightRotation(head);
            }
            else
            {
                head->left = leftRotation(head->left);

                return rightRotation(head);
            }
        }
        else if(bal<-1)
        {
            if(x > head->right->key)
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

    node* removeUtil(node* head, int x)
    {
        if(!head) return nullptr;

        if(x < head->key)
        {
            head->left = removeUtil(head->left, x);
        }
        else if(x > head->key)
        {
            head->right = removeUtil(head->right, x);
        }
        else
        {
            node* r = head->right;

            if(!head->right)
            {
                node* l = head->left;
                delete(head);
                head = l;
            }
            else if(!head->left)
            {
                delete(head);
                head = r;
            }
            else
            {
                while(r->left!=NULL) r = r->left;
                head->key = r->key;
                head->value = r->value;
                head->right = removeUtil(head->right, r->key);
            }
        }

        if(head==NULL)
        {
            return head;
        }

        head->height = 1 + std::max(height(head->left), height(head->right));

        int bal = height(head->left) - height(head->right);

        if(bal > 1)
        {
            if(height(head->left) >= height(head->right))
            {
                return rightRotation(head);
            }
            else
            {
                head->left = leftRotation(head->left);

                return rightRotation(head);
            }
        }
        else if(bal < -1)
        {
            if(height(head->right) >= height(head->left))
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

    node* searchUtil(node* head, int x)
    {
        if(!head)
        {
            return nullptr;
        }

        int k = head->key;

        if(k == x)
        {
            return head;
        }

        if(k > x)
        {
            return searchUtil(head->left, x);
        }

        if(k < x)
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



class new_tree : public AVL
{

public:
    void vis(QTreeWidgetItem* r)
    {
        AVL::root->vis(r);
    }

    int count()
    {
        int temp = 0;

        AVL::root->count(temp);

        return temp;
    }

    void clear()
    {
        AVL::root->clear();

        AVL::root = nullptr;
    }
};
#endif // TREE_H
