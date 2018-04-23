#include <iostream>
#include "imagem.hpp"
#include <string>
 #include <cstdlib>

Imagem::Imagem(){

}
Imagem::~Imagem(){

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


void Imagem::setInicioImagem(int inicioImagem){
  this->inicioImagem = inicioImagem;
}

int Imagem::getInicioImagem(){
  return inicioImagem;
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

void Imagem::setTipo(string tipo){
  this->tipo = tipo;
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

void Imagem::abrirImagem(){
  cout << "Digite o caminho da imagem:"<<endl;
  cin>>caminho;
  setCaminho(caminho);
  IMG.open(caminho.c_str());
  while ( !(IMG.is_open())) {
    cout << "Erro: imagem  nao encontrada, digite novamente:";
    cin >> caminho;
    IMG.open(caminho.c_str());
    setCaminho(caminho);
  }
  IMG >> tipo;
  setTipo(tipo);
  IMG.close();

}
int Imagem::converteParaInt(string generica){
int numero;
numero  = atoi(generica.c_str());
return numero;
}

char* Imagem::alocaImagem(){

  char pixel=0;
  int dimensaoImagem = altura * largura *3;
  char * vetorImagem = new char[dimensaoImagem];
  for (int i = 0; i < dimensaoImagem; i++) {
    IMG.get(pixel);
  vetorImagem[i] = pixel;
}
return vetorImagem;
}
