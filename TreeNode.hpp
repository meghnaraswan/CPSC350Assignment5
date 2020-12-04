#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
#include "Student.hpp"
#include "Faculty.hpp"
#include <map>
#include <string>

template <class K, class V> //template to operate on generic types
class TreeNode{
    public:
        TreeNode();
        TreeNode(const K&, const V&);
        ~TreeNode();

        K key;
        V value;
        TreeNode *left;
        TreeNode *right;
        TreeNode *parent;
//        Student s;
//        Faculty f;
        int level;
        void print();
    
        void moveLevelUp();
    
        string level_to_str();
        string valueToCSV();
};


#endif /* TreeNode_hpp */
