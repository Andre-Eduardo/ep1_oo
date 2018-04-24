#include <iostream>
#include "PGM.hpp"
#include <string>
using namespace std;

PGM::PGM() {
  //construtor
}
PGM::PGM(string caminho){
  IMG.open(caminho.c_str()); // abre imagem
    // leitura do cabeçalho da imagem.
  IMG >> tipo;
  IMG >> inicioCifra>> tamanhoMensagem >> numCifra ;
  IMG >> altura >> largura;
  IMG >> escala;
  cout << inicioCifra.c_str() << " " << tamanhoMensagem << " " <<numCifra << endl;
  cout << altura << " " <<largura << endl;
  cout << escala <<endl;
  inicioImagem_int = converteParaInt(estrairChar());

}

PGM::~PGM(){}
  // ==== Get / Set ====
void PGM::setTamanhoMensagem(int tamanhoMensagem){
  this->tamanhoMensagem = tamanhoMensagem;
}
int  PGM::getTamanhoMensagem(){
  return tamanhoMensagem;
}

void PGM::setInicioCifra(string inicioCifra){
    this->inicioCifra = inicioCifra;
}
string PGM::getInicioCifra(){
  return inicioCifra;
}

void PGM::setNumCifra( int numCifra){
  this->numCifra = numCifra;

}
int PGM::getNumCifra(){
  return numCifra;

}

//  ==== Metodos ====

string PGM::estrairChar(){
  string inCifra;
  for (int i = 0; i < inicioCifra.size(); i++) {
    if (inicioCifra[i] != '#') {
    inCifra+=inicioCifra[i];

  }

}
return inCifra;
}
char* PGM::alocaImagem(){
  //instruçoes
  dimensaoImagem = altura * largura;
  char * vetorImagem = new char[dimensaoImagem];
  for (int i = 0; i < dimensaoImagem; i++) {
  IMG.get(pixel);
  vetorImagem[i] = pixel;
}
return vetorImagem;
}
