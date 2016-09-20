#include "Tree.h"
#include <cstdlib>
#include <iostream>

//binary search tree

struct TreeNode{
	ElementType Element;
	SearchTree  Left;
	SearchTree  Right;
};

SearchTree makeEmpty( SearchTree T ){
	if( T != NULL)
	{
		makeEmpty(T->Left);
		makeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position find( ElementType X, SearchTree T ){
	if(T == NULL)
		return NULL;
	if( X < T->Element)
		return find(X, T->Left);
	else if(X > T->Element)
		return find(X, T->Right);
	else
		return T;
}

Position findMin( SearchTree T ){
	if(T == NULL){
		return NULL;
	}
	if( T->Left = NULL){
		return T;
	}
	else{
		return findMin(T);
	}
}

Position findMax( SearchTree T ){
	if(T == NULL){
		return NULL;
	}
	if( T->Right = NULL){
		return T;
	}
	else{
		return findMax(T);
	}
}

SearchTree insert( ElementType X, SearchTree T ){
	if(T == NULL){
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		T->Element = X;
		T->Left = T->Right = NULL;
	}
	else{
		if(X < T->Element){
			T->Left = insert(X, T->Left);
		}
		else if(X > T->Element){
			T->Right = insert(X, T->Right);
		}
		//else X is in the Tree
		//do nothing
	}
	return T;
}

SearchTree del( ElementType X, SearchTree T ){
	if(T == NULL){
		std::cerr << "Element not found" << std::endl;
	}
	else if(X < T->Element)
		T->Left = del(X, T);
	else if(X > T->Element)
		T->Right = del(X, T);
	else{
		Position tmp;
		if(T->Left && T->Right){ //Two childen
			// replace with the smallest in right subtree
			tmp = findMin( T->Right );
			T->Element = tmp->Element;
			T->Right = del(T->Element, T->Right);
		}
		else{ // one or zero child
			tmp = T;
			if(T->Left = NULL)
				T = T->Right;
			else if(T->Right == NULL)
				T = T->Left;
			free(tmp);
		}
	}
	return T;
}