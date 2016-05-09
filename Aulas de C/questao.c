/*
    Escreva um programa que receba a quantidade de turmas (0 =< turmas =< 5), o nome da turma com no maximo dois caracteres(s1, s2, ...), a quantidade de alunos de cada turma (qtd_alunos > 0), e a nota de cada aluno (0.0 <= nota <= 10.0). Para cada turma, o programa deve informar a porcentagem de alunos aprovados e reprovados, as maiores e menores notas e a média da turma. Ao final o programa deve imprimir o nome da turma com o maior numero de aprovacoes e a turma com a maior nota e a maior nota. Garanta que o programa apenas receba notas entre 0 e 10 e tenha no maximo 5 turmas.
*/

#include <stdio.h>

int main() {
    
    int qtd_turmas,   // quantidade de turmas
        qtd_alunos,   // quantidade de alunos
        qtd_alunos_a, // quantidade de alunos aprovados
        qtd_alunos_r; // quantidade de alunos reprovados
    
    int i, j; // variaveis de controle para os for's
    
    float nota, // nota lida de cada aluno
          soma, // soma de todas as notas
          media, // media das notas de cada turma
          porc_a, // porcentagem de alunos aprovados em cada turma
          porc_r, // porcentagem de alunos reprovados em cada turma
          maior_n, // maior nota de uma turma
          menor_n, // menor nota de uma turma
          maior_g = 0, // maior nota dentre todas
          maior_n_a = 0; // maior taxa de aprovação dentre todas
    
    char turma_c1, turma_c2, // nome da turma formada por dois caracteres ex: s1
         turma_m_a_c1, turma_m_a_c2; // nome da turma com maior taxa de aprovacao
         turma_m_n_c1, turma_m_n_c2; // nome da turma com maior nota de aprovacao
    
    // garantindo a quantidade de turmas 
    do {
        printf("digite a quantidade de turmas:");
        scanf("%d", &qtd_turmas);
    }while(qtd_turmas < 0 || qtd_turmas > 5);
    
    
    turma_m_a_c1 = turma_c1;
    turma_m_a_c2 = turma_c2;
    
    // para cada turma
    for(i = 0; i < qtd_turmas; i++) {
        printf("digite o nome da turma: ");
        scanf(" %c%c", &turma_c1, &turma_c2);
        
        // garantindo a quantidade de alunos
        do {
            printf("digite a qtd de alunos: ");
            scanf("%d", &qtd_alunos);
        } while(qtd_alunos =< 0);
        
        // esses contadores serao reinicializados para cada turma
        soma = 0; // para calculo da media
        qtd_alunos_a = 0; // quantidade de alunos aprovados
        qtd_alunos_r = 0; // quantidade de alunos reprovados
        maior_n = 0;  // maior nota
        menor_n = 10; // menos nota
        
        // para cada aluno de uma turma
        for(j = 0; j < qtd_alunos; j++) {

            // valida a nota do aluno entre 0 e 10
            do {
                printf("digite a nota do aluno %d: ", j+1);
                scanf("%f", &nota);
            }while(nota < 0.0 || nota > 10.0);
            
            // pega a maior nota
            if(nota > maior_n) {
                maior_n = nota;
            }
            
            // pega a menor nota
            if(nota < menor_n) {
                menor_n = nota;
            }
            
            // calcula a soma de todas as notas para o calculo
            // da media
            soma = soma + nota;        
            
            // conta a quantidade de alunos ...
            if(nota >= 7.0) {
                // ... aprovados
                qtd_alunos_a++;
            }
            else {
                // ... reprovados
                qtd_alunos_r++;
            }
        }
        
        media = soma / qtd_alunos; // media das notas dos alunos
        
        // e necessario fazer uma conversao explicita dos tipos de dados
        // se ambos forem inteiros a divisao abaixo sempre vai dar zero
        // para evitar isso a qtd_alunos_x foi convertida para float
        // assim o resultado vai ser diferente de zero, pois um float / int 
        // e um float
        
        porc_a = (float) qtd_alunos_a / qtd_alunos; // porcentagem alunos aprovados
        porc_r = (float) qtd_alunos_r / qtd_alunos; // porcentagem alunos reprovados
        
        
        // nome da turma com a maior nota e a maior nota de todas
        if(maior_n > maior_g) {
            maior_g = maior_n;
            turma_m_n_c1 = turma_c1;
            turma_m_n_c2 = turma_c2;
        }
        
        // nome da turma com maior porcentagem de aprovacao e a maior taxa de aprovacao
        if(porc_a > maior_n_a) {
            maior_n_a = porc_a;
            turma_m_a_c1 = turma_c1;
            turma_m_a_c2 = turma_c2;
        }
        
        printf("%c%c media: %.2f apr: %.2f%% rep: %.2f%%\n", turma_c1, turma_c2, media, porc_a*100.0, porc_r*100);
        
    }
    
    printf("a turma com maior tx de aprovacao foi %c%c %.2f\n", turma_m_a_c1, turma_m_a_c2, maior_n_a*100);
    printf("a maior nota de todas foi: %.2f", maior_g);
    
    return 0;
 
}







