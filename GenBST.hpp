#ifndef GenBST_hpp
#define GenBST_hpp

#include <stdio.h>

#include <iostream>
#include <cstddef>
#include "TreeNode.hpp"
#include "Student.hpp"
#include "Faculty.hpp"
#include "BSTIterator.hpp"
#include <map>

using namespace std;

template <class K, class V> //template to operate on generic types
class BST{
    private:
        TreeNode<K, V> *root;

    public:
        BST();
        ~BST();

        bool insertNode(const K&, const V&);
        TreeNode<K, V>* searchNode(const K&);
        V* deleteNode(const K& k);

        int BSTheight(TreeNode<K, V> *node);
        bool isEmpty();
//        K getMax();
//        K getMin();
        void recPrint(TreeNode<K, V> *node); //recursive print, takes a node so we can print any part of the tree
//        void recPrint(TreeNode<K, V> *node, int level); //recursive print, takes a node so we can print any part of the tree
        void printTree();
        void iterateThroughEachNode(TreeNode<K, V> *node);

        //returns the sucessor of the node to be deleted, d
        TreeNode<K, V>* getSuccessor(TreeNode<K, V> *d);
//        int height;

        BSTIterator<K, V> iterator();
        int size;
        int getSize();
};

#endif /* GenBST_hpp */
