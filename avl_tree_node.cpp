#include "avl_tree_node.hpp"


node::node(int k)
{
    height = 1;
    key = k;
    left = nullptr;
    right = nullptr;
}


void AVL::insert(int x)
{
    root=insert(root, x);
}

void AVL::remove(int x)
{
    root=remove(root, x);
}

node *AVL::search(int x)
{
    return find(root,x);
}

void AVL::disp()
{
    display(root);
    cout<<endl;
}

int AVL::height(node *head)
{
    if(head==nullptr) return 0;
    return head->height;
}

node *AVL::right_rotation(node *head)
{
    node *tmp = head->left;
    head->left = tmp->right;
    tmp->right = head;
    head->height = 1 + max(height(head->left), height(head->right));
    tmp->height = 1 + max(height(tmp->left), height(tmp->right));
    return tmp;
}

node *AVL::left_rotation(node *head)
{
    node *tmp = head->right;
    head->right = tmp->left;
    tmp->left = head;
    head->height = 1 + max(height(head->left), height(head->right));
    tmp->height = 1 + max(height(tmp->left), height(tmp->right));
    return tmp;
}

void AVL::display(node *head)
{
    if(head==nullptr) 
        return ;
    display(head->left);
    cout<<head->key<<" ";
    display(head->right);
}

node *AVL::insert(node *head, int x)
{
    if(head==nullptr)
    {
        n++;
        node *temp = new node(x);
        return temp;
    }
    if(x < head->key) head->left = insert(head->left, x);
    else if(x > head->key) head->right = insert(head->right, x);
    head->height = 1  +  max(height(head->left), height(head->right));
    int bal = height(head->left) - height(head->right);
    if(bal>1)
    {
        if(x < head->left->key)
        {
            return right_rotation(head);
        }
        else
        {
            head->left = left_rotation(head->left);
            return right_rotation(head);
        }
    }
    else if(bal<-1)
    {
        if(x > head->right->key)
        {
            return left_rotation(head);
        }
        else
        {
            head->right = right_rotation(head->right);
            return left_rotation(head);
        }
    }
    return head;
}

node *AVL::remove(node *head, int x){
    if(!head)
        return nullptr;
    if(x < head->key)
    {
        head->left = remove(head->left, x);
    }
    else if(x > head->key)
    {
        head->right = remove(head->right, x);
    }
    else
    {
        node *r = head->right;
        if(head->right==nullptr)
        {
            node *l = head->left;
            delete(head);
            head = l;
        }
        else if(head->left==nullptr)
        {
            delete(head);
            head = r;
        }
        else
        {
            while(r->left!=nullptr) r = r->left;
            head->key = r->key;
            head->right = remove(head->right, r->key);
        }
    }
    if(!head) 
        return head;
    head->height = 1  +  max(height(head->left), height(head->right));
    int bal = height(head->left) - height(head->right);
    if(bal>1)
    {
        if(height(head->left) >= height(head->right))
        {
            return right_rotation(head);
        }
        else
        {
            head->left = left_rotation(head->left);
            return right_rotation(head);
        }
    }
    else if(bal < -1)
    {
        if(height(head->right) >= height(head->left))
        {
            return left_rotation(head);
        }
        else
        {
            head->right = right_rotation(head->right);
            return left_rotation(head);
        }
    }
    return head;
}

node *AVL::find(node *head, int x)
{
    if(head == nullptr) 
        return nullptr;
    int k = head->key;
    if(k == x) 
        return head;
    if(k > x) 
        return find(head->left, x);
    if(k < x) 
        return find(head->right, x);
}


