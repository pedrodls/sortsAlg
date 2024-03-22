
#include<stdio.h>
#include<stdlib.h>

struct Heap {
	int key;
	int value;
	struct Heap *left;
	struct Heap *right;
	struct Heap *next;
}typedef heap;

heap *buildHeap(heap *myHeap, int key, int size, int vet[]){
	 
	 if(key < ((size - 1)/2)){
	 	
		heap *parent = (heap*)malloc(sizeof(heap));
	 	
	 	if(!myHeap){
		 	parent->key = key;
		 	parent->value = vet[key];
		 	parent->left = NULL;
		 	parent->right = NULL;
	    }else
	    	parent = myHeap->left;
	 	 	
	 	//Left
	 	if((key*2 + 1) < (size)){
	 		
	 		heap *child = (heap*)malloc(sizeof(heap));
	 	
			 	child->key = (key*2) + 1;
			 	child->value = vet[(key*2) + 1];
			 	child->left = NULL;
			 	child->right = NULL;
			 	
	 		if(!myHeap){
			 	parent->left = child;
			}else{
				myHeap->left = child;
			}
		 }
		 
		 //right
	 	if((key*2 + 2) < (size)){
	 		
	 		heap *child = (heap*)malloc(sizeof(heap));
	 	
			 	child->key = (key*2) + 2;
			 	child->value = vet[(key*2) + 2];
			 	child->left = NULL;
			 	child->right = NULL;
			 	
	 		if(!myHeap){
			 	parent->right = child;
			}else{
				myHeap->right = child;
			}
		 }
		 
		 if(!myHeap)
			{
			 myHeap = parent;	
			}
		
			
		 buildHeap(myHeap, ++key, size, vet);		 
	 }
	 
	 return myHeap;
	 	
}

void printHeap (heap *myHeap, int size, int key){
	
	heap *aux = myHeap;
	
	while(aux != NULL && (key < ((size - 1)/2))){
	
	
		 	
	 	printf("%d\n", aux->value);
	 		 	
	 	//Left
	 	if((key*2 + 1) < (size)){
	 		
	 		printf("%d - ", aux->left->value);
	 		
        }
		 
		 //right
	 	if((key*2 + 2) < (size)){
	 		printf("%d", aux->right->value);
	    }
		 
 		key++;
 		
 		aux = aux->next;			
		 
    }
}


int main(){
	 
	 int vet[]={4, 3, 7, 9};
	 
	 heap *myHeap = (heap*)malloc(sizeof(heap));
	 
	 myHeap = NULL;
	 
	 myHeap = buildHeap(myHeap, 0, sizeof(vet)/sizeof(vet[0]), vet);
 	
 	 printHeap(myHeap, sizeof(vet)/sizeof(vet[0]), 0);
 	 
 	
	 
	 
	 
	 return 0;
}




























