//
// Created by Valentino on 20.11.2015..
//

#ifndef BIOINFORMATICS_NODE_H
#define BIOINFORMATICS_NODE_H

#include "color.h"
#include "Data.h"
#include <iostream>
#include "wTree.h"
using namespace my_color;

class Node {

private:
    Data *value;
    Color color;
    Node *rightNode;
    Node *leftNode;
    Node *parentNode;
    wTree *w;

public:
    Data* getValue(){
        return this->value;
    }
    void setValue(Data* value){
        this->value = value;
    }
    Color getColor(){
        return this->color;
    }
    void setColor(Color color){
        this->color = color;
    }
    Node *getRightNode(){
        return this->rightNode;
    }
    void setRightNode(Node *node){
        this->rightNode = node;
    }
    Node *getLeftNode(){
        return this->leftNode;
    }
    bool isLeaf(){
        return false;
    }
    void setLeftNode(Node *node){
        this->leftNode = node;
    }
    Node *getParentNode(){
        return this->parentNode;
    }
    void setParentNode(Node *parent){
        this->parentNode = parent;
    }
    wTree *getWTree(){
        return this->w;
    }
    Node(){

        this->color = black;
        this->rightNode = this;
        this->leftNode = this;
        this->parentNode = this;
    }


    Node(wTree *w, Data *value) : w(w), value(value) {


        this->color = black;
        this->rightNode = this;
        this->leftNode = this;
        this->parentNode = this;
    }
};


#endif //BIOINFORMATICS_NODE_H
