#include "bits/stdc++.h"

typedef struct son
{
	int key;
	struct son *right;
	struct son *left;
}son;
son *root = NULL;


void insert(int k)
{
	printf("===ENTROU EM INSERT===\n");
	son *node = (son*) malloc (sizeof(son));
	node->key = k;
	node->right = NULL;
	node->left = NULL;
	if(!root)
	{
		root = node;
		printf("NOVA RAIZ: %d\n", root->key);
	}
	else
	{
		son *temp = root;
		int added = 0;
		while(!added)
		{
			if (k < temp->key)
			{
				if (temp->left)temp = temp->left;
				else 
				{
					temp->left = node;
					printf("Adicionado: %d na arvore esquerda de %d\n", temp->left->key, temp->key);
					added = 1;
				}
			}
			else
			{
				if (temp->right)temp = temp->right;
				else
				{
					temp->right = node;
					printf("Adicionado: %d na arvore direita de %d\n", temp->right->key, temp->key);
					added = 1;
				}
			}
		}
	}
}

void remove_key(int k, son *sub_root)
{
	son *node = sub_root;
	son *parent = NULL;
	while(node != NULL && node->key != k)
	{
		parent = node;
		if(k < node->key) node = node->left;
		else node = node->right;
	}
	if(node == NULL) 
	{
		printf("the key %d is NOT in the tree!\n", k);
		return;
	}
	if(node != root)
	{
		if(node->left == NULL) //possui um filho a direita
		{
			if(k <= parent->key) parent->left = node->right;
			else parent->right = node->right;
			printf("Value %d Removed from the tree!\n", node->key);
			delete(node);
		}
		else if (node->right == NULL) //possui um filho a esquerda
		{
			if(k <= parent->key) parent->left = node->left;
			else parent->right = node->left;
			printf("Value %d removed from the tree!\n", node->key);
			delete(node);
		}
		else //caso tenha dois filhos
		{
			printf("It's a node with 2 childs!\n");
			son *node1 = node->left;
			son *parent1 = node;
			//pegando o filho com maior key antes do nó com dois filhos
			while(node1->right != NULL)
			{
				parent1 = node1;
				node1 = node1->right;
			}
			//apos o while podemos deletar
			parent1->right = node1->left;
			printf("Removed %d from the tree!\n", node->key);
			node->key = node1->key;
			printf("value %d replaced in the node!\n", node->key);
			delete(node1);
		}
	}

	
}

void print_tree(son *sub_root)
{

	if (sub_root)
	{
		print_tree(sub_root->left);
		
		print_tree(sub_root->right);
		printf("%d ", sub_root->key);
	}
}

int main(int argc, char const *argv[])
{
	int key, k;
	while(1)
	{
		scanf("%d", &key);
		if(!key) break;
		if (key == 30)
		{
			printf("which remove?\n");
			scanf("%d", &k);
			remove_key(k, root);
		}
		else if(key == 40) print_tree(root);
		else insert(key);
	}

	return 0;
}