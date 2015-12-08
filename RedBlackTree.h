//
// Created by Valentino on 20.11.2015..
//

#ifndef BIOINFORMATICS_REDBLACKTREE_H
#define BIOINFORMATICS_REDBLACKTREE_H


#include <iostream>
#include "Node.h"
#include "color.h"
using namespace std;

class RedBlackTree {
private:
    Node *root;
    Node *sentinel;
    void insertFix(Node *node){
        Node *uncle;
        if(root == node){
            node->setColor(black);
            return;
        }
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
            root->setColor(black);
        }
    };
    void leftRotation(Node *node){
        if(node->getRightNode() == NULL){
            return;
        }
        else {
            Node *right = node->getRightNode();
            if(right->getLeftNode() != NULL){
                node->setRightNode(right->getLeftNode());
                right->getLeftNode()->setParentNode(node);
            }
            else {
                node->setRightNode(NULL);
            }

            if(node->getParentNode() != NULL){
                right->setParentNode(node->getParentNode());
            }

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

            if(node->getParentNode() != NULL){
                left->setParentNode(node->getParentNode());
            }

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
    void display(Node *node){
        if(root==NULL)
        {
            cout<<"\nEmpty Tree.";
            return ;
        }
        if(node != NULL)
        {
            cout<<"\n\t NODE: ";
            cout<<"\n Key: " << node->getValue();
            cout<<"\n Colour: ";
            if(node->getColor() == black)
                cout<<"Black";
            else
                cout<<"Red";
            if(node->getParentNode() != NULL)
                cout<<"\n Parent: " << node->getParentNode()->getValue();
            else
                cout<<"\n There is no parent of the node.  ";
            if(node->getRightNode() != NULL)
                cout<<"\n Right Child: " << node->getRightNode()->getValue();
            else
                cout<<"\n There is no right child of the node.  ";
            if(node->getLeftNode() != NULL)
                cout<<"\n Left Child: " << node->getLeftNode()->getValue();
            else
                cout<<"\n There is no left child of the node.  ";
            cout<<endl;

            if(node->getLeftNode()) {
                cout << "\n\nLeft:\n";
                display(node->getLeftNode());
            }
            if(node->getRightNode())
            {
                cout<<"\n\nRight:\n";
                display(node->getRightNode());
            }
        }
    };

public:
    RedBlackTree(){
        root = NULL;
        sentinel = NULL;
    }
    void insert(long newValue){
        Node *p, *q;
        Node *t = new Node;
        t->setValue(newValue);
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
            while (p != NULL){
                q = p;
                if(t->getValue() > p->getValue() ){
                    p = p->getRightNode();
                }
                else{
                    p = p->getLeftNode();
                }
            }
            t->setParentNode(q);
            if( t->getValue() > q->getValue() ){
                q->setRightNode(t);
            }
            else{
                q->setLeftNode(t);
            }
        }
        insertFix(t);
    };
    void deleteNode(long deleteValue){
        if(root == NULL){
            cout << "Empty tree";
            return;
        }

        Node *searched = root;
        Node *temp = NULL;
        Node *node = NULL;

        int found = 0;

        while (searched != NULL && found == 0){
            if(searched->getValue() == deleteValue){
                found = 1;
            }
            else{
                if(searched->getValue() > deleteValue){
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
                cout << "You deleted value " << searched->getValue() << " with color " << searched->getColor() << endl;

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
    void disp(){
        display(root);
    };
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
            if(p->getValue() == value)
                found=1;
            if(found==0)
            {
                if(p->getValue() < value)
                    p = p->getRightNode();
                else
                    p = p->getLeftNode();
            }
        }
        if(found==0)
            cout<<"\nElement Not Found.";
        else {
            cout << "\n\t FOUND NODE: ";
            cout << "\n Key: " << p->getValue();
            cout << "\n Colour: ";
            if (p->getColor() == black)
                cout << "Black";
            else
                cout << "Red";
        }
    };

};

#endif //BIOINFORMATICS_REDBLACKTREE_H
