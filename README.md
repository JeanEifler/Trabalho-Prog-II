# Trabalho Programação II
## Instituto Federal De Santa Catarina (Câmpus Florianópolis)
## Alunos: Jean Eifler, Thiago de Lira

## Introdução

    Este trabalho visa implementar e comparar a ordenação radix com o método de ordenação quick para uma variável de um arquivo .csv

## Ordenação Radix

    Se dá de forma a separar os algarismos, colocar em determinada ordem de crescimento/decrescimento e repetir o processo até que todos os algarismos estejam ordenados.
    
## Desenvolvimento

    A implementação foi baseada em um código contido na wikipedia, conforme registrado em Referências, onde a escolha por utilizá-lo se deu por não fazer uso da estrutura lista encadeada do tipo fila, que poderia distorcer o tempo de ordenação, e também por não fazer uso de 10 vetores (quantidade de algarismos 0..9) todos com tamanho da quantidade de linhas do arquivo (garantir que os algarismos caibam no vetor) fazendo um grande uso de memória.
    O código respondeu muito bem as alterações necessárias, e os testes para comprovar seu funcionamento se deram através da ferramenta de Valgrind disponibilizada no moodle e por print do vetor ordenado no console da IDE eclipse.

PS: A ordenação QuickSort não libera corretamente seus ponteiros como demonstrado no Valgrind, problema que não conseguimos resolver, por isso os testes foram realizados antes da implementação QuickSort. 

## Resultados

    Média RadixSort (20x) = 0.021700 s

    Média QuickSort (20x) = 0.044200 s

Teste feito em um dos computadores do LPDE 

## Referências
https://www.kaggle.com/carlolepelaars/toy-dataset

https://homepages.dcc.ufmg.br/~cunha/teaching/20121/aeds2/radixsort.pdf

http://www.inf.ufg.br/~hebert/disc/aed1/AED1_05_ordenacao2.pdf

https://pt.wikipedia.org/wiki/Radix_sort

Como programar - [6ª ed] (Deitel & Deitel) - 2011.

Cormen - (Algoritmos - Teoria e prática) [6ª ed.].
