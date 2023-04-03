#include <bits/stdc++.h>

#ifndef LABIRINTO_HPP_INCLUDED
#define LABIRINTO_HPP_INCLUDED

using namespace std;

class Labirinto
{
  private:
    string **labirinto;
    int linha, coluna, tamLabirinto, numLabirinto;
    int vidas, passos, itensPegos, perigos, sacola;

  public:

	  Labirinto(int vidas, int passos, int itensPegos,int perigos, int sacola);
    Labirinto();

    void setVidas(int vidas);
    int getVidas();
    void setPassos(int passos);
    int getPassos();
    void setItensPegos(int itensPegos);
    int getItensPegos();
    void setPerigos(int perigos);
    int getPerigos();
    void setSacola(int sacola);
    int getSacola();

    void criandoLabirinto();
    void deletandoLabirinto();

    void apagarArquivos();
    void criandoArquivoAuxiliar();
    void atualizarArquivoAuxiliar();
    void atualizarSegundoArquivoAuxiliar();

    void obtendoPosicaoInicial();
    void obtendoPosicaoAleatoria();
    void verificandoParedes(int linha, int coluna);

    void pegandoValoresLabirinto();
    void caminhandoLabirinto();
    void verificandoVida();
    void verificandoSacola();
    int verificarPasso(int newLinha, int newColuna);
};
#endif