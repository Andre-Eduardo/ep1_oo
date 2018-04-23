#include <iostream>
#include "PGM.hpp"
#include <string>
using namespace std;

PGM::PGM() {
  //construtor
}
PGM::PGM(string caminho){
  IMG.open(caminho.c_str());
  IMG >> tipo;
  IMG >> inicioCifra>> tamanhoMensagem >> numCifra ;
  IMG >> altura >> largura;
  IMG >> escala;
  cout << inicioCifra.c_str() << " " << tamanhoMensagem << " " <<numCifra << endl;
  cout << altura << " " <<largura << endl;
  cout << escala <<endl;
  int num = converteParaInt(estrairChar());
  cout << converteParaInt(estrairChar()) <<endl;
  char pixel;
  int dimensaoImagem = altura * largura;
  char * vetorImagem = new char[dimensaoImagem];
  for (int i = 0; i < dimensaoImagem; i++) {
  IMG.get(pixel);
  vetorImagem[i] = pixel;
}
int contador=1;
	bitExtraido=0;
	byteExtraido=0;

do
	{
		bitExtraido= vetorImagem[(num+1)+contador] & 0x01;

		if(contador%8!=0)
		{
			byteExtraido = (byteExtraido<<1) | bitExtraido;
		}


		else
		{
			byteExtraido = byteExtraido | bitExtraido;
			cout<<byteExtraido;
			byteExtraido=0;
		}

		contador++;
	}while(contador < tamanhoMensagem);
cout << " " << '\n';

  }

PGM::~PGM(){

}

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
string PGM::estrairChar(){
  string inCifra;
  for (int i = 0; i < inicioCifra.size(); i++) {
    if (inicioCifra[i] != '#') {
    inCifra+=inicioCifra[i];

  }

}
return inCifra;
}
