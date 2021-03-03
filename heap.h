#ifndef HEAP_H
#define HEAP_H

#include "huffTree.h"
#include <iostream>
#include <string>

class heap 
{
	public:
		heap( unsigned cap );
		void insert( huffTree* node );
		void swap( unsigned index1, unsigned index2 );
		//void heapify( unsigned sz, unsigned index );
		void heapUp( unsigned index );
		//void buildHeap();
		huffTree* deleteMin();
		void print();
		bool oneNode();
	private:
		huffTree** huffArr;
		unsigned sz;
		unsigned cap;

		void percolateDown( huffTree* node);
}; //huffQueue class

heap::heap( unsigned cap )
{
	huffArr = new huffTree*[cap];
	for ( unsigned i = 0; i < cap; i++)
	{
		huffArr[i] = 0;
	}
	sz = 0;
	this->cap = cap;
}

/*void heap::heapify( unsigned sz, unsigned index )
{
	unsigned smallest = index;
	unsigned left = 2 * index + 1;
	unsigned right = 2 * index + 2;

	if ( left < sz && huffArr[left]->getRoot()->freq < huffArr[smallest]->getRoot()->freq )
		smallest = left;

	if ( right < sz && huffArr[right]->getRoot()->freq < huffArr[smallest]->getRoot()->freq )
		smallest = right;

	if ( smallest != index )
	{
		swap( index, smallest );
		heapify( sz, smallest);
	}
}*/

void heap::swap( unsigned index1, unsigned index2 )
{
	huffTree* temp = huffArr[index1];
	huffArr[index1] = huffArr[index2];
	huffArr[index2] = temp;
}

/*void heap::buildHeap()
{
	int start = ( cap / 2 ) - 1;

	for ( int i = start; i >= 0; i-- )
	{
		heapify( cap, i );
	}
}*/

void heap::heapUp( unsigned index )
{
	unsigned parent = (index - 1) / 2;

	if (huffArr[parent]->getRoot()->freq > 0)
	{
		if ( huffArr[index]->getRoot()->freq < huffArr[parent]->getRoot()->freq)
		{
			swap(index, parent);
			heapUp(parent);
		}
	}
}


void heap::insert( huffTree* node )
{
	sz++;
	unsigned i = sz-1;

	while (i && node->getRoot()->freq < huffArr[(i-1) / 2]->getRoot()->freq)
	{
		huffArr[i] = huffArr[(i-1) / 2];
		i = (i-1) / 2;
	}
	huffArr[i] = node;
}

huffTree* heap::deleteMin()
{
	huffTree* temp = huffArr[0];
	huffArr[0] = huffArr[sz-1];
	sz--;
	percolateDown(huffArr[0]);

	return temp;
}

void heap::percolateDown( huffTree* node)
{
	unsigned i = 0;

	while ( ((i+1) * 2) - 1 < sz 
		&& ( node->getRoot()->freq > huffArr[((i+1) * 2) - 1]->getRoot()->freq 
		|| node->getRoot()->freq > huffArr[(i+1) * 2 ]->getRoot()->freq ) )
	{
		if ( huffArr[(i+1) * 2]->getRoot()->freq > huffArr[((i+1) * 2) - 1]->getRoot()->freq )
		{
			huffArr[i] = huffArr[((i+1) * 2) - 1];
			i = ((i+1) * 2) - 1;
		}
		else
		{
			huffArr[i] = huffArr[(i+1) * 2];
			i = (i+1) * 2;
		}
	}
	huffArr[i] = node;
}

void heap::print()
{
	for(unsigned i=0; i < sz; i++)
	{
		cout << huffArr[i]->getRoot()->freq << " ";
	}

	cout << endl;
}

bool heap::oneNode()
{
	return (sz == 1);
}

#endif // huffQueue_h

