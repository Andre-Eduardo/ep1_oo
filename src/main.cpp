#include<iostream>
#include <fstream>
#include "imagem.hpp"
#include "PPM.hpp"
#include "PGM.hpp"
using namespace std;
int main (){

    Imagem imagem;

    imagem.abrirImagem();
    PGM pgm;

  if ( imagem.getTipo()=="P5"){
    cout << imagem.getTipo() <<endl;
    PGM pgm;
    PGM(imagem.getCaminho());



    }
    else if(imagem.getTipo() == "P6"){
      cout << imagem.getTipo() <<endl;
      PPM ppm;
      PPM(imagem.getCaminho());
      

    }



    //ifstream leitura("exemplo.ppm");

    //leitura.getline(setTipo(), 2);




}
