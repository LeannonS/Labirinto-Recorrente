# Labirinto-Recorrente

O programa receberá através de um arquivo chamado input.data, um número K de labirintos de tamanho NxN, onde nele um garoto percorrera os labirintos pegando itens, enfrentando perigos e desviando de paredes de forma randômica, até que ele consiga ganhar o jogo ou morrer tentando.

## Objetivo

O sistema fará a leitura desses labirintos, obtidas pelo arquivo input.data, e logo começará a partir de um ponto inicial selecionado pelo usuário, andar com o garoto pelos labirintos de forma randômica. Ao caminhar pelos labirintos, o programa deveráandar de forma aleatória entre 8 direções, sendo elas todas casas ao redor do garoto. A imagem abaixo demonstra, como é a estrutura de um labirinto, todas as possibilidades que o garoto pode encontrar em seu caminho e as direções que o mesmo pode andar:

![Labirinto-Exemplo](https://user-images.githubusercontent.com/118322766/232914381-9569c6c1-b785-4ac5-b68c-62406cac4b31.jpeg)

```Movimentações: ``` </p>

- Caso o garoto ande para uma casa com número: ele vai obter um item e colocar em uma sacola, o limite máximo da sacola é de 4 itens.
- Caso o garoto ande para uma casa com * (Linha 2 e Coluna 3 da imagem acima): ele perderá 1 vida.
- Caso o garoto ande para uma casa com # (Linha 2 e Coluna 2 da imagem acima): ele não pode avançar e deve andar por outro caminho.
- Caso o garoto ande para fora dos limites do labirinto: ele cairá em um portal e será teletransportado para o próximo labirinto.

```Regras Basicas: ``` </p>

- O garoto sempre começa com 10 vidas e não pode exceder este limite.
- Quando o garoto pisar em uma casa com número, ele vai pegar um item daquela posição, ou seja, se o mesmo andar para uma casa com o número 2, após obter o item a posição irá ficar com o número 1.
- Caso o garoto ande em uma casa com número 0 (Linha 2 e Coluna 1 da imagem acima), nada vai acontecer.
- Quando o garoto estiver com quatro itens na sacola ele irá ganhar uma vida caso tenha menos que 10, ou então, caso esteja com as 10 vidas, ele vai perder todos itens.
- Caso o garoto perca todas as vidas o jogo acaba com a sua derrota.
- Para o garoto vencer o jogo ele deve percorrer todos os labirintos, porém, ele não deve pegar nenhum item quando percorrer do primeiro ao último labirinto.

```Casos Especiais: ``` </p>

- Caso o usuário insira a posição inicial, ou então, após cair em um portal o garoto fique cercado de paredes, o código retornará que infelizmente o garoto não conseguiu escapar, pois foi impossível seguir a sua jornada pelos labirintos.

## Implementação
 

 
## Arquivos

* ```main.cpp```: Arquivo e função principal do código;
* ```input.data```: Labirintos a serem utilizadas;
* ```Makefile```: Automatiza processos de compilação;
* ```ArquivoVerificador.txt```: Arquivo criado durante a execução do algoritimo, tal arquivo verificará as casas que o garoto andou;

## Funções

* ```void criandoLabirinto()```: Cria o labirinto e o verificador que vai mostrar por onde o garoto andou.
* ```void deletandoLabirinto()```: Deleta o labirinto e o verificador que vai mostrar por onde o garoto andou.

* ```void apagarArquivos()```: Apaga todos arquivos auxiliares criados durante a execução do código.
* ```void criandoArquivoAuxiliar()```: Cria o primeiro arquivo auxiliar, onde salvará todos os labirintos e, cria o segundo arquivo auxiliar, onde salvará todos os labirintos atualizados, após o garoto percerrer e pegar os itens.
* ```void atualizarSegundoArquivoAuxiliar()```: Sempre que o garoto completar um labirinto, o novo labirinto atualizado será inserida no segundo arquivo auxiliar.
* ```void atualizarArquivoAuxiliar()```: Atualiza o arquivo auxiliar sempre que o garoto percorrer todos labirintos, ou seja, primeiro arquivo auxiliar vai ser limpo e receber todos labirintos do segundo arquivo auxiliar.

* ```void criandoArquivoVerificador()```: Cria o primeiro arquivo verificador, responsável por verificar por onde o garoto andar, o mesmo vai ser iniciado com 0 em todas as casas dos labirintos, cria também o segundo arquivo verificador, responsável por salvar o labirinto marcando com 1 após o garoto completa-lo.
* ```void atualizarSegundoArquivoVerificador()```: Sempre que o garoto completar um labirinto, um labirinto com mesmo tamanho do original contendo 0 e 1 onde o garoto andoi, será inserida no segundo arquivo verificador
* ```void atualizarArquivoVerificador()```: Atualiza o arquivo verificador sempre que o garoto percorrer todos labirintos, ou seja, arquivo verificador vai ser limpo e receber todos labirintos do segundo arquivo verificador.

* ```void obtendoPosicaoInicial()```: Obtém a posição inicial inserida pelo usuário.
* ```void obtendoPosicaoAleatoria()```: Obtém uma posiçãp aleatória após o garoto pegar um portal.
* ```void verificandoParedes(int linha, int coluna)```: Função responsável por verificar se o garoto não está cercado de paredes.

* ```void pegandoValoresLabirinto()```: Esta função vai ler o primeiro labirinto do primeiro arquivo auxiliar e salvar na variável labirinto, também vai ler o primeiro labirinto verificador e salvar na variável labirinto.
* ```void caminhandoLabirinto()```: Seleciona aleatoriamente o caminho a ser percorrido pelo garoto.
* ```void verificandoSacola()```: Verifica quantos itens tem na sacola.
* ```bool verificarPasso(int newLinha, int newColuna)```: Após o caminho selecionado na função ```void caminhandoLabirinto()```, verifica o que foi encontrado em seu caminho (perigo, item ou parede);
* ```int verificarCasasInexploradas()```: Conta o número de casas não exploradas nos labirintos obtidos no arquivo verificador, as casas não exploradas são representadas por 0;
* ```void printResultados()```: Mostra todos os resultados obtidos pelo caminho como, perigos enfrentados, casas percorridas, casas não exploradas e número de itens pegos.

## Exemplos de compilação

Na imagem a seguir temos um exemplo de 3 labirintos de tamanho 4x4, obtidos através do arquivo input.data.

![Labirinto 4x4x3](https://user-images.githubusercontent.com/118322766/232927513-02b92b36-ab38-4081-a163-19f1b148f098.jpeg)

Após obter os labirintos que serão utilizados, o programa mostrará 

imagem

- 

## Conclusão



## Compilação e Execução

Esse código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contato

✉️ <i>leanndrosousac@gmail.com</i>
</a>
