/*-------------------------------------------------------
                    Valentino Perović

Red Black Tree class for creating and maintaining
 typical Red Black tree structure expanded by rank and
 select functions for calculating rank and select of
 wavelet trees contained in Red Black tree's nodes.

---------------------------------------------------------*/

#ifndef BIOINFORMATICS_REDBLACKTREE_H
#define BIOINFORMATICS_REDBLACKTREE_H


#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "Node.h"
#include "color.h"
#include "wTree.h"
#include "Data.h"
using namespace std;

class RedBlackTree {
private:
    Node *root; // root pointer

    /**
     *insertFix(Node* node)
     *
     * DESCRIPTION
     * function responsible for maintaining Red Black tree's
     * structure after insert of new node.
     *
     */

    void insertFix(Node *node){
        Node *uncle; // contains left/right child of node's parent depending if node is right or left child
        if(root == node){
            node->setColor(black); // you're done, just change root's color to black - 2. rule of Red Black tree
            return;
        }

        // check if parent is red and apply transformations if it is
        while(node->getParentNode() != NULL && node->getParentNode()->getColor() == red){
            Node *grandparent = node->getParentNode()->getParentNode();
            if(grandparent->getLeftNode() == node->getParentNode()){
                if(grandparent->getRightNode() != NULL){
                    uncle = grandparent->getRightNode();
                    if(uncle->getColor() == red){
                        node->getParentNode()->setColor(black);
                        uncle->setColor(black);
                        grandparent->setColor(red);
                        node = grandparent;
                    }
                    else{
                        if(node->getParentNode()->getRightNode() == node){
                            node = node->getParentNode();
                            leftRotation(node);
                        }
                        node->getParentNode()->setColor(black);
                        grandparent->setColor(red);
                        rightRotation(grandparent);
                    }
                }
                else{
                    if(node->getParentNode()->getRightNode() == node){
                        node = node->getParentNode();
                        leftRotation(node);
                    }
                    node->getParentNode()->setColor(black);
                    grandparent->setColor(red);
                    rightRotation(grandparent);
                }
            }
            else {
                if(grandparent->getLeftNode() != NULL){
                    uncle = grandparent->getLeftNode();
                    if(uncle->getColor() == red){
                        node->getParentNode()->setColor(black);
                        uncle->setColor(black);
                        grandparent->setColor(red);
                        node = grandparent;
                    }
                    else {
                        if(node->getParentNode()->getLeftNode() == node){
                            node = node->getParentNode();
                            rightRotation(node);
                        }
                        node->getParentNode()->setColor(black);
                        grandparent->setColor(red);
                        leftRotation(grandparent);
                    }
                }
                else {
                    if(node->getParentNode()->getLeftNode() == node){
                        node = node->getParentNode();
                        rightRotation(node);
                    }
                    node->getParentNode()->setColor(black);
                    grandparent->setColor(red);
                    leftRotation(grandparent);
                }
            }

            // change root's color to black just in case
            root->setColor(black);
        }
    };

    /**
     *leftRotation(Node* node)
     *
     * DESCRIPTION
     * function responsible for making normal Red Black
     * tree's left rotation.
     *
     */
    void leftRotation(Node *node){
        if(node->getRightNode() == NULL){
            return; // you're done
        }
        else {
            Node *right = node->getRightNode();

            // rotate node around it's left node
            if(right->getLeftNode() != NULL){
                node->setRightNode(right->getLeftNode());
                right->getLeftNode()->setParentNode(node);
            }
            else {
                node->setRightNode(NULL);
            }


            right->setParentNode(node->getParentNode());

            // set right as child of the parent depending on node initial position
            if(node->getParentNode() == NULL){
                root = right;
            }
            else {
                if(node == node->getParentNode()->getLeftNode()){
                    node->getParentNode()->setLeftNode(right);
                }
                else {
                    node->getParentNode()->setRightNode(right);
                }
            }

            right->setLeftNode(node);
            node->setParentNode(right);
        }
    };

