# Labirinto-Recorrente

O programa receberá através de um arquivo chamado input.data, um número K de labirintos de tamanho NxN, onde nele um garoto percorrera os labirintos pegando itens, enfrentando perigos e desviando de paredes de forma randômica, até que ele consiga ganhar o jogo ou morrer tentando.

## Objetivo

O sistema fará a leitura desses labirintos, obtidas pelo arquivo input.data, e logo começará a partir de um ponto inicial selecionado pelo usuário, andar com o garoto pelos labirintos de forma randômica. Ao caminhar pelos labirintos, o programa deveráandar de forma aleatória entre 8 direções, sendo elas todas casas ao redor do garoto. A imagem abaixo demonstra, como é a estrutura de um labirinto, todas as possibilidades que o garoto pode encontrar em seu caminho e as direções que o mesmo pode andar:

![Direções](https://user-images.githubusercontent.com/118322766/233220639-002fe992-0783-4dc4-929c-53eb24005215.png)<br>
imagem 1

Vamos supor que o garoto saiu da posição [0,1] e logo em seguida, andou para a posição [1,0] e depois para a posição [2,0], o labirinto será atualizado, como mostrado na imagem a seguir: 

![Caminhamento](https://user-images.githubusercontent.com/118322766/233205684-f5f39ca0-5320-4609-bfc7-61c2d07ee321.jpeg)<br>
imagem 2

- O garoto está sendo representado pela letra G no exemplo acima.</p>

```Movimentações: ``` </p>

- Caso o garoto ande para uma casa com número: ele vai obter um item e colocar em uma sacola, o limite máximo da sacola é de 4 itens.
- Caso o garoto ande para uma casa com * (Linha 2 e Coluna 3 da imagem 1): ele perderá 1 vida.
- Caso o garoto ande para uma casa com # (Linha 2 e Coluna 2 da imagem 1): ele não pode avançar e deve andar por outro caminho.
- Caso o garoto ande para fora dos limites do labirinto (Ande para cima da posição atual): ele cairá em um portal e será teletransportado para o próximo labirinto.

```Regras Basicas: ``` </p>

- O garoto sempre começa com 10 vidas e não pode exceder este limite.
- O garoto deve sempre andar de forma randômica pelo labirinto.
- Quando o garoto pisar em uma casa com número, ele vai pegar um item daquela posição, como na imagem 2.
- Caso o garoto ande em uma casa com número 0 (Linha 2 e Coluna 1 da imagem 1), nada vai acontecer.
- Quando o garoto estiver com quatro itens na sacola ele irá ganhar uma vida caso tenha menos que 10, ou então, caso esteja com as 10 vidas, ele vai perder todos itens.
- Caso o garoto perca todas as vidas o jogo acaba com a sua derrota.
- Para o garoto vencer o jogo ele deve percorrer todos os labirintos, porém, ele não deve pegar nenhum item quando percorrer do primeiro ao último labirinto.

```Casos Especiais: ``` </p>

- Caso o usuário insira a posição inicial, ou então, após cair em um portal o garoto fique cercado de paredes, o código retornará que infelizmente o garoto não conseguiu escapar, pois foi impossível seguir a sua jornada pelos labirintos.

## Implementação
 
- Para poder caminhar, foi criado uma matriz do mesmo tamanho do labirinto, foram criados também 2 arquivos auxiliares, o primeiro arquivo recebia todas os labirintos que foram passados para a execução do programa, o segundo arquivo inicialmente era criado sem nada escrito. Após a criação dos 2 arquivos, a matriz criada recebia o primeiro labirinto escrito no primeiro arquivo auxiliar. Logo, o garoto caminhava de forma randômica pelo labirinto, coletando os itens encontrados pelo caminho e atualizando a matriz, com a matriz atualizada depois dos itens coletados, a mesma era salva no segundo arquivo auxiliar, em seguida, se repetia o mesmo passo com todos os labirintos listados no primeiro arquivo auxiliar, e após o segundo arquivo auxiliar estar com todas os labirintos atualizados, o primeiro arquivo auxiliar era limpo e recebia todos os labirintos do segundo arquivo auxiliar, em seguida, o segundo arquivo auxiliar também era limpo, e este processo era repetido até o garoto vencer ou perder o jogo.
- Para o caminhamento de forma randômica, foi criado duas variáveis que recebiam um valor aleatório de -1 a 1, onde a primeira representava a linha e a segunda representava a coluna, e depois a linha e coluna que o garoto se encontrava, eram somadas com as variáveis contendo o valor aleatório gerado.
- Para obter resultados como: quantas casas foram percorridas, itens coletados pelo caminho e perigos enfrentados, foram criadas uma variável para cada caso, onde sempre que o garoto enfrentava um perigo ou outro caso, a variável do caso ocorrido era incrementada em uma unidade.
- Para obter o número de casas inexploradas, foram criados 2 arquivos auxiliares e uma matriz de 0 e 1 para representar as casas não exploradas, onde havia 0 a casa não havia sido explorada e onde havia 1 a casa teria sido explorada (paredes nunca são exploradas então sempre contém 0 em sua posição). Logo em seguida, era usado o mesmo processo para poder caminhar pelo labirinto, e no final da execução do programa, era contado todos os 0 dos labirintos salvos no primeiro arquivo auxiliar.
- A posição inicial selecionada pelo usuário, não será considerada como uma ação no primeiro contato do garoto com o labirinto, logo ele não sofrerá dano caso haja um perigo e nem mesmo coletará o item caso haja na casa selecionada, porém o usuário não pode selecionar um local com parade pois o mesmo será desconsiderado.
 
## Arquivos

* ```main.cpp```: Arquivo e função principal do código;
* ```Labirinto.hpp```: Criação das funções utilizadas;
* ```Labirinto.cpp```: Implementação das funções descritas no arquivo hpp;
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

![Labirintos](https://user-images.githubusercontent.com/118322766/232927513-02b92b36-ab38-4081-a163-19f1b148f098.jpeg)

Após obter os labirintos que serão utilizados, o programa inicialmente irá pedir para o usuário digitar a linha e a coluna para a posição inicial, como mostrado no exemplo abaixo foi escolhido a posição [2,2], logo em seguida, é mostrado o fim do jogo e os resultados. Veja o exemplo abaixo: 

![Resultados](https://user-images.githubusercontent.com/118322766/233192324-93e7ee08-72b0-4b8c-a2fb-5431d8a36415.jpeg)

No exemplo acima, o garoto infelizmente não conseguiu completar a sua missão pois o mesmo perdeu todas suas vidas, logo após avisar sobre sua derrota, foi listado abaixo todos os dados de sua jornada como as casas percorridas, os itens coletados pelo caminho, as casas não exploradas e os perigos enfrentados.

## Conclusão

O programa funciona corretamente como foi esperado, porém não é viável realizar a análise do custo computacional da estratégia randômica, o mesmo não é possível pois como ela é feita de forma aleatória, pode se ocorrer que após uma execição o garoto ande apenas para a direita deixando assim, um menor custo computacional se comparado com uma execução que o garoto ficou dando voltas pelos labirintos.</p>
Ademais, a estgratégia utilizada para salvar os labirintos em um arquivo, provou-se ser uma ótima escolha pois, desta forma não é preciso criar uma matriz tridimensional para salvar todos os labirintos, evitando assim, maiores chances de estourar a memória com a alocação dinâmica de matrizes.

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
