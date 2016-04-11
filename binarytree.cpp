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

son* tree_search(son *sub_root, k)
{
	if (!sub_root || k == sub_root->key)
	{
		return sub_root;
	}
	if (k < sub_root->key)
	{
		return tree_search(sub_root->left, k);
	}
	else return tree_search(sub_root->right, k);
}

son* tree_minimum(son *sub_root)
{
	if(!sub_root->left)
	{
		return sub_root;
	}
	else return tree_minimum(sub_root->left)
}

son* tree_sucessor(son* sub_root)
{
	if (sub_root->right)
	{
		return tree_minimum(sub_root->right);
	}
	son* temp = sub_root; //p[x]
	// while(temp && sub_root = temp->right)
	// {
	// 	sub_root = temp;
	// 	temp = 
	// }

}

void remove_key(int k, son *sub_root)
{
	if(!root) printf("No elements left!\n");
	
}

void print_tree(son *sub_root)
{
	if (sub_root)
	{
		print_tree(sub_root->left);
		printf("%d \n", sub_root->key);
		print_tree(sub_root->right);
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