    /**
     *rightRotation(Node* node)
     *
     * DESCRIPTION
     * function responsible for making normal Red Black
     * tree's right rotation. Idea is same as one for
     * left rotation.
     *
     */
    void rightRotation(Node *node){
        if(node->getLeftNode() == NULL){
            return;
        }
        else {
            Node *left = node->getLeftNode();
            if(left->getRightNode() != NULL){
                node->setLeftNode(left->getRightNode());
                left->getRightNode()->setParentNode(node);
            }
            else {
                node->setLeftNode(NULL);
            }


            left->setParentNode(node->getParentNode());


            if(node->getParentNode() == NULL){
                root = left;
            }
            else {
                if(node == node->getParentNode()->getLeftNode()){
                    node->getParentNode()->setLeftNode(left);
                }
                else {
                    node->getParentNode()->setRightNode(left);
                }
            }

            left->setRightNode(node);
            node->setParentNode(left);
        }
    };

    /**
     *
     * successor(Node *node)
     *
     * DESCRIPTION
     * finds successor of node - last right node in
     * left subtree or last left node in right subtree
     *
     */
    Node* successor(Node *node){
        Node *temp = NULL;
        if(node->getLeftNode() != NULL){
            temp = node->getLeftNode();
            while (temp->getRightNode() != NULL){
                temp = temp->getRightNode();
            }
        }
        else {
            temp = node->getRightNode();
            while (temp->getLeftNode() != NULL){
                temp = temp->getLeftNode();
            }
        }
        return temp;
    };

    /**
     *deleteFix(Node* node)
     *
     * DESCRIPTION
     * function responsible for maintaining Red Black tree
     * structure after deleting node. Not used in current
     * version of project.
     *
     */
    void deleteFix(Node *node){
        Node *temp;
        while (node != root && node->getColor() == black) {
            if (node->getParentNode()->getLeftNode() == node) {
                temp = node->getParentNode()->getRightNode();
                if (temp->getColor() == red) {
                    temp->setColor(black);
                    node->getParentNode()->setColor(red);
                    leftRotation(node->getParentNode());
                    temp = node->getParentNode()->getRightNode();
                }
                if (temp->getLeftNode()->getColor() == black && temp->getRightNode()->getColor() == black) {
                    temp->setColor(red);
                    node = node->getParentNode();
                }
                else {
                    if (temp->getRightNode()->getColor() == black) {
                        temp->getLeftNode()->setColor(black);
                        temp->setColor(red);
                        rightRotation(temp);
                        temp = node->getParentNode()->getRightNode();
                    }
                    temp->setColor(node->getParentNode()->getColor());
                    node->getParentNode()->setColor(black);
                    temp->getRightNode()->setColor(black);
                    leftRotation(node->getParentNode());
                    node = root;
                }
            }
            else {
                temp = node->getParentNode()->getLeftNode();
                if (temp->getColor() == red) {
                    temp->setColor(black);
                    node->getParentNode()->setColor(red);
                    rightRotation(node->getParentNode());
                    temp = node->getParentNode()->getLeftNode();
                }

                if (temp->getLeftNode()->getColor() == black && temp->getRightNode()->getColor() == black) {
                    temp->setColor(red);
                    node = node->getParentNode();
                }
                else {
                    if (temp->getLeftNode()->getColor() == black) {
                        temp->getRightNode()->setColor(black);
                        temp->setColor(red);
                        leftRotation(temp);
                        temp = node->getParentNode()->getLeftNode();
                    }
                    temp->setColor(node->getParentNode()->getColor());
                    node->getParentNode()->setColor(black);
                    temp->getLeftNode()->setColor(black);
                    rightRotation(node->getParentNode());
                    node = root;
                }
            }
            node->setColor(black);
            root->setColor(black);
        }
    };

