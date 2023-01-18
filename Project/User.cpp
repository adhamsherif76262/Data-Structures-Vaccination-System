#include "User.h"
#include "assert.h"



template <class T>
Node<T>::Node()
{
	left = right = NULL;

}


template <class T>
Node<T>::Node(T val)
{
	Nat_Id = val;
	left = right = NULL;
}

template <class T>
BSTree<T>::BSTree()
{
	root = NULL;
}
template <class T>
bool BSTree<T>::contains(T val)  //bet5alini at2akd lw el node dih mawgoda wala la2
{
	// 1- han3ml temporary pointer aybtdi men el root
	Node<T>* tmp = root;
	while (tmp != 0 && val != tmp->Nat_Id)

		if (val < tmp->Nat_Id)
			tmp = tmp->left;
		else
			tmp = tmp->right;

	return(tmp != 0);//ya3ni howa la2aa el value f hayrturn true

	//mmken a3ml badal kol dah 
	/* Node<T>* tmp = findNode(val);
	   return(tmp != 0); */
}

template <class T>
Node<T>* BSTree<T>::findNode(T val)
{
	Node<T>* tmp = root;
	while (tmp != 0 && val != tmp->Nat_Id)

		if (val < tmp->Nat_Id)
			tmp = tmp->left;
		else
			tmp = tmp->right;

	return(tmp);//hay-return pointer beta3 el node el ana 3ayzaha 

}


template <class T>
void BSTree<T>::insert(T val)
{
	////assert(!contains(val));
	//awl node hatigi hatba2a heya el root
	Node<T>* new_Pointer = new Node<T>(val);

	if (root == 0)

		root = new_Pointer;

	else
	{
		//han3ml temporary pointer aybtdi men el root
		Node<T>* tmp = root;
		while (true)
		{
			if (val < tmp->Nat_Id)
				if (tmp->left == 0)
				{
					tmp->left = new_Pointer;
					break;
				}
				else
					tmp = tmp->left;

			else
				if (tmp->right == 0)
				{
					tmp->right = new_Pointer;
					break;
				}
				else
					tmp = tmp->right;

		}
	}
}

