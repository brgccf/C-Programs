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

int main(int argc, char const *argv[])
{
	int key;
	while(1)
	{
		scanf("%d", &key);
		if(!key) break;
		insert(key);
	}

	return 0;
}