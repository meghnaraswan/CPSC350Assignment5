#include "BSTIterator.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

template <class K, class V> //template to operate on generic types
BSTIterator<K, V>::BSTIterator(TreeNode<K, V>* root) {
    current = root;
    rootTreeNode = root;
}

template <class K, class V> //template to operate on generic types
TreeNode<K, V>* BSTIterator<K, V>::next() {
    TreeNode<K, V>* ret_current = current;
    // wherever I am I ahve to process left and then right
    if(current->left != NULL) {
        current = current->left;
    } else if (current->right != NULL) {
        current = current->right;
    } else { //both are NULL
//        if (current->parent) {
            //...
        TreeNode<K, V>* parent = current->parent;
        while (parent) {
            if (parent->left == current) { // right is not processed yet
                if (parent->right != NULL) {
                    current = parent->right;
                    break;
                } else {
                    current = parent;
                    parent = parent->parent;
                }
            } else { //(parent->right == current) // if you have visited right also then go to your parent
                current = parent;
                parent = parent->parent;
            }
        }
        if (parent == NULL) {// you are at your root, no parent
            current = NULL;
        }
    }
    return ret_current;
}

template <class K, class V> //template to operate on generic types
void BSTIterator<K, V>::setCurrentForNextOrdered() {
    // keep on going to the left most node of the tree
    while (current->left != NULL) {
        current = current->left;
    }
    isProcessingLeftSideofRoot = true;
    return;
}

template <class K, class V> //template to operate on generic types
TreeNode<K, V>* BSTIterator<K, V>::nextOrdered() {
    TreeNode<K, V>* ret_current = current;
    if (current == rootTreeNode)
        isProcessingLeftSideofRoot = !isProcessingLeftSideofRoot; //isProcessingLeftSideofRoot = false;
    
    if(isProcessingLeftSideofRoot) {
        if (current->right != NULL) {
            current = current->right;
            while (current->left != NULL) {
                current = current->left;
            }
        } else { //both are NULL, we are at leaf node, trace back, the parent is already processed
            // wherever I am I have to process left and then parent and then right
            TreeNode<K, V>* parent = current->parent;
            if(current->parent == parent->left) { // I am left node
                current = parent;
            } else if(current->parent == parent->right) { // I am right node
                current = parent->parent; // traverse up
            }
        }
    } else { // isProcessingLeftSideofRoot == false
        if(current->left != NULL) {
            while (current->left != NULL) {
               current = current->left;
            }
        } else if (current->right != NULL) {
            current = current->right;
            while (current->left != NULL) {
                current = current->left;
            }
        } else { //both are NULL, we are at leaf node, trace back, the parent is already processed
            // wherever I am I have to process left and then parent and then right
            TreeNode<K, V>* parent = current->parent;
            if(current->parent == parent->left) { // I am left node
                current = parent;
            } else if(current->parent == parent->right) { // I am right node
                current = parent->parent; // traverse up
            }
        }
    }
    return ret_current;
}



template <class K, class V> //template to operate on generic types
TreeNode<K, V>* BSTIterator<K, V>::nextOrder() {
    TreeNode<K, V>* ret_current = current;
    cout << "nextOrder" << endl;
    if(current->left != NULL) {
        current = current->left;
        cout << "1" << endl;
    } else if (current->right != NULL) {
        current = current->right;
        cout << "2" << endl;
    } else { //both are NULL
//        if (current->parent) {
        cout << "3" << endl;
        TreeNode<K, V>* parent = current->parent;
        while (current->left == NULL) {
            current = current->left;
            cout << "3.1" << endl;
            if(current->left == current){
                cout << "3.1.1" << endl;
                if(current->right != NULL){
                    current = current->right;
                    cout << "3.1.1.1" << endl;
                    break;
                } else {
                    current = parent;
                    parent = parent->parent;
                    cout << "3.1.1.2" << endl;
                }
            } else {
                cout << "3.1.2" << endl;
                if(current->left != NULL){
                    current = current->left;
                    cout << "3.1.2.1" << endl;
                    break;
                } else {
                    current = parent;
                    parent = parent->parent;
                    current = current->right;
                    cout << "3.1.2.2" << endl;
                }
            }
            
//            if (parent->left == current) { // right is not processed yet
//                current = parent->left;
//                if (parent->right != NULL) {
//                    current = parent->right;
//                    break;
//                } else {
//                    current = parent;
//                    parent = parent->parent;
//                }
//            } else { //(parent->right == current) // if you have visited right also then go to your parent
//                current = parent;
//                parent = parent->parent;
//            }
//        }
//        if (parent == NULL) {// you are at your root, no parent
//            current = NULL;
//        }
//    }
//    return ret_current;
        }
    }
    return ret_current;
}

//template <class K, class V> //template to operate on generic types
//void BSTIterator<K, V>::nextOrder() {
////    TreeNode<K, V>* ret_current = current;
//    // return if the current node is empty
//       if (current == NULL)
//           return;
//       // Traverse the left subtree
//       nextOrder(current->left);
//       // Display the data part of the root (or current node)
//       cout << current->data << " ";
//       // Traverse the right subtree
//       nextOrder(current->right);
//}

template <class K, class V> //template to operate on generic types
bool BSTIterator<K, V>::hasNext() {
    return (current!=NULL);
}

template class BSTIterator<int, Student>;
template class BSTIterator<int, Faculty>;

//template <class K, class V> //template to operate on generic types
//void BSTIterator<K, V>::iterate(TreeNode<K, V>* n) {
//    if(!n)
//        return;
//    iterate(n->left);
//    iterate(n->right);
//}

//template <class K, class V> //template to operate on generic types
//TreeNode<K, V>* BSTIterator<K, V>::find_first(TreeNode<K, V>* n){
//    TreeNode<K, V> *tmp;
//    while(n){
//        tmp = n;
//        n = n->left;
//    }
//    return tmp;
//}
//
//template <class K, class V> //template to operate on generic types
//TreeNode<K, V>* BSTIterator<K, V>::lolnext(TreeNode<K, V>* n){
//    assert(n);
//    if(n->right)
//        return find_first(n->right);
//    while(n->parent && n->parent->right == n)
//        n = n->parent;
//    if(!n->parent)
//        return NULL;
//    return n;
//}
//
//template <class K, class V> //template to operate on generic types
//void BSTIterator<K, V>::preorderTraversal(TreeNode<K, V>* root) {
//   if ( root != NULL ) {
//      cout << root->valueToCSV() << endl;
//      preorderPrint( root->left ); // Print items in left subtree.
//      preorderPrint( root->right ); // Print items in right subtree.
//   }
//}
