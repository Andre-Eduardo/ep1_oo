#include <iostream>
#include "imagem.hpp"
#include <string>
 #include <cstdlib>

Imagem::Imagem(){

}
Imagem::~Imagem(){

 //delete vetorImagem; //  libera espaço na memoria que alocava a imagem
}
void Imagem::setAltura(int altura){
  this->altura = altura;
}
int Imagem::getAltura(){
  return altura;
}

void Imagem::setLargura(int largura){
  this->largura = largura;
}


int Imagem::getLargura(){
  return largura;
}

void  Imagem::setEscala(int escala){
  this->escala = escala;
}
int Imagem::getEscala(){
  return escala;
}

void Imagem::setInicioImagem_int(){
  this->inicioImagem_int = inicioImagem_int;
}
int Imagem::getInicioImagem_int(int inicioImagem_int){
  return inicioImagem_int;
}

void Imagem::setDimensaoImagem(int dimensaoImagem){
  this->dimensaoImagem = dimensaoImagem;
}
int Imagem::getDimensaoImagem(){
  return dimensaoImagem;
}

void Imagem::setTipo(string tipo){
  this->tipo = tipo;
}

void Imagem::SetPixel(char pixel){
  this->pixel = pixel;
}

char Imagem::getPixel(){
  return pixel;
}

void Imagem::setInicioCifra(string inicioCifra){
  this->inicioCifra = inicioCifra;
}
string Imagem::getInicioCifra(){
  return inicioCifra;
}


string Imagem::getTipo(){
  return tipo;
}

void Imagem::setCaminho(string caminho){
  this->caminho = caminho;
}
string Imagem::getCaminho(){
  return caminho;
}

void Imagem::setMensagemcriptografada(string mensagemCriptografada){

  this->mensagemCriptografada = mensagemCriptografada;
}
string Imagem::getMensagemCriptografada(){

  return mensagemCriptografada;
}

//  ==== Metodos ====

void Imagem::abrirImagem(){

  //instruçoes
  cout << "Digite o caminho da imagem:  ";
  cin>>caminho;
  IMG.open(caminho.c_str());
  while ( !(IMG.is_open())) {
    cout << "Erro: imagem  nao encontrada, digite novamente:";
    cin >> caminho;
    IMG.open(caminho.c_str());
    setCaminho(caminho);
  }
  IMG >> tipo;
  IMG.close(); // fecha a imagem.

}

int Imagem::converteParaInt(string generica){
// variavel local
  int numero;
// instruçoes
  numero  = atoi(generica.c_str());
  return numero;
}

char* Imagem::alocaImagem(){
  // instruçoes
   dimensaoImagem = altura * largura *3;
  vetorImagem = new char[dimensaoImagem];
  for (int i = 0; i < dimensaoImagem; i++) {
    IMG.get(pixel);
    vetorImagem[i] = pixel;
  }
  return vetorImagem;
}

string Imagem::estrairChar(){
  string inCifra; // variavel local

  //instruçoes
  for (int i = 0; i < inicioCifra.size(); i++) {
    if (inicioCifra[i] != '#') {
    inCifra+=inicioCifra[i];
    }
  }
  return inCifra;
}
