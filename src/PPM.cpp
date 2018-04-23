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

  IMG.open(caminho.c_str());


 IMG >> tipo;
  IMG >> inicioCifra>> tamanhoMensagem >> chave;
  IMG >> altura >> largura;
  IMG >> escala;
  cout << inicioCifra.c_str() << " " << tamanhoMensagem << " " << chave.c_str() << endl;
  cout << altura << " " <<largura << endl;
  cout << escala <<endl;
  cout << converteParaInt(estrairChar()) <<endl;
i  = converteParaInt(estrairChar());
  vetorPPM = alocaImagem();
  pegaMensagem();

  }
PPM::~PPM(){

}

//gbTgbT
//get / set
void PPM::setTamanhoMensagem(int tamanhoMensagem){
  this->tamanhoMensagem = tamanhoMensagem;
}
int PPM::getTamanhoMensagem(){
  return tamanhoMensagem;
}

void PPM::setInicioCifra(string inicioCifra){
  this->inicioCifra = inicioCifra;
}
string PPM::getInicioCifra(){
  return inicioCifra;
}


void PPM::setChave(string chave){
  this->chave = chave;
}
string PPM::getChave(){
  return chave;
}

string PPM::estrairChar(){
  string inCifra;
  for (int i = 0; i < inicioCifra.size(); i++) {
    if (inicioCifra[i] != '#') {
    inCifra+=inicioCifra[i];

  }

}
return inCifra;
}
void PPM::pegaMensagem(){
  int vetorMensagem[tamanhoMensagem*3];
  int vtMen[tamanhoMensagem*3];
  int mensagem[tamanhoMensagem];
  char  codigo[tamanhoMensagem];
  for (int a = 0; a < tamanhoMensagem*3-1; a++) {
    if (vetorPPM[i+a+1] < 0){
      vetorPPM[i+a+1]= vetorPPM[i+a+1]*(-1);
    }
    vetorMensagem[a] = vetorPPM[i+a+1]%10;


  }
  for (int aux = 0; aux < tamanhoMensagem*3-3; aux+=3) {
      vtMen[aux] = vetorMensagem[aux]+ vetorMensagem[aux+1] +vetorMensagem[aux+2];

  }
  for (int aux = 0; aux < tamanhoMensagem-1; aux++) {
    mensagem[aux] =vtMen[aux*3];
    cout << mensagem[aux]<<" ";
  }
  cout <<""<<endl;
  char alfabeto[27] ={' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
  for (int aux = 0; aux < tamanhoMensagem-1; aux++) {
    codigo[aux]= alfabeto[mensagem[aux]];
  }
cout << codigo << "codigo" << endl;
cout << chave << "cahve" << endl;
string encoded = encoder(chave);
cout << "Deciphered Text : " << decipheredIt(codigo,encoded) << endl;
}

// CPP program for decoding the string
// which generate using classical cipher




// Original Set of letters
string plaintext = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Function generates the encoded text
string PPM::encoder(string key)
{
    string encoded = "";
    bool arr[26] = {0};

    // This loop inserts the keyword
    // at the start of the encoded string
    for (int i=0; i<key.size(); i++)
    {
        if(key[i] >= 'A' && key[i] <= 'Z')
        {
            // To check whether the character is inserted
            // earlier in the encoded string or not
            if (arr[key[i]-65] == 0)
            {
                encoded += key[i];
                arr[key[i]-65] = 1;
            }
        }
        else if (key[i] >= 'a' && key[i] <= 'z')
        {
            if (arr[key[i]-97] == 0)
            {
                encoded += key[i] - 32;
                arr[key[i]-97] = 1;
            }
        }
    }

    // This loop inserts the remaining
    // characters in the encoded string.
    for (int i=0; i<26; i++)
    {
        if(arr[i] == 0)
        {
            arr[i]=1;
            encoded += char(i + 65);
        }
    }
    return encoded;
}

// This function will decode the message
string PPM::decipheredIt(string msg, string encoded)
{
    // Hold the position of every character (A-Z)
    // from encoded string
    map <char,int> enc;
    for(int i=0; i<encoded.size(); i++)
    {
        enc[encoded[i]]=i;
    }

    string decipher="";

    // This loop deciphered the message.
    // Spaces, special characters and numbers remain same.
    for (int i=0; i<msg.size(); i++)
    {
        if (msg[i] >='a' && msg[i] <='z')
        {
            int pos = enc[msg[i]-32];
            decipher += plaintext[pos];
        }
        else if(msg[i] >='A' && msg[i] <='Z')
        {
            int pos = enc[msg[i]];
            decipher += plaintext[pos];
        }
        else
        {
            decipher += msg[i];
        }
    }
    return decipher;
}
