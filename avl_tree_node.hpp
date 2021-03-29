#include<iostream>
using namespace std;

class node
{
    public:
        int key;
        int height;
        node *left;
        node *right;
        node(int k);
};

class AVL
{
    public:
        node *root = nullptr;
        int n;
        void insert(int x);
        void remove(int x);
        node *search(int x);
        void disp();
    private:
        int height(node *head);
        node *right_rotation(node *head);
        node *left_rotation(node *head);
        void display(node *head);
        node *insert(node *head, int x);
        node *remove(node *head, int x);
        node *find(node *head, int x);
};