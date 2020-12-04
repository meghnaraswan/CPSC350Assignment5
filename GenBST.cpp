#include "GenBST.hpp"
#include "Student.hpp"
#include "Faculty.hpp"
#include "TreeNode.hpp"
#include <map>

template <class K, class V>
BST<K, V>::BST(){
    root = NULL;
}

template <class K, class V>
BST<K, V>::~BST(){
    //iterate and delete, this is O(n)
    BSTIterator<K, V> it = iterator();
    while(it.hasNext()) {
        TreeNode<K,V>* node = it.next();
        delete node;
    }
}

//prints tree given a node to start from
template <class K, class V>
void BST<K, V>::recPrint(TreeNode<K, V> *node){
    if(node){
        node->print();
    }
}

//prints entire tree
template <class K, class V>
void BST<K, V>::printTree(){
    recPrint(root);
}

template <class K, class V>
bool BST<K, V>::insertNode(const K& k, const V& v){
    bool insert_success = true;
    // check if tree is empty, make node root if so
    if(isEmpty()){
        TreeNode<K, V> *node = new TreeNode<K, V>(k, v);
//        size++;
        root = node;
        node->level = 0;
    } else {
        TreeNode<K, V> *parent = NULL;
        TreeNode<K, V> *current = root;
        while(true){
            parent = current;
            if(k < current->key){
                //go left
                current = current->left;
                if(current == NULL) { // reach the leaf anf then connect
                    //found insertion point
                    TreeNode<K, V> *node = new TreeNode<K, V>(k, v);
//                    size++;
                    parent->left = node;
                    node->parent = parent;
                    node->level = parent->level+1;
                    break;
                }
            } else if (k > current->key) {
                //go right
                current = current->right;
                if(current == NULL){ // reach the leaf anf then connect
                    //found insertion point
                    TreeNode<K, V> *node = new TreeNode<K, V>(k, v);
//                    size++;
                    parent->right = node;
                    node->parent = parent;
                    node->level = parent->level +1;
                    break;
                }
            } else { // k == current->key
                cout << "Duplicate key found :" << k << endl;
                insert_success = false;
                break;
            }
        }
    }
    return insert_success;
}

//template <class K, class V>
//int BST<K, V>::getSize(){
//    return size;
//}

template <class K, class V>
TreeNode<K, V>* BST<K, V>::searchNode(const K& k){
    TreeNode<K, V> *node_found = NULL;
    if(!isEmpty()) {
        //tree is not empty, let's go look for the value
        TreeNode<K, V> *current = root;
        while(current->key != k) {
            if(k < current->key)
                current = current->left;
            else
                current = current->right;
            if(current == NULL){ // if leaf is reached without finding the key, the key does not exist
                break;
            }
        }
        if(current != NULL)
            node_found = current;
    }
    return node_found; // found the value
}

template <class K, class V>
V* BST<K, V>::deleteNode(const K& k){
    V* ret_val = NULL;
    TreeNode<K, V> *node_found = this->searchNode(k);
    if(node_found) {
        cout << node_found->valueToCSV() << endl;
        TreeNode<K, V> *current = node_found;
        TreeNode<K, V> *parent = node_found->parent;
        bool isLeftNode = (parent!=NULL) ? (parent->left == current) : true;
        
        //if we make it here, then we found it, now lets proceed to delete
        //case: node to delete has no children, AKA leaf node
        if(current->left == NULL && current->right == NULL){
            cout << "if(current->left == NULL && current->right == NULL)" << endl;
            if(current == root){
                root = NULL; //removed the node
            } else if(isLeftNode){
                parent->left = NULL;
            } else{ //right child
                parent->right = NULL;
            }
        }
        //FIX THISSSS
        //case: node to be deleted has one child. need to determine whether child is left or right
        else if(current->right == NULL){
            //node has left child, no right children
            cout << "if(current->right == NULL)" << endl;
            if(current == root)
                root = current->left;
            else if(isLeftNode) {
                parent->left = current->left;
                current->left->parent = parent;
                current->left->moveLevelUp();
            } else { // not lfet node
                parent->right = current->left;
                current->left->parent = parent;
                current->left->moveLevelUp();
            }
        }
        else if(current->left ==NULL){
            //node has right child, no left children
            cout << "if(current->left ==NULL)" << endl;
            if(current == root)
                root = current->right;
            else if(isLeftNode) {
                parent ->left = current->right;
                current->right->parent = parent;
                current->right->moveLevelUp();
            } else {
                parent->right = current->right;
                current->right->parent = parent;
                current->right->moveLevelUp();
            }
        } else {
            cout << "else" << endl;
            //node to be deleted has two children. we need to find the successor in this case
            TreeNode<K, V> *successor = getSuccessor(current); //current is the node to be deleted
            if(current == root)
                root = successor;
            else if (isLeftNode) {
                parent->left = successor;
                successor->parent = parent;
                successor->moveLevelUp();
            } else {
                parent->right = successor;
                successor->parent = parent;
                successor->moveLevelUp();
            }
            successor->left = current->left;
        }

        cout << node_found->valueToCSV() << endl;
        // store the pointer of the value here to return it
        ret_val = &(node_found->value);
        // cleaup the node memory here, before saying good by to the node
        delete node_found;
    }
    return ret_val;
}

