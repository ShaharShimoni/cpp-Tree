//
// Created by shahar on 06/04/2020.
//

#include "FamilyTree.hpp"
#include <iostream>


family::Tree& family::Tree:: search(string son) {

    if(this) {
        if (this->root == son) {
          //  cout << "yes i found" << this->root << endl;
            return *this;
        }
        else {

                Tree &ans1=this->father->search(son);
                //cout << ans1.root<< endl;

                //cout << "search in mother" << endl;
                Tree &ans2=this->mother->search(son);
                //cout << ans2.root<< endl;
                if(ans1.root==son){
                    return ans1;
                }
               if(ans2.root==son){
                return ans2;
                }


        }
    }
    Tree a=Tree("0");
    Tree &b=a;
    return b;



}

family::Tree& family::Tree::addFather(string son, string father){
      Tree &temp=this->search(son);
     // cout<<"cameback the one im going to add a father is: "<<temp.root<<endl;
      Tree *a=new Tree(father);
      temp.father=a;
     // cout<<"father="<<temp.father->root<<endl;
     return *this;

}
family::Tree& family::Tree::addMother(string son, string mother){
    Tree &temp=this->search(son);
   // cout<<"cameback the one im going to add a mother is: "<<temp.root<<endl;
    Tree *a=new Tree(mother);
    temp.mother=a;
    return *this;
}

string family::Tree::relation_help(string name,string prefix) {
       if (!this){
           return "0";
       }
       if(this->mother)
       if (this->mother->root == name) {
           return prefix + "mother";
       }
       if(this->father)
       if(this->father->root==name){
           return prefix+"father";
       }
           string a=  this->mother->relation_help(name,"great-"+prefix);
           string b=   this->father->relation_help(name,"great-"+prefix);
           if(a!="0"){
               return a;
           }
           if(b!="0"){
              return b;
           }
           else
               return "0";


}

string family::Tree::relation(string name){
       if (this->root==name){
           return "me";
       }
       if(this->mother->root==name){
           return "mother";
       }
       if(this->father->root==name){
           return "father";
       }
       else {
           string a = this->father->relation_help(name, "grand");
           string b = this->father->relation_help(name, "grand");
           if(a!="0"){
               return a;
           }
           if(b!="0"){
               return b;

           }
       }

return "unrelated";
}

string family::Tree::find_help(string name,string prefix,int count) {

        if((name==prefix+"mother")){
            if(this->mother){
                return this->mother->root;
            }
        }
        if((name==prefix+"father")){
            if(this->father){
                return this->father->root;
            }
        }


            string add = "grand";
            string add2 = "great-";
            if (count == 0) {
                //cout<<"add grand"<<endl;
                prefix = add + prefix;
                count=1;
            }
            else {
                //cout<<"add great-"<<endl;
                prefix = add2 + prefix;
            }

            string a, b = "0";
            if (this->mother) {

                a = this->mother->find_help(name, prefix, count);


            }
            if (this->father) {

                b = this->father->find_help(name, prefix, count);

            }

            if (a != "0" && a!="") {

                return a;
            }
            if (b!="0"&& b!="") {

                return b;
            }

            else
                return "0";


}

string family::Tree::find(string name){
      if (name=="me"){
          return this->root;
      }
      string a="0";
      a=this->find_help(name,"",0);
      //cout<<"a afer function"<<a<<endl;
      if(a!="0"){
          return a;
      }
      throw exception();


}
void family::Tree::erase() {

    if (this) {
        //cout << "in erase" << endl;
         if(this->father) {
             //cout << "there is a father" << endl;
             this->father->erase();
          }
        if (this->mother) {
           // cout << "there is a mother" << endl;
            this->mother->erase();
        }

         this->root="0";
//        free(this);
//        cout<<this->root<<endl;
    }


}



void family::Tree::remove_help(string name){
    if(this) {
        if (name == this->root) {
            //cout<<"in removehelp"<<endl;
            if(this->father) {
              //  cout<<"sending to erase ther ia a father"<<endl;
                this->father->erase();
            }
            if(this->mother) {
               // cout<<"sending to erase ther ia a mother"<<endl;
                this->mother->erase();

            }
           // cout<<"after erase"<<this->root<<endl;
            this->root="0";

          //  cout<<"after free"<<endl;
            //return *this;
        }
        else {
            if(this->father)
            this->father->remove_help(name);
            if(this->mother)
            this->mother->remove_help(name);
        }
    }




}

family::Tree& family::Tree::remove(string name){

    if(this->root==name){
        throw exception();
    }
    Tree& save=*this;
    this->remove_help(name);
   // cout<<"done"<<endl;
    return save;
}

int family::Tree::display_help() {

    int a=0;
    int b=0;
    if(this) {
        if (this->root!= "0") {
            if (this->father) {
                a = this->father->display_help();
            }
            if (this->mother) {
                b = this->mother->display_help();
            }
            if (b == 1 && a == 1)
                cout << this->father->root << " " << this->mother->root << endl;
            else if (a == 1 && b == 0)
                cout << this->father->root << endl;
            else if (a == 0 && b == 1)
                cout << this->mother->root << endl;

            return 1;
        }
        else
            return 0;
    }
    else
        return 0;


}

void family::Tree::display() {

    int c=0;
    if(this)
     c=this->display_help();
    if(c==1)
    cout<<this->root<<endl;

}