    /**
     *display(Node* node)
     *
     * DESCRIPTION
     * displays Red Black tree's structure.
     *
     */
    void display(Node *node){
        if(root==NULL)
        {
            cout<<"\nEmpty Tree.";
            return ;
        }
        if(node != NULL)
        {
            if(node->getLeftNode()) {
                cout << "\n\nLeft:\n";
                display(node->getLeftNode());
            }

            // just heading for node
            cout<<"\n\t NODE: ";

            // node id
            cout<<"\n Key: " << node->getValue()->getId();

            // color heading
            cout<<"\n Color: ";

            // writes node color
            if(node->getColor() == black)
                cout<<"Black";
            else
                cout<<"Red";

            // write parent's id if parent exist
            if(node->getParentNode() != NULL)
                cout<<"\n Parent: " << node->getParentNode()->getValue()->getId();
            else
                cout<<"\n There is no parent of the node.  ";

            // write right child' id if right child exist
            if(node->getRightNode() != NULL)
                cout<<"\n Right Child: " << node->getRightNode()->getValue()->getId();
            else
                cout<<"\n There is no right child of the node.  ";

            // write left child's id if left child exist
            if(node->getLeftNode() != NULL)
                cout<<"\n Left Child: " << node->getLeftNode()->getValue()->getId();
            else
                cout<<"\n There is no left child of the node.  ";
            cout<<endl;

            // write number of elements in nodes with lower id + number of each individual element
            cout<<"\n Broj znakova lijevo "<<node->getValue()->getP();
            cout<<"\n Broj znakova A lijevo "<<node->getValue()->getNoA();
            cout<<"\n Broj znakova C lijevo "<<node->getValue()->getNoC();
            cout<<"\n Broj znakova G lijevo "<<node->getValue()->getNoG();
            cout<<"\n Broj znakova T lijevo "<<node->getValue()->getNoT();

            if(node->getRightNode())
            {
                cout<<"\n\nRight:\n";
                display(node->getRightNode());
            }
        }
    };

    unsigned long SymbolCount(Node *node,char c){
        char findC = tolower(c);
        if(findC == 'c') {
            return node ->getValue() ->getNoC();
        }
        else if(findC == 'a') {
            return node ->getValue() ->getNoA();
        }
        else if(findC == 'g') {
            return node ->getValue() ->getNoG();
        }
        else if(findC == 't') {
            return node ->getValue() ->getNoT();
        }
        else{
            return -1;
        }
    }
    unsigned long rankT(Node *node, unsigned long i, char c) {
        unsigned long numberOfSymbols = node->getValue()->getP();
        if( node->getValue()->getP()==0 ){
            return node->getWTree()->rank(c, i);
        }
        if (i <= numberOfSymbols ) {
            return rank(node->getLeftNode(), i, c);
        }
        else if (i <= numberOfSymbols + node->getWTree()->length()) {
            return SymbolCount(node, c) + node->getWTree()->rank(c, i - numberOfSymbols);
        }
        else {
            return rank(node->getRightNode(), i, c);
        }
    }
public:
    unsigned long select(Node *node, long i, char c) {
        unsigned long NumberOfSymbolAppearance = SymbolCount(node,c);
        if(NumberOfSymbolAppearance >= i){
            return select(node ->getLeftNode(),i,c);
        }
        else if(node ->getWTree() -> select(c, i-NumberOfSymbolAppearance) == -1){
            return select(node ->getRightNode(),i,c);
        }
        else{
            unsigned long x=node ->getWTree() -> select(c, i-NumberOfSymbolAppearance);
            return node ->getWTree() -> select(c, i-NumberOfSymbolAppearance) + node->getValue()->getP();
        }
    }

    /**
      *RedBlackTree()
      *
      * DESCRIPTION
      * constructor, sets root to NULL.
      *
      */
    RedBlackTree(){
        root = NULL;
    }

    /**
     *insert(long newValue, wTree *w, Data *d)
     *
     * DESCRIPTION
     * function for inserting new node in Red Black tree.
     *
     * long newValue - id of tree's node
     *
     * wTree *w - wavelet tree inserted in node
     *
     * Data *d - Data structure for this new node
     *
     */
    void insert(long newValue,wTree *w,Data *d){
        Node *p, *q;
        Node *t = new Node(w,d);


        t->setLeftNode(NULL);
        t->setRightNode(NULL);
        t->setColor(red);
        p = root;
        q = NULL;

        if(root == NULL){
            root = t;
            t->setParentNode(NULL);
        }
        else{

            // find position for new node
            while (p != NULL){
                q = p;
                if(t->getValue()->getId() > p->getValue()->getId() ){
                    p = p->getRightNode();
                }
                else{
                    p = p->getLeftNode();
                }
            }

            // insert new node
            t->setParentNode(q);
            if( t->getValue()->getId() > q->getValue()->getId() ){
                q->setRightNode(t);
            }
            else{
                q->setLeftNode(t);
            }
        }

        // fix tree structure
        insertFix(t);

    };

