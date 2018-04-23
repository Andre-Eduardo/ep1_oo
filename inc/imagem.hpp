#ifndef IMAGEM_HPP
#define IMAGEM_HPP
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
using namespace std;


class Imagem {
  //Atributos
protected:
  string caminho;
  int altura, largura, escala,inicioImagem;
  string tipo;
  fstream IMG;



  // Metodos
public:
    Imagem(); // construtor
    ~Imagem();// Destrutor

  //Get / Set
  void setAltura(int altura);
  int getAltura();

  void setLargura(int largura);
  int getLargura();

  void  setEscala(int tons);
  int getEscala();


  void setTipo( string tipo);
  string getTipo();

  void setInicioImagem(int inicioImagem);
  int getInicioImagem();

  void setCaminho(string caminho);
  string getCaminho();

  void abrirImagem();
  int converteParaInt(string generica);
  char* alocaImagem();

};




#endif
