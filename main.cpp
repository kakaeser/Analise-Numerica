#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "funcoes.hpp"
#include "sistemasl.hpp"


int main(){
   int a = 0;
   std::cout << "O que você quer calcular?" << std:: endl << "1 - Sistemas Lineares" << std:: endl << "2 - Interpolação Polinomial" << std:: endl;
   std::cout << "3 - Ajustes de curvas" << std:: endl << "4 - Integração numérica" << std:: endl << "5 - Raizes de polinômio" << std::endl;
   do {
      std::cout << std::endl << "Escreva o numero de 1 até 5" << std::endl;
      std::cin >> a;
   } while(a < 1 || a > 5);
  
   clearScreen();
   if(a == 1){ // Sistemas Lineares com matrizes

      int sl = 0; // Selecionador de método 
      int Nsl; // Quantidade de x's
      
      std::cout << "Quantas variaveis tem o seu sistema?" << std::endl;
      std::cin >> Nsl; // Definir o tamanho da matriz, vetor solução e etc

      clearScreen();
      
      std::cout << "Qual método será utilizado?\n" << "1 - Eliminação de Gauss\n" << "2 - Decomposição LU\n" << "3 - Choelesky (Recomendado apenas para matrizes positivas e simétricas)\n";

      do {
      std::cout << std::endl << "Escreva o numero de 1 até 3" << std::endl;
      std::cin >> sl;
         
      } while(sl < 1 || sl > 3); //Definir qual método será utilizado 

      clearScreen();
      
      if(sl == 1){ // Gauss
         Gauss(Nsl);
      
      } else if(sl == 2){ // LU
         
      } else if(sl == 3){ // Choelesky
         
      }

      
   } else if (a == 2){ // Interpolação polinomial
      std::cout << "Não temos ainda";
   } else if (a == 3){ // Ajuste de Curva
      std::cout << "Não temos ainda";
   } else if (a == 4){ // Integração numérica
      std::cout << "Não temos ainda";
   } else if (a == 5){ // Raízes de polinômio
      std::cout << "Não temos ainda";
   }




   
}
