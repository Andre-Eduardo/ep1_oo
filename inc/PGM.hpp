#ifndef PHM_hpp
#define PHM_hpp
#include "imagem.hpp"
using namespace std;
#include <string>


class PGM : public Imagem{

  int numCifra;
  int tamanhoMensagem;
  string inicioCifra;
  char *vetorPGM;
  char bitExtraido;
	char byteExtraido;



string decifradorPGM();
public:
    PGM(); // construtor
    PGM(string caminho);
    ~PGM();// Destrutor

  // ==== Get / Set ====
void setTamanhoMensagem(int tamanhoMensagem);
int  getTamanhoMensagem();

void setInicioCifra(string inicioCifra);
string getInicioCifra();

void setNumCifra( int numCifra);
int getNumCifra();
//  ==== Metodos ====
string estrairChar();
char* alocaImagem(); // Sobrescrita do metodo herdado da classe imagem.

};
#endif