template <class K, class V>
BSTIterator<K, V> BST<K, V>::iterator() {
    return BSTIterator<K, V>(root);
}

//d represents the node to be deleted
template <class K, class V>
TreeNode<K, V>* BST<K, V>::getSuccessor(TreeNode<K, V> *d){
    TreeNode<K, V> *sp = d;
    TreeNode<K, V> *successor = d;
    TreeNode<K, V> *current = d->right;
    while(current != NULL){
        sp = successor;
        successor = current;
        current = current->left;
    }
    if(successor != d->right){
        //descendant of the right children
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}

template <class K, class V>
bool BST<K, V>::isEmpty(){
    if(root == NULL)
        return true;
    else
        return false;
}

template class BST<int, Student>;
template class BST<int, Faculty>;

//template <class K, class V>
//void BST<K, V>::recPrint(TreeNode<K, V> *node, int level){
//    if(node == NULL){
//        return;
//    } if (level == 1) {
//        cout << node << endl;
//    } else if (level > 1) {
//        recPrint(node->left, level - 1);
//        cout << node->key << endl;
//        recPrint(node->right, level - 1);
//    }
//}

////prints entire tree
//template <class K, class V>
//void BST<K, V>::printTree(){
//    int height = BSTheight(root);
//    for(int i = 0; i <= height; ++i){
//        recPrint(root, i);
//    }
//}

//template <class K, class V>
//int BST<K, V>::BSTheight(TreeNode<K, V> *node){
//    if (node == NULL) {
//           return 0;
//    } else {
//        int leftHeight = BSTheight(node->left);
//        int rightHeight = BSTheight(node->right);
//        if (leftHeight > rightHeight) {
//            return(leftHeight + 1);
//        } else {
//            return(rightHeight + 1);
//        }
//    }
//}


//template <class T>
//T BST<T>::getMax(){
//    if(isEmpty())
////        return 0;
//        return NULL;
//    TreeNode *current = root;
//    while (current->right != NULL) {
//        current = current->right;
//    }
//    return current->key;
//}
//
//template <class T>
//T BST<T>::getMin(){
//  if(isEmpty())
//    return 0;
//
//  TreeNode *current = root;
//
//  while (current->left != NULL) {
//    current = current->left;
//  }
//  return current->key;
//}


//template <class K, class V>
//void BST<K, V>::iterateThroughEachNode(TreeNode<K, V> *node){
//    if(node->left != NULL) {
//        iterateThroughEachNode(node->left);
//    }
//    if(node->right != NULL) {
//        iterateThroughEachNode(node->right);
//    }
//    if(node->left == NULL && node->right == NULL) {
//        //leaf
//    }
//}
//needs to be fixed
//template <class K, class V>
//V BST<K, V>::deleteNode(const K& k){
//    if(isEmpty())
//        return false;
//    TreeNode<K, V> *parent = NULL;
//    TreeNode<K, V> *current = root;
//    bool isLeftNode = true;
//    //usual code to find a TreeNode
//    while(current->key !=k){
//        parent = current;
//        if(k < current->key){ //go left
//            isLeftNode = true;
//            current = current->left;
//        } else { //go right
//            isLeftNode = false;
//            current = current->right;
//        }
//        if(current == NULL){ //value does not exist
//            return false;
//        }
//    }
//    //if we make it here, then we found it, now lets proceed to delete
//    //case: node to delete has no children, AKA leaf node
//    if(current->left == NULL && current->right == NULL){
//        if(current == root){
//            root = NULL; //removed the node
//        } else if(isLeftNode){
//            parent->left = NULL;
//        } else{ //right child
//            parent->right = NULL;
//        }
//    }
//    //FIX THISSSS
//    //case: node to be deleted has one child. need to determine whether child is left or right
//    else if(current->right == NULL){
//        //node has left child, no right children
//        if(current == root)
//            root = current->left;
//         else if(isLeftNode)
//             parent->left = current->left;
//        else
//            parent->right = current->left;
//    }
//    else if(current->left ==NULL){
//        //node has right child, no left children
//        if(current == root)
//            root = current->right;
//        else if(isLeftNode)
//            parent ->left = current->right;
//        else
//            parent->right = current ->right;
//    } else {
//        //node to be deleted has two children. we need to find the successor in this case
//        TreeNode<K, V> *successor = getSuccessor(current); //current is the node to be deleted
//        if(current == root)
//            root = successor;
//        else if (isLeftNode)
//            parent ->left = successor;
//        else
//            parent->right = successor;
//        successor->left = current->left;
//    }
//    //TO DO!!!!!!!!!!!!!!
//    //do we delete(garbage collect) the tree in the delete function for the destructor???
//    return true;
//}
