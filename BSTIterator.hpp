#ifndef BSTIterator_hpp
#define BSTIterator_hpp

#include "TreeNode.hpp"
#include <stdio.h>

template <class K, class V> //template to operate on generic types
class BSTIterator {

private:
    TreeNode<K, V> *current;
    
public:
    BSTIterator(TreeNode<K, V>* root);
    TreeNode<K, V>* next();
    bool hasNext();
    TreeNode<K, V>* nextOrder();
//    void nextOrder();
//    bool hasVisitedRight;
//    void iterate(TreeNode<K, V>* n);
//    TreeNode<K, V>* find_first(TreeNode<K, V>* n);
//    TreeNode<K, V>* lolnext(TreeNode<K, V>* n);
//    void preorderTraversal(TreeNode<K, V>* n);
    
    void setCurrentForNextOrdered();
    TreeNode<K, V>* nextOrdered();
    
    bool isProcessingLeftSideofRoot = true;
    TreeNode<K, V>* rootTreeNode;

    
};

#endif /* BSTIterator_hpp */
