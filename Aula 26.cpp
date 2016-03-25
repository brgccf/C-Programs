/*
Estrutura Deque: Implementa Lista encadeada e Pilha ao mesmo tempo!
Há um comportamente de prioridades dependendo da necessidade

Insection-sort:
Algoritmo de ordenação que utiliza um array (desordenado) e uma lista.
Colocamos cada elemento do array de forma ordenada na lista e depois
passamos tal ordenação para o array
-- Pior caso O(n²). Com sorte: O(n)

*SkipList --> Metodo mais eficiente de busca por um elemento numa lista
consiste basicamente em criar novos 'heads' e ir sorteando elementos
aleatorios da lista criando novas 'pequenas listas' nesses heads.
Dai, quando estiver num head com poucos elementos,
verificamos o elemento procurado em passos, apontando para o head
posterior caso chegamos num final de um head e o valor que procuramos
ainda é maior. 
