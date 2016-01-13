/*Marta Postenjak
 *
 * Class represent single node which is building block for wavelet tree. It contains vector of bits, parent node and left and right chiid.
 * It also contains alphabet based on which we can interperet meaning of bit.
 */

#ifndef BIOINFORMATICS_WNODE_H
#define BIOINFORMATICS_WNODE_H


#include <iostream>
using namespace std;
#include <string>
#include <map>
#include <bitset>
#include <sstream>
#include <vector>
#include <algorithm>


#define maxdepth 1

class wNode {

    wNode* parent;
    wNode* lChild;
    wNode* rChild;
    int nodeDepth;
    vector <bool> vec;
    bool isLLeaf;
    bool isRLeaf;
    vector <char> alfbt;


/**
 * Constructor for wNode class. It gets parent node, string s, and vector<bit> as parametars.It generetas all nodes needen for single tree beacuse it is
 * recursive.
 */
public:

    wNode(wNode *parent, int noDepth,string s,vector<char> al) : parent(parent), nodeDepth(noDepth),alfbt(al) {
        string left,right;
        int nHalf=1.0*alfbt.size()/2+0.5;
        //nHalf+=alfbt.size()%2;
        for (int i=0;i<s.length();i++){

            int pos=find(alfbt.begin(), alfbt.end(), s[i]) - alfbt.begin();

            if (pos<nHalf) {
                left+=s[i];
                vec.push_back(0);
            }

            else{
                right+=s[i];
                vec.push_back(1);
            }



        }
        //cout<<"left "<<left<<endl;
        //cout<<"right "<<right<<endl;


        if (alfbt.size()>2){

            int nHalf=1.0*alfbt.size()/2+0.5;
            isLLeaf=false;
            lChild=new wNode(this ,nodeDepth+1,left,vector<char>(alfbt.begin(),alfbt.begin()+nHalf));
            if (alfbt.size()>3) {
                rChild=new wNode(this ,nodeDepth+1,right,vector<char>(alfbt.begin()+nHalf,alfbt.end()));
                isRLeaf=false;
            } else {
                isRLeaf=true;
            }
        } else {
            isLLeaf=true;
            isRLeaf=true;
        }
    }

    /**
     * Getter for parents node.
     */
    wNode *getParent() const {
        return parent;
    }

    /*
     * Getter for left child
     */
    wNode *getLChild() const {
        return lChild;
    }

    /**
     * Getter for right child
     */
    wNode *getRChild() const {
        return rChild;
    }

    /**
     * Getter for depth of node
     */
    int getNodeDepth() const {
        return nodeDepth;
    }


    /**
     * Getter for bool variable if node is left  child of its parent
     */
    bool isIsLLeaf() const {
        return isLLeaf;
    }

    /**
     * Getter for bool variable if node is right  child of its parent
     */
    bool isIsRLeaf() const {
        return isRLeaf;
    }

    /*
     * Getter for values
     */
    const vector<bool, allocator<bool>> &getVec() const {
        return vec;
    }

    /*
     * Getter for alfabet
     */
    const vector<char> &getAlfbt() const {
        return alfbt;
    }
};
#endif //BIOINFORMATICS_WNODE_H