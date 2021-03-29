#include "avl_tree_node.hpp"



int main(){
    AVL tree;
    for (int i = 0; i < 10; i++)
        tree.insert(i);
    tree.disp();
    tree.remove(8);
    tree.disp();
}