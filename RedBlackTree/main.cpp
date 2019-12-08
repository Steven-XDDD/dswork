#include "RedBlackTree.h"

int main(int argc, char *argv[])
{
//	RedBlackTree<int> A(1);
	RedBlackTree<int> B(3);
	B.insert(1);
	B.insert(1);	
	B.insert(1);
	B.insert(1);	
	B.insert(1);	
	B.insert(1);
	std::cout << "Height of B." << B.height() << std::endl;
	B.display();
//	BinaryTree<int>::Node *t = B.getRoot();
//	t = t->left;
//	t->color = BLACK;
//	B.transplant(B.getRoot(), t);
//	B.display();
	return 0;
}
