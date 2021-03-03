//#include "huffQueue.h"
#include "heap.h"
#include <fstream>

using namespace std;

int main( int argc, char *argv[] )
{
	/*huffNode* A = new huffNode( 'a', 10 );
	huffNode* E = new huffNode( 'e', 15 );
	huffNode* I = new huffNode( 'i', 12 );
	huffNode* S = new huffNode( 's', 3 );
	huffNode* T = new huffNode( 't', 4 );
	huffNode* Y = new huffNode( 'y', 13 );
	huffNode* Z = new huffNode( 'z', 1 );

	huffTree* pA = new huffTree(A);
	huffTree* pE = new huffTree(E);
	huffTree* pI = new huffTree(I);
	huffTree* pS = new huffTree(S);
	huffTree* pT = new huffTree(T);
	huffTree* pY = new huffTree(Y);
	huffTree* pZ = new huffTree(Z);


	huffTree* arr[7] = {pA, pE, pI, pS, pT, pY, pZ};

	cout << "unsorted:" << endl;
	for( int i; i < 7; i++ )
	{
		cout << arr[i]->getRoot()->freq << " ";
	}

	cout << endl;

	heap h(7);
	for(int i=0; i<7; i++)
	{
		h.insert(arr[i]);
	}

	cout << "sorted:" << endl;
	
	h.print();
	cout << h.deleteMin()->getRoot()->freq << endl;
	h.print();
	cout << h.deleteMin()->getRoot()->freq << endl;
	h.print();
	cout << h.deleteMin()->getRoot()->freq << endl;
	h.print();
	cout << h.deleteMin()->getRoot()->freq << endl;
	h.print();
	cout << h.deleteMin()->getRoot()->freq << endl;
	h.print();
	cout << h.deleteMin()->getRoot()->freq << endl;
	h.print();
	cout << h.deleteMin()->getRoot()->freq << endl;
	h.print();*/

	/*for( int i; i < 7; i++ )
	{
		cout << arr[i]->getRoot()->freq << " ";
	}

	cout << endl;*/

	/*cout << "deleting" << endl;

	//cout << h.deleteMin()->getRoot()->freq << endl;

	cout << "done" << endl;

	cout << "third" << endl;
	for( int i; i < 7; i++ )
	{
		cout << arr[i]->getRoot()->freq << endl;
	}*/


	/*tZ.merge(tS);
	cout << tZ.getRoot()->freq << endl;
	tZ.merge(tT);
	cout << tZ.getRoot()->freq << endl;
	tZ.merge(tA);
	cout << tZ.getRoot()->freq << endl;
	tI.merge(tY);
	cout << tI.getRoot()->freq << endl;
	tE.merge(tZ);
	cout << tE.getRoot()->freq << endl;
	tI.merge(tE);
	cout << tI.getRoot()->freq << endl;*/

	//tI.print();

	string fileName = argv[1];

	unsigned* arr1 = new unsigned[256];
	for(int i; i<256; i++)
	{
		arr1[i] = {0};
	}

	ifstream file;
	file.open( fileName.c_str() );

	if( file )
	{
		char ch;

		while (file)
		{
			file.get(ch);

			if ( file.eof() )
			{
				break;
			}

			unsigned chFreq = ch;
			
			arr1[chFreq] += 1;
		}

		/*for (int i; i<256; i++)
		{
			if(arr1[i] > 0)
				cout << arr1[i] << endl;
		}*/

		heap h1(256);

		for(int i = 0; i < 256; i++)
		{
			if( arr1[i] > 0 )
			{
				huffNode* node = new huffNode(i, arr1[i]);
				huffTree* tree = new huffTree(node);
				h1.insert(tree);
			}
		}

		//h.print();

		huffTree* tree1 = new huffTree();
		huffTree* tree2 = new huffTree();

		while (!h1.oneNode())
		{
			tree1 = h1.deleteMin();
			tree2 = h1.deleteMin();
			tree1->merge(tree2);
			h1.insert(tree1);
		}

		cout << "Total Bytes: " << h1.deleteMin()->print() << endl;

		file.close();
	}



	return 0;
}


