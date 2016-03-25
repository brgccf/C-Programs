#include <stdio.h>
#include <stdlib.h>
//programa para dizer quais posições dos bits estão ativadas (1)
int main()
{
    
    unsigned int n;
    scanf("%i", &n);
	int i;  
    for(i = 0; i < 8; i++)
    {	
    //o if so sera verdade quando o & funcionar
		if(n & (1 << i))
		{
			printf("%d\n", i+1);
		}
		
    }
    return 0;
    
}
