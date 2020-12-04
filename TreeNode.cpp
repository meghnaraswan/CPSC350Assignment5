#include "TreeNode.hpp"
#include "Student.hpp"
#include "Faculty.hpp"
#include <map>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <class K, class V>
TreeNode<K, V>::TreeNode(){
    left = NULL;
    right = NULL;
    parent = NULL;
    level = 0;
}

//template <class K, class V>
template <class K, class V>
TreeNode<K, V>::TreeNode(const K& k, const V& v){
    key = k;
    value = v;
    left = NULL;
    right = NULL;
    parent = NULL;
}

template <class K, class V>
TreeNode<K, V>::~TreeNode(){}

template <class K, class V>
void TreeNode<K, V>::print(){
    cout << level_to_str() << "Key: " << key << endl;
    cout << level_to_str() << "Value: " << value.toString() << endl;
    if (left){
        left->print();
    }
    if (right){
        right->print();
    }
}

template <class K, class V>
string TreeNode<K, V>::level_to_str(){
    string ret_val = "";
    for(int i=1; i<=level;i++) {
        ret_val += "\t";
    }
    return ret_val;
}

template <class K, class V>
string TreeNode<K, V>::valueToCSV(){
    return value.toCSV();
}

template <class K, class V>
void TreeNode<K, V>::moveLevelUp() {
    level -= 1;
    if(left)
        left->level -= 1;
    if(right)
        right->level -= 1;
}

template class TreeNode<int, Student>;
template class TreeNode<int, Faculty>;
