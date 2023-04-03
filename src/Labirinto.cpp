#include "Labirinto.hpp"

Labirinto::Labirinto(int vidas, int passos, int itensPegos, int perigos, int sacola)
{
  setVidas(vidas);
  setPassos(passos);
  setItensPegos(itensPegos);
  setPerigos(perigos);
  setSacola(sacola);
}
Labirinto::Labirinto()
{
}

void Labirinto::setVidas(int vidas)
{
  this->vidas = vidas;
}
int Labirinto::getVidas()
{
  return this->vidas;
}

void Labirinto::setPassos(int passos)
{
  this->passos = passos;
}
int Labirinto::getPassos()
{
  return this->passos;
}

void Labirinto::setItensPegos(int itensPegos)
{
  this->itensPegos = itensPegos;
}
int Labirinto::getItensPegos()
{
  return this->itensPegos;
}

void Labirinto::setPerigos(int perigos)
{
  this->perigos = perigos;
}
int Labirinto::getPerigos()
{
  return this->perigos;
}

void Labirinto::setSacola(int sacola)
{
  this->sacola = sacola;
}
int Labirinto::getSacola()
{
  return this->sacola;
}

void Labirinto::criandoLabirinto()
{
  this->labirinto = new string*[this->tamLabirinto];
  
  for (int i = 0; i < this->tamLabirinto; i++)
  {
    this->labirinto[i] = new string[this->tamLabirinto];
  }
}

void Labirinto::deletandoLabirinto()
{
  for (int i = 0; i < this->tamLabirinto; i++)
  {
    delete[] this->labirinto[i];
  }
  delete[] this->labirinto;
}

void Labirinto::apagarArquivos()
{
  remove("arquivoAuxiliar.txt");
  remove("segundoArquivoAuxiliar.txt");
  
  exit(1);
}

void Labirinto::criandoArquivoAuxiliar()
{
  ofstream arqAux;
  ifstream arq;
  string line;

  arq.open("input.data");
  if(!arq.is_open())
  {
    cout << "Erro na abertura do arquivo: input.data!!!" << endl;
    exit(1);
  }
  arqAux.open("arquivoAuxiliar.txt");

  arq >> this->tamLabirinto;
  arq >> this->tamLabirinto;
  arq >> this->numLabirinto;
  
  while(arq)
  {
    getline(arq, line);
    arqAux << line;
    arqAux << "\n";
  }
  
  arq.close();
  arqAux.close();
  
  arqAux.open("segundoArquivoAuxiliar.txt");
  arqAux.close();
}

void Labirinto::atualizarArquivoAuxiliar()
{
  ofstream arq;
  ifstream arqAux;
  string line;

  remove("arquivoAuxiliar.txt");
  arq.open("arquivoAuxiliar.txt");
  arqAux.open("segundoArquivoAuxiliar.txt");
  if(!arqAux.is_open())
  {
    cout << "Erro na abertura do arquivo: segundoArquivoAuxiliar.txt!!!" << endl;
    apagarArquivos();
  }

  while(arqAux)
  {
    getline(arqAux, line);
    arq << line;
    arq << "\n";
  }
  
  arq.close();
  arqAux.close();
}

void Labirinto::atualizarSegundoArquivoAuxiliar()
{
  ofstream arqAux;
  
  arqAux.open("segundoArquivoAuxiliar.txt", ios::app);

  for(int i = 0; i < this->tamLabirinto; i++)
  {
    for(int j = 0; j < this->tamLabirinto; j++)
    {
      arqAux << this->labirinto[i][j];
      arqAux << " ";
    }
    arqAux << "\n";
  }
  arqAux << "\n";
  arqAux.close();
}

void Labirinto::obtendoPosicaoInicial()
{
  int linha, coluna, erro;
  
  do
  {
    erro = 0;
    cout << "Linha: ";
    cin >> linha;
    cout << "Coluna: ";
    cin >> coluna;
    
    if(cin.fail() || coluna < 0 || coluna >= this->tamLabirinto || linha < 0 || linha >= this->tamLabirinto || this->labirinto[linha][coluna] == "#")
    {
      erro = 1;
      cin.clear();
      cin.ignore(80, '\n');
    }
    if(erro == 1)
    {
      cout << endl << "Digite uma opção valida!" << endl << endl;
    }
  }while(erro == 1);

  this->linha = linha;
  this->coluna = coluna;
  verificandoParedes(linha, coluna);
}

