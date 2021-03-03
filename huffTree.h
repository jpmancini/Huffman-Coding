#ifndef HUFFTREE_H
#define HUFFTREE_H

#include <string>
#include <iostream>
#include <math.h>
#include <iomanip>
 
using namespace std;

struct huffNode
{
    huffNode* left;
    huffNode* right;
    char ch;
    unsigned freq;

    huffNode()
    {
        this->ch = 0;
        this->freq= 0;
        this->left = 0;
        this->right = 0;
    }

    huffNode( char ch, const unsigned freq )
    {
        this->ch = ch;
        this->freq= freq;
        this->left = 0;
        this->right = 0;
    }
};

class huffTree
{
    public:
        huffTree();
        huffTree( huffNode*& root );
        unsigned print();
        void merge( huffTree*& );
        unsigned getWeight();
        huffNode* getRoot();
        
    private:
        unsigned print( huffNode* root, int codes[], unsigned& index);
        huffNode* root;
        unsigned weight;
        unsigned height;
        int* codes;
};


huffTree::huffTree()
{
    this->root = 0;
    this->weight = 0;
    this->height = 0;
}

huffTree::huffTree( huffNode*& root )
{
    this->root = root;
    weight = root->freq;
}

void huffTree::merge(huffTree* &tree)
{
    huffNode* newNode = new huffNode();
    newNode->freq = weight + tree->getWeight();

    if ( weight > tree->getWeight() )
    {
        newNode->left = tree->getRoot();
        newNode->right = root;
    }
    else
    {
        newNode->left = root; 
        newNode->right = tree->getRoot();
	}
    root = newNode;
    weight = weight + tree->getWeight();
    height++;
}

unsigned huffTree::print()
{
    codes = new int[height];
    unsigned index = 0;
    return print( root, codes, index);
}

unsigned huffTree::print( huffNode* root, int codes[], unsigned& index )
{
        unsigned total = 0;

        if (root->left)
        {
            codes[index] = 0;
            unsigned newIndex = index + 1;
            total += print( root->left, codes, newIndex );
        }
       
        if (root->right)
        {
            codes[index] = 1;
            unsigned newIndex = index + 1;
            total += print( root->right, codes, newIndex );
        }
       
        if ( !(root->left ) && !( root->right ) ) 
        {
            cout << "Char: " << root->ch << " Code: "; 
            for (unsigned i=0; i < index; i++)
                cout << codes[i];  
            cout << " Frequency: " << root->freq << endl;
            double len = index;
            double uses = root->freq;
            //cout << "Bits: " << (len * uses)  << endl;
            //cout << "Bytes: " << ceil((len * uses) / 8) << endl;
            total += ceil((len * uses) / 8);
        }

        return total;
}

unsigned huffTree::getWeight()
{
    return weight;
}

huffNode* huffTree::getRoot()
{
    return root;
}


#endif