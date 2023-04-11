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
  l.deletandoLabirinto();
  l.printResultados();
  
  remove("arquivoAuxiliar.txt");
  remove("segundoArquivoAuxiliar.txt");
  remove("arquivoVerificador.txt");
  remove("segundoArquivoVerificador.txt");
  
  return 0;
}
