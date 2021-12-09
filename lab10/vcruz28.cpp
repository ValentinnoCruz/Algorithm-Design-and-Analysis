/*****************************************************************
*
*    Author: Brian Hungerman
*    Date: 11/24/2018
*    Description: Greedy Algo for Huffman Codes
*
******************************************************************/
#include <queue>
#include <map>
#include <iostream>
#include <iterator>

using namespace std;

int len;

typedef vector<bool> CodeVector;
typedef map<int, CodeVector> CodeMap;

/* Superclass of Node [to distinguish between inny and leafy*/
class Node
{
  public:
	int freq;
	virtual ~Node() {} //allows for dynamic cast
	Node(int freqIn)
	{
		freq = freqIn;
	}
};
class NodeInny : public Node
{
  public:
	Node *l;
	Node *r;
	NodeInny(Node *ll, Node *rr) : Node(ll->freq + rr->freq)
	{
		l = ll;
		r = rr;
	}
};
class NodeLeafy : public Node
{
  public:
	int index;
	NodeLeafy(int freq, int indexIn) : Node(freq)
	{
		index = indexIn;
	}
};
struct NodeComparer
{
	bool operator()(Node *l, Node *r)
	{
		/* If frequency is the same, check index */
		if (l->freq == r->freq)
		{
			int lIndex = -1, rIndex = -1;
			if (NodeLeafy *ll = dynamic_cast<NodeLeafy *>(l))
				lIndex = ll->index;
			else
			{
				Node *ptrNode = l;
				while (lIndex == -1)
				{
					if (NodeLeafy *ll = dynamic_cast<NodeLeafy *>(ptrNode))
						lIndex = ll->index;
					else
						ptrNode = dynamic_cast<NodeInny *>(ptrNode)->l;
				}
			}
			if (NodeLeafy *rr = dynamic_cast<NodeLeafy *>(r))
				rIndex = rr->index;
			else
			{
				Node *ptrNode = r;
				while (rIndex == -1)
				{
					if (NodeLeafy *rr = dynamic_cast<NodeLeafy *>(ptrNode))
						rIndex = (int)rr->index;
					else
						ptrNode = dynamic_cast<NodeInny *>(ptrNode)->l;
				}
			}
			return lIndex > rIndex;
		}
		/* Else choose greater frequency*/
		return l->freq > r->freq;
	}
};

void makeCode(Node *node, const CodeVector &codePtr, CodeMap &code)
{
	/* If is an internal node */
	if (NodeInny *nodeI = dynamic_cast<NodeInny *>(node))
	{
		CodeVector l = codePtr;
		l.push_back(false);
		makeCode(nodeI->l, l, code);

		CodeVector r = codePtr;
		r.push_back(true);
		makeCode(nodeI->r, r, code);
	}

	/* If is a leaf */
	else if (NodeLeafy *nodeL = dynamic_cast<NodeLeafy *>(node))
	{
		code[nodeL->index] = codePtr;
	}
}

Node *makeTree(int *values)
{
	priority_queue<Node *, vector<Node *>, NodeComparer> tree;

	/* Populate tree */
	for (int i = 0; i < len; i++)
	{
		NodeLeafy *newLeaf = new NodeLeafy(values[i], i);
		tree.push(newLeaf);
	}
	//cout << tree.top();
	while (tree.size() > 1)
	{
		Node *r = tree.top();
		tree.pop();
		Node *l = tree.top();
		tree.pop();
		Node *p = new NodeInny(r, l);
		tree.push(p);
	}
	return tree.top();
}

int main()
{
	/* First Input: Length of Array */
	cin >> len;
	int values[len];

	/* Take in Array Values */
	for (int i = 0; i < len; i++)
	{
		cin >> values[i];
	}

	/* Generate codes from tree, store in "code"*/
	CodeMap code;
	makeCode(makeTree(values), CodeVector(), code);

	/* Use Iterator to print codes */
	for (CodeMap::const_iterator i = code.begin(); i != code.end(); i++)
	{
		copy(i->second.begin(), i->second.end(), ostream_iterator<bool>(cout));
		cout << "\n";
	}
	return 0;
}