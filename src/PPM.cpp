#include <iostream>
#include "PPM.hpp"
#include <string>
#include <fstream>
#include <unistd.h>
#include<bits/stdc++.h>
using namespace std;

PPM::PPM(){

}
PPM::PPM(string caminho){

  IMG.open(caminho.c_str()); // abre a imagem
  // leitura do cabeçalho da imagem.
  IMG >> tipo;
  IMG >> inicioCifra>> tamanhoMensagem >> chave;
  IMG >> altura >> largura;
  IMG >> escala;
  inicioImagem_int = converteParaInt(estrairChar());
  vetorPPM = alocaImagem();
  pegaMensagem();
  cout << "Chave: " << chave << endl;
  cout << "Mensagem: " << decodificador(mensagemCriptografada) << endl;
  }
PPM::~PPM(){

}
  // ==== Get / Set ====
void PPM::setTamanhoMensagem(int tamanhoMensagem){
  this->tamanhoMensagem = tamanhoMensagem;
}
int PPM::getTamanhoMensagem(){
  return tamanhoMensagem;
}

void PPM::setVetorPPM(char* vetorPPM){
  this->vetorPPM = vetorPPM;
}

char* PPM::getVetorPPM(){
  return vetorPPM;
}

void PPM::setChave(string chave){
  this->chave = chave;
}
string PPM::getChave(){
  return chave;
}
//  ==== Metodos ====

void PPM::pegaMensagem(){
// variaveis locais
  int vetorMensagem[tamanhoMensagem*3];
  int vtMen[tamanhoMensagem*3];
  int mensagem[tamanhoMensagem];
  char alfabeto[27] ={' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
// instruçoes

  for (int a = 0; a < tamanhoMensagem*3-1; a++) {
    if (vetorPPM[inicioImagem_int+a+1] < 0){
      vetorPPM[inicioImagem_int+a+1]= vetorPPM[inicioImagem_int+a+1]*(-1);
    }
    vetorMensagem[a] = vetorPPM[inicioImagem_int+a+1]%10; // pega a posiçao menos significativa do numero

  }
  for (int aux = 0; aux <tamanhoMensagem*3-3; aux+=3) {
    vtMen[aux] = vetorMensagem[aux]+ vetorMensagem[aux+1] +vetorMensagem[aux+2];
  }

  for (int aux = 0; aux < tamanhoMensagem-1; aux++) {
    mensagem[aux] =vtMen[aux*3];
  }


  for (int aux = 0; aux < tamanhoMensagem-1; aux++) {
    mensagemCriptografada += alfabeto[mensagem[aux]];
  }

}

string PPM::decodificador(string msg)
{
  string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  string decodificador = "";
  bool posicoes[26] = {0};


  for (int i=0; i<chave.size(); i++)
  {
      if(chave[i] >= 'A' && chave[i] <= 'Z')
      {

          if (posicoes[chave[i]-65] == 0)
          {
              decodificador += chave[i];
              posicoes[chave[i]-65] = 1;
          }
      }
      else if (chave[i] >= 'a' && chave[i] <= 'z')
      {
          if (posicoes[chave[i]-97] == 0)
          {
              decodificador += chave[i] - 32;
              posicoes[chave[i]-97] = 1;
          }
      }
  }

  for (int i=0; i<26; i++)
  {
      if(posicoes[i] == 0)
      {
          posicoes[i]=1;
          decodificador += char(i + 65);
      }
  }

    map <char,int> enc;
    for(int i=0; i<decodificador.size(); i++)
    {
        enc[decodificador[i]]=i;
    }

    string decodificado="";


    for (int i=0; i<msg.size(); i++)
    {
        if (msg[i] >='a' && msg[i] <='z')
        {
            int posicoes = enc[msg[i]-32];
            decodificado += alfabeto[posicoes];
        }
        else if(msg[i] >='A' && msg[i] <='Z')
        {
            int posicoes = enc[msg[i]];
            decodificado += alfabeto[posicoes];
        }
        else
        {
            decodificado += msg[i];
        }
    }
    return decodificado;
}
