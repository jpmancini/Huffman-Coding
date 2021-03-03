#ifndef HUFFQUEUE_H
#define HUFFQUEUE_H

#include "huffTree.h"
#include "qNode.h"
#include <iostream>
#include <string>

class huffQueue 
{
	public:
		huffQueue();
		void push( huffNode* & node );
        huffNode* pop();
	private:
		unsigned sz;
		huffNode* front;
		huffNode* back;
}; //huffQueue class

huffQueue::huffQueue()
{
    this->sz = 0;
    this->front = 0;
} //huffQueue::huffQueue

void huffQueue::push( huffNode* & node)
{
	qNode* newNode = new qNode( node );

	if ( sz == 0 )
	{
		front = newNode;
	}
	else
	{
		newNode->setNext(back);
	}

	back = newNode;
	sz++;
}

huffNode* huffQueue::pop()
{
	if( sz == 0 )
	{
		return 0;
	}
	
	huffNode* node = 0;

	if( sz == 1)
	{
		node = back;
		delete back;
		front = 0;
		back = 0;
	}
	else
	{
		qNode* newPtr = back;
		node = newPtr;
		back = back->getNext();
		delete newPtr;
	}

	return node;
}

#endif // huffQueue_h

