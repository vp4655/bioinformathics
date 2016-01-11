//
// Created by Administrator on 7.1.2016..
//

#ifndef BIOINFORMATICS_WTREE_H
#define BIOINFORMATICS_WTREE_H


#include <iostream>
using namespace std;
#include <string>
#include <map>
#include <bitset>
#include <sstream>
#include <vector>
#include <algorithm>
#include "wNode.h"

class wTree {

    wNode *root;
    int depth;

private:
    bool calculateValue(wNode node,char c){
        vector<char> alfbt=node.getAlfbt();
        int nHalf=1.0*alfbt.size()/2+0.5;
        int pos=find(alfbt.begin(), alfbt.end(), c) - alfbt.begin();

        //cout<<endl<<" nalaztime se na dubini "<<depth<<"   "<<pos<<" "<<nHalf<<endl;
        bool v = false;
        if ( pos>=nHalf) {
            v = true;
        }
        return v;
    }
    int rankRecurs(wNode node, char c, int i, int depth, int maxDepth) {


        bool  v = calculateValue(node,c);

        int iNew = count(node.getVec().begin(), node.getVec().begin() + i, v);

        if (v) {

            if (node.isIsRLeaf()) {
                return iNew;
            } else {
                return rankRecurs(*node.getRChild(), c, iNew, depth + 1, maxdepth);
            }
        } else {

            if (node.isIsLLeaf()) {
                return iNew;
            } else {
                return rankRecurs(*node.getLChild(), c, iNew, depth + 1, maxdepth);
            }
        }

    }

public:
    wTree(string s,vector<char> al)  {


        root=new wNode(nullptr ,0,s,al);


    }
    wNode *getRoot() const {
        return root;
    }
    int rank(char c,int i) {
        int ranke=rankRecurs(*root,c,i+1,0,maxdepth);

        return ranke;
    }
    int length(){
        return root->getVec().size();
    }
    wNode getLeafNode(char c,wNode node){
        bool  v = calculateValue(node,c);
        if (v) {

            if (node.isIsRLeaf()) {
                return node;
            } else {
                return getLeafNode(c,*node.getRChild());
            }
        } else {

            if (node.isIsLLeaf()) {
                return node;
            } else {
                return getLeafNode(c,*node.getLChild());
            }
        }


    }


    int selectRecurs(wNode node, char c, int j){


        bool  v = calculateValue(node,c);
        for (int i=0;i<node.getVec().size()+1;i++){
            int jNew = count(node.getVec().begin(), node.getVec().begin() +i, v);
            if (jNew==j){


                if (node.getParent()== nullptr) {
                    return i;
                } else {
                    return selectRecurs(*node.getParent(),c,i-1);
                }
            }
        }
        return -1;

    }

    int select (char c, int j){
        wNode beginNode=getLeafNode(c,*root);
        cout<<endl;

        return selectRecurs(beginNode,c,j);
    }
};
#endif //BIOINFORMATICS_WTREE_H