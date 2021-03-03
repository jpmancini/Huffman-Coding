#ifndef HUFFQUEUE_H
#define HUFFQUEUE_H

class qNode
{
	public:
	    qNode( huffNode* & node );
		void setNext( qNode* & node );
		qNode* getNext(); 
	private:
		qNode* next;
		huffNode* content;
};

    qNode::qNode( huffNode* & node )
    {
        this->content = node;
        this->next = 0;
    }

	void qNode::setNext( qNode* & node )
	{
		this->next = node;
	}

	qNode* qNode::getNext()
	{
		return next;
	}

#endif // qNode_h