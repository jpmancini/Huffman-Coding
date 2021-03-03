#ifndef HUFFNode_H
#define HUFFNode_H

#include <iostream>
#include <string>

class huffNode 
{
	public:
		huffNode( const int& );
		void setCh( const char& );
		char& getCh();
		void setFreq( const int& );
		int& getFreq();
		void setID( const int& );
		int& getID();
		void setLeft( huffNode * );
		huffNode *getLeft() const;
		void setRight( huffNode * );
		huffNode *getRight() const;
	private:
		char ch;
		int freq;
		string ID;
		huffNode *left;
		huffNode *right;

}; //huffNode class

huffNode::huffNode( const char& ch )
{
  this->ch = ch;
  this->freq = 0;
  this->ID = "";
  this->left = 0;
  this->right = 0;

} //huffNode::huffNode

void huffNode::setCh( const char& ch )
{
  this->ch = ch;
} //huffNode::setCh

char& huffNode::getCh()
{
  return ch;
} //huffNode::getCh

void huffNode::setFreq( const int& freq )
{
  this->freq = freq;
} //huffNode::setFreq

int& huffNode::getFreq()
{
  return freq;
} //huffNode::getFreq

void huffNode::setID( const string& ID )
{
  this->ID = ID;
} //huffNode::setID

string& huffNode::getID()
{
  return ID;
} //huffNode::getID

void huffNode::setLeft( huffNode *left )
{
  this->left = left;
} //huffNode::setLeft

huffNode *huffNode::getLeft() const
{
  return left;
} //huffNode::getLeft

void huffNode::setRight( huffNode *right )
{
  this->right = right;
} //huffNode::setRight

huffNode *huffNode::getRight() const
{
  return right;
} //huffNode::getRight

#endif // huffNode_H