    /**
     *deleteNode(Node* node)
     *
     * DESCRIPTION
     * function responsible for deleting Red Black
     * tree's node.
     * Deprecated in this version of project.
     *
     */
    void deleteNode(long deleteValue){

        if(root == NULL){
            cout << "Empty tree";
            return;
        }

        Node *searched = root;
        Node *temp = NULL;
        Node *node = NULL;

        int found = 0;

        // find node for delete
        while (searched != NULL && found == 0){
            if(searched->getValue()->getId() == deleteValue){
                found = 1;
            }
            else{
                if(searched->getValue()->getId() > deleteValue){
                    searched = searched->getLeftNode();
                }
                else{
                    searched = searched->getRightNode();
                }
            }

            if(found == 0){
                cout << "Value you want to delete does'n exist";
                return;
            }
            else{
                cout << "You deleted value " << searched->getValue()->getId() << " with color " << searched->getColor() << endl;

                if(searched->getLeftNode() == NULL || searched->getRightNode() == NULL){
                    node = searched;
                }
                else {
                    node = successor(searched);
                }

                if(node->getLeftNode() != NULL){
                    temp = node->getLeftNode();
                }
                else {
                    if(node->getRightNode() != NULL){
                        temp = node->getRightNode();
                    }
                    else {
                        temp = NULL;
                    }
                }

                if(temp != NULL){
                    temp->setParentNode(node->getParentNode());
                }
                if(node->getParentNode() == NULL){
                    root = temp;
                }
                else {
                    if(node == node->getParentNode()->getLeftNode()){
                        node->getParentNode()->setLeftNode(temp);
                    }
                    else {
                        node->getParentNode()->setRightNode(temp);
                    }
                }

                if(node != searched){
                    searched->setColor(node->getColor());
                    searched->setValue(node->getValue());
                }
                if(node->getColor() == black){
                    deleteFix(temp);
                }
            }
        }
    };

    /**
     *disp()
     *
     * DESCRIPTION
     * public display function, calling display to start
     * from root node.
     *
     */
    void disp(){
        display(root);
    };

    /**
     *search(long value)
     *
     * DESCRIPTION
     * find node with specific id and write it's information.
     *
     * long value - id of node
     *
     */
    void search(long value){
        if(root==NULL)
        {
            cout<<"\nEmpty Tree\n" ;
            return  ;
        }
        Node *p = root;
        int found=0;
        while(p != NULL && found == 0)
        {
            if(p->getValue()->getId() == value)
                found=1;
            if(found==0)
            {
                if(p->getValue()->getId() < value)
                    p = p->getRightNode();
                else
                    p = p->getLeftNode();
            }
        }
        if(found==0)
            cout<<"\nElement Not Found.";
        else {
            cout << "\n\t FOUND NODE: ";
            cout << "\n Key: " << p->getValue()->getId();
            cout << "\n Colour: ";
            if (p->getColor() == black)
                cout << "Black";
            else
                cout << "Red";
            cout<<"\n Broj znakova lijevo "<<p->getValue()->getP();
            cout<<"\n Broj znakova A lijevo "<<p->getValue()->getNoA();
            cout<<"\n Broj znakova C lijevo "<<p->getValue()->getNoC();
            cout<<"\n Broj znakova G lijevo " <<p->getValue()->getNoG();
            cout<<"\n Broj znakova T lijevo "<<p->getValue()->getNoT();
        }


    };

    unsigned long rank(Node *node, unsigned long i, char c){
        return rankT(node,i,c);
    }

    /**
     *getRoot()
     *
     * DESCRIPTION
     * return root of Red Black tree instance.
     *
     */
    Node *getRoot(){
        return this->root;
    }
};

#endif //BIOINFORMATICS_REDBLACKTREE_H
