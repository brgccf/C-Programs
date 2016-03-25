/*
LISTA DUPLAMENTE ENCADEADA: ESTRUTURA QUE APONTA PRA FRENTE E PRA TRAS AO MESMO TEMPO

--> LISTA CIRCULAR:
temos varios processos, mas queremos que eles rodem em paralelo (ao mesmo tempo).
Pondo-os numa lista circular, podemos realizar facilmente esta dinâmica, ao mesmo tempo em que podemos remover
ou adicionar processos facilmente.
O ultimo elemento desta lista aponta para o primeiro. Caso ele seja o primeiro, aponte pra ele mesmo
