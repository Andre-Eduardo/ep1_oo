#ifndef PPM_HPP
#define PPM_HPP
#include "imagem.hpp"
#include <unistd.h>
using namespace std;



class PPM : public Imagem{

private:
  int tamanhoMensagem,i;
  string chave;
  string inicioCifra;
  char*vetorPPM;


public:
    PPM(); // construtor
    PPM(string caminho);
    ~PPM();// Destrutor
string decifradorPPM();
//Get / Set

void setTamanhoMensagem(int tamanhoMensagem);
int  getTamanhoMensagem();

void setInicioCifra(string inicioCifra);
string getInicioCifra();

void setPixel( int r ,int g, int b );
struct Pixel getPixel();

void setChave(string chave);
string getChave();
string estrairChar();
void pegaMensagem();
string encoder(string key);
string decipheredIt(string msg, string encoded);
};
#endif
