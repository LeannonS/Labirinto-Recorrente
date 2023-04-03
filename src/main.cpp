#include <bits/stdc++.h>
#include "Labirinto.hpp"

using namespace std;

int main() 
{
  Labirinto l(10, 0, 0, 0, 0);
  int flag;

  l.criandoArquivoAuxiliar();
  l.criandoLabirinto();
  l.pegandoValoresLabirinto();
  l.deletandoLabirinto();

  cout << "Casas percorridas ao todo: " << l.getPassos() << endl;
  cout << "Soma de itens coletados pelo caminho: " << l.getItensPegos() << endl;
  cout << "Perigos enfrentados durante o caminho: " << l.getPerigos() << endl;

  remove("arquivoAuxiliar.txt");
  remove("segundoArquivoAuxiliar.txt");
  
  return 0;
}