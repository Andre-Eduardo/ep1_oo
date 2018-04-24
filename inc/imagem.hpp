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

  int altura;
  int largura;
  int escala;
  int dimensaoImagem;
  int inicioImagem_int; // gurda a posiçao de inicio da mensagem, apos a remoçao do caractere '#'
  string tipo;
  fstream IMG;
  string caminho;
  string mensagemCriptografada;
  string inicioCifra;// gurda posiçao de inicio da imagem antes de retirar caractere'#'
  char * vetorImagem;
  char pixel;

  // Metodos
public:
    Imagem(); // construtor
    ~Imagem();// Destrutor

  // ==== Get / Set ====
  void setAltura(int altura);
  int getAltura();

  void setLargura(int largura);
  int getLargura();

  void  setEscala(int tons);
  int getEscala();

  void  setDimensaoImagem(int dimensaoImagem);
  int getDimensaoImagem();

  void setInicioImagem_int();
  int getInicioImagem_int(int inicioImagem_int);

  void setMensagemcriptografada(string mensagemCriptografada);
  string getMensagemCriptografada();

  void setTipo( string tipo);
  string getTipo();

  void SetPixel(char pixel);
  char getPixel();

  void setInicioCifra(string inicioCifra);
  string getInicioCifra();

  void setCaminho(string caminho);
  string getCaminho();

  //  ==== Metodos ====

  string estrairChar(); // funcao que retira caractere '#'
  void abrirImagem(); // funçao que abre uma imagem
  int converteParaInt(string generica); // funcao que faz a conversao de uma string para o tipo inteiro
  char* alocaImagem(); // funçao que aloca dinamicamente a imagem;

};


#endif
