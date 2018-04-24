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
    PGM pgm;
    PGM(imagem.getCaminho());

    }
    else if(imagem.getTipo() == "P6"){
      PPM ppm;
      PPM(imagem.getCaminho());

    }
}
