#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include "funcoes.hpp"

void Gauss(int Nsl){
     double gab[Nsl][Nsl+1], gx[Nsl], gabe[Nsl][Nsl+1]; // Matriz A + vector B e o vetor solução, vetor para subsitruição de linhas, matriz pra calcular o erro respectivamente

      //Coleta de informações da matriz A
      for(int i = 0; i <= Nsl - 1; i++){
         std:: cout << "Escreva a " << i+1 << "ª linha da matriz A (Ax = B):\t";
         for(int j = 0; j <= Nsl - 1 ; j++){
            std::cin >> gab[i][j];
            gabe[i][j] = gab[i][j];
         }   
               
         }
      clearScreen();
      //Coleta de informações da matriz B
      std:: cout << "Escreva a matriz B (Ax = B):\t";
      for(int i = 0; i <= Nsl - 1 ; i++){
         std::cin >> gab[i][Nsl];
         gabe[i][Nsl] = gab[i][Nsl];
      }
      clearScreen();
      
          // Matriz printer
          for (int i = 0; i <= Nsl - 1; i++) {
             std::cout << std::fixed << std::setprecision(4);
             std::cout << "| ";
             for (int j = 0; j <= Nsl - 1; j++) {
               std::cout << std::setw(8) << gab[i][j] << " "; // Espaçamento uniforme
            }
            std::cout << "| \t|x" << i << "| \t|" << std::setw(8) << gab[i][Nsl] << " |" << std::endl;
         }

      
         for (int i = 0; i < Nsl; i++) {
              int ig = i; //Indice da linha que contem o maior valor da primeira coluna
              double ag = std::abs(gab[i][i]); // Maior Valor da Coluna atual

              // Encontrar o maior pivô na coluna atual
              for (int k = i + 1; k < Nsl; k++) {
                  if (std::abs(gab[k][i]) > ag) {
                      ag = std::abs(gab[k][i]);
                      ig = k;
                  }
              }
            // Trocar linhas se necessário
              if (ig != i) {
                  for (int j = 0; j <= Nsl; j++) {
                      std::swap(gab[i][j], gab[ig][j]);
                  }
              }
         }
         // Eliminação
         for(int i = 0; i< Nsl;i++){
            double factor;   
            for(int k = i+1; k < Nsl;k++){
               factor = gab[k][i]/gab[i][i];
               for(int j = 0; j < Nsl+1; j++)  
                  gab[k][j] -= gab[i][j]*factor;
               
            }
         }
     
      //Matriz Printer
      for (int i = 0; i <= Nsl - 1; i++) {
          
          std::cout << std::endl << "\n| ";
          for (int j = 0; j <= Nsl - 1; j++) {
              std::cout << std::setw(8) << gab[i][j] << " "; // Espaçamento uniforme
          }
          std::cout << "| \t|x" << i << "| \t|" << std::setw(8) << gab[i][Nsl] << " |" << std::endl;
      }

      
      double detg = 1; //Determinante da matriz, para conferir se a matriz tem um, infinitas ou nenhuma solução real
      for(int i = 0; i <= Nsl -1; i++)
         detg = detg * gab[i][i];
      if(detg == 0) // Caso o determinante seja 0, ou o sistema tem infinitas soluções, ou o sistema não tem solução real
      std::cout <<"\n\nEsse sistema não tem solução única ou não tem solução real";
         
         //Caso a matriz tenha solução única(det!=0), o programa continua o cálculo
      else {
         //Substituição retroativa
         double xacumulado; // Soma parcial das colunas
         
         //Zerador do vetor solução pra
         for(int i=0; i < Nsl;i++)
            gx[i]=0;
         
         for(int i = Nsl-1; i>=0 ;i--){
            xacumulado = 0;
            for(int j = 0; j < Nsl; j++)
               if(j != i)
                  xacumulado +=  gx[j]*gab[i][j];
               
            gx[i] = (gab[i][Nsl]-xacumulado)/gab[i][i];
         }
         //Printer da solução
         std::cout << std::fixed << std::setprecision(6);
         std::cout<< std::endl <<"\nVetor solução X = [ ";
         for(int i = 0; i <Nsl;i++)
            std::cout << gx[i] << ' ';
         std::cout<< "]^t"<< std::endl;

         //Calculo do erro 
         double eg[Nsl];
         for(int i = 0; i< Nsl;i++){
            xacumulado = 0;
            for(int j = 0; j <= Nsl-1; j++)
               xacumulado +=  gx[j]*gabe[i][j];
            eg[i]= gabe[i][Nsl] - xacumulado;
         }
         //Printer do erro
         std::cout<< std::endl <<"r (erro residual) = [ ";
         for(int i = 0; i <Nsl;i++)
            std::cout << eg[i] << ' ';
         std::cout<< "]^t"<< std::endl;
      }
   }