void Labirinto::obtendoPosicaoAleatoria()
{
  int linha, coluna;
  
  do
  {
    linha = rand()%this->tamLabirinto;
    coluna = rand()%this->tamLabirinto;
    
    if(this->labirinto[linha][coluna] == "#")
    {
      linha = -1;
    }
    else
    {
      this->linha = linha;
      this->coluna = coluna;
      verificandoParedes(linha, coluna);
    }
  }while(linha == -1);
}

void Labirinto::verificandoParedes(int linha, int coluna)
{
  if(!(linha+1 >= this->tamLabirinto || coluna+1 >= this->tamLabirinto || linha-1 < 0 || coluna-1 < 0))
  {
    if(this->labirinto[linha+1][coluna] == "#"  && this->labirinto[linha+1][coluna-1] == "#"  && this->labirinto[linha][coluna-1] == "#"  && this->labirinto[linha-1][coluna-1] == "#"  && this->labirinto[linha-1][coluna] == "#"  && this->labirinto[linha-1][coluna+1] == "#"  && this->labirinto[linha][coluna+1] == "#"  && this->labirinto[linha+1][coluna+1] == "#")
    {
      cout << "O garoto não conseguiu sair pois estava cercado nas 8 posições por paredes!!!" << endl;
      apagarArquivos();
    }
  }
}

void Labirinto::pegandoValoresLabirinto()
{
  ifstream arq;
  int itensCaminho, aux = 0;
  
  do
  {
    remove("segundoArquivoAuxiliar.txt");
    itensCaminho = itensPegos;
    
    arq.open("arquivoAuxiliar.txt");
    if(!arq.is_open())
    {
      cout << "Erro na abertura do arquivo: arquivoAuxliar.txt!!!" << endl;
      apagarArquivos();
    }
    
    for(int k = 0; k < this->numLabirinto; k++)
    {
      for(int i = 0; i < this->tamLabirinto; i++)
      {
        for(int j = 0; j < this->tamLabirinto; j++)
        {
          arq >> this->labirinto[i][j];
        }
      }
      if(aux == 0)
      {
        obtendoPosicaoInicial();
        aux++;
      }
      else
      {
        obtendoPosicaoAleatoria();
      }
      caminhandoLabirinto();
      atualizarSegundoArquivoAuxiliar();
    }
    
    arq.close();
    atualizarArquivoAuxiliar();
  }while(itensCaminho+this->itensPegos == this->itensPegos);
}

void Labirinto::caminhandoLabirinto()
{
  int linha, coluna, aux;

  while(1)
  {
    linha = (rand()%3)-1;
    coluna = (rand()%3)-1;

    if(this->linha+linha >= 0 && this->coluna+coluna >= 0 && this->linha+linha < tamLabirinto && this->coluna+coluna < tamLabirinto)
    {
      if(this->labirinto[this->linha+linha][this->coluna+coluna] != "#" && (linha != 0 || coluna != 0))
      {
        this->passos++;
        this->linha = this->linha+linha;
        this->coluna = this->coluna+coluna;
        if(this->labirinto[this->linha][this->coluna] == "*")
        {
          this->vidas--;
          this->perigos++;
          verificandoVida();
        }
        else
        {
          if(this->labirinto[this->linha][this->coluna] != "0")
          {
            this->itensPegos++;
            this->sacola++;
            verificandoSacola();
            
            istringstream(this->labirinto[this->linha][this->coluna]) >> aux;
            aux--;
            this->labirinto[this->linha][this->coluna] = to_string(aux);
          }
        }
      }
    }
    else
    {
      this->passos++;
      return;
    }
  }
}

void Labirinto::verificandoVida()
{
  if(getVidas() == 0)
  {
    cout << "Fim de jogo!!!" << endl;
    cout << "O garoto infelizmente perdeu todas suas vidas!!!" << endl << endl;
    cout << "Casas percorridas ao todo: " << getPassos() << endl;
  cout << "Soma de itens coletados pelo caminho: " << getItensPegos() << endl;
  cout << "Perigos enfrentados durante o caminho: " << getPerigos() << endl;
    apagarArquivos();
  }
}

void Labirinto::verificandoSacola()
{
  if(getSacola() == 4)
  {
    if(getVidas() == 10)
    {
      setSacola(0);
    }
    else
    {
      setSacola(0);
      this->vidas++;
    }
  }
}