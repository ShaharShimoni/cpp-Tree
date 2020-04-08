//
// Created by shahar on 06/04/2020.
//


#include<string>
using namespace std;
namespace family{

//    class Node{
//        string root;
//        Node mother;
//        Node father;
//    };

   class Tree;



}
class family::Tree{
public:
    string root;
    Tree *mother;
    Tree *father;
    Tree *left;
    Tree *right;


    Tree(string root, Tree &left, Tree &right,Tree &mother, Tree &father) { // Constructor with parameters
        this->root=root;
        this->left=&left;
        this->right=&right;
        this->mother=&mother;
        this->father=&father;
    }
    Tree(){
        //this->root=" ";
        this->left=NULL;
        this->right=NULL;
        this->mother=NULL;
        this->father=NULL;
    }
    Tree(string root){
        this->root=root;
        this->left=NULL;
        this->right=NULL;
        this->mother=NULL;
        this->father=NULL;
    }

//        Tree(string root);
//
//        Tree(string root, Tree &left, Tree &right, Tree &mother, Tree &father);
//
//        Tree();


    Tree& search(string son);

    Tree& addFather(string son, string father);

    Tree& addMother(string son, string mother);
    string relation_help(string name,string prefix);
    string relation(string name);
    string find_help(string name,string prefix,int count);
    string find(string name);
    void erase();
    void remove_help(string name);

    Tree& remove(string name);

    void display();



    int display_help();

};


