#include <stdio.h>
#include <stdlib.h>

int pos[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void imprimir() {
	int i, j;
	for(i=0;i<8;i++) {
		for(j=0; j<8; j++) {
			if(pos[j] == i) printf("D");
			else printf(".");
		}
		printf("\n");
	} printf("\n");
}

void gerar(int k)
{
	if(k == 8) imprimir();
	else {
		int i, j;
		for(i=0;i<8;i++) {
			pos[k] = i;
			int prob = 0;
			for(j=0;j<k && !prob;j++) {
				prob |= (pos[k] == pos[j]);
				prob |= (abs(pos[k] - pos[j]) == abs(k-j));
			}
			if(!prob) gerar(k+1);
		}
	}
}

int main() {
	gerar(0);
	return 0;
}