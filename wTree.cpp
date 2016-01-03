// Example program
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
            lChild=new wNode(nullptr ,nodeDepth+1,left,vector<char>(alfbt.begin(),alfbt.begin()+nHalf));
            if (alfbt.size()>3) {
                rChild=new wNode(nullptr ,nodeDepth+1,right,vector<char>(alfbt.begin()+nHalf,alfbt.end()));
                isRLeaf=false;
            } else {
                isRLeaf=true;
            }
        } else {
            isLLeaf=true;
            isRLeaf=true;
        }
    }

    wNode *getParent() const {
        return parent;
    }

    wNode *getLChild() const {
        return lChild;
    }

    wNode *getRChild() const {
        return rChild;
    }

    int getNodeDepth() const {
        return nodeDepth;
    }


    bool isIsLLeaf() const {
        return isLLeaf;
    }

    bool isIsRLeaf() const {
        return isRLeaf;
    }

    const vector<bool, allocator<bool>> &getVec() const {
        return vec;
    }


    const vector<char> &getAlfbt() const {
        return alfbt;
    }
};

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
        for (int i=0;i<node.getVec().size();i++){
            int jNew = count(node.getVec().begin(), node.getVec().begin() + i, v);
            if (jNew==j){

                if (node.getParent()== nullptr) {
                    return jNew;
                } else {
                    return selectRecurs(*node.getParent(),c,j);
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

/*
int main(){

    string s ="ACGGGACCGTTTTTAGGA";
    vector <char> alfa{'A','C','G','T'};
    wTree* w=new wTree(s,alfa);

    cout<<s;
    cout<<endl<<"Rank znaka A do i=5 je"<<w->rank('A',5);
    cout<<endl<<"Rank znaka C do i=8 je"<<w->rank('C',8);
    cout<<endl<<"Rank znaka G do i=4 je"<<w->rank('G',2);
    cout<<endl<<"Rank znaka A do i=0 je"<<w->rank('A',0)<<endl;


    vector<char> alfic=w->getRoot()->getLChild()->getAlfbt();
    for (int i=0;i<alfic.size();i++) {
        cout<<alfic[i];
    }

    string s ="121334533322173276";
    vector <char> alfa{'1','2','3','4','5','6','7'};
    wTree* w=new wTree(s,alfa);
    cout<<s;
    cout<<endl<<"Rank znaka A do i=9 je"<<w->rank('7',13);
    int j=w->select('7',1);
    cout<<j;
    /*
    for (int i=0;i<w->getRoot()->getVec().size();i++) {
        cout<<w->getRoot()->getVec()[i];
    }

    return 0;
}

*/

