#ifndef PPM_HPP
#define PPM_HPP
#include "imagem.hpp"
#include <unistd.h>
using namespace std;



class PPM : public Imagem{

  private:
    int tamanhoMensagem;
    string chave; // chave para descriptografar mensagem
    char*vetorPPM; //  aponta para onde a imagem esta armazenada


  public:
      PPM(); // construtor
      PPM(string caminho);
      ~PPM();// Destrutor
  //===== Get / Set =======

  void setTamanhoMensagem(int tamanhoMensagem);
  int  getTamanhoMensagem();

  void setVetorPPM(char* vetorPPM);
  char* getVetorPPM();

  void setChave(string chave);
  string getChave();
  //  ==== Metodos ====
  
  string decifradorPPM();
  void pegaMensagem(); // funcao que pega a mensagem escondida na imagem .ppm
  string decodificador(string msg);
  };
#endif
