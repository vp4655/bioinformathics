/* Marta Postenjak
 *
 * Class created for creating and mantaining wavelet tree. It can work on any alpabet provided.
 * It has rank and select functions imeplemented.
 *
 */

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
    /*
     * It is function that calculates how char should be represetned as zero or as one depending on its postition in alphabet
     */
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

    /*
     * Function that calculates rank recursivly. It starts with root and goes in appropirate child.
     */
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
    /*
     * It is constructor for class. It accepts string s that needs to be put in tree and vector<char> that represent alphabet
     */
public:
    wTree(string s,vector<char> al)  {


        root=new wNode(nullptr ,0,s,al);


    }
    /*
     *Getter for root
     */
    wNode *getRoot() const {
        return root;
    }
    /*
     * Function which user calls when he wants the rank of ceartin sign in certain length. Function than delegates job to rankRecurs
     */
    int rank(char c,int i) {
        int ranke=rankRecurs(*root,c,i+1,0,maxdepth);

        return ranke;
    }
    /*
     * Function returns length of string contained in wavelet tree
     */
    int length(){
        return root->getVec().size();
    }

    /**
     * Function gets last node in wavelet tree that contains char c in alphabet
     */
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

    /**
     * Recursive function that tells position of j-th appiriance of sign c
     */

    int selectRecurs(wNode node, char c, int j){


        bool  v = calculateValue(node,c);

        for (int i=0;i<node.getVec().size()+1;i++){
            int jNew = count(node.getVec().begin(), node.getVec().begin() +i, v);
            if (jNew==j){


                if (node.getParent()== nullptr) {
                    return i-1;
                } else {
                    return selectRecurs(*node.getParent(),c,i);
                }
            }
        }
        return -1;

    }

    /**
     * Function that user calls when one wants to select position of j-th apperance of char c. Function delegates job to seletcRecurs
     */
    int select (char c, int j){
        wNode beginNode=getLeafNode(c,*root);
        cout<<endl;

        return selectRecurs(beginNode,c,j);
    }
};
#endif //BIOINFORMATICS_WTREE_H