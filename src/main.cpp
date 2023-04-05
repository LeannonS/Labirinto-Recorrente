#include <bits/stdc++.h>
#include "Labirinto.hpp"

using namespace std;

int main() 
{
  Labirinto l(10, 0, 0, 0, 0);

  l.criandoArquivoAuxiliar();
  l.criandoArquivoVerificador();
  l.criandoLabirinto();
  l.pegandoValoresLabirinto();

  cout << endl << "Casas percorridas ao todo: " << l.getPassos() << endl;
  cout << "Soma de itens coletados pelo caminho: " << l.getItensPegos() << endl;
  cout << "Número de casas não exploradas no labirinto: " << l.verificarCasasInexploradas() << endl;
  cout << "Perigos enfrentados durante o caminho: " << l.getPerigos() << endl;

  l.deletandoLabirinto();
  remove("arquivoAuxiliar.txt");
  remove("segundoArquivoAuxiliar.txt");
  remove("arquivoVerificador.txt");
  remove("segundoArquivoVerificador.txt");
  
  return 0;
}
