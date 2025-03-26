#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <time.h>

using namespace std;

#define LIN 16
#define COL 41

void opcaoUm (int **mat) {
	int fileira;
	int poltrona;
	bool reserva;
	
	cout << "============================================" << endl <<
			"            RESERVA DE POLTRONA" << endl <<
       	    "============================================" << endl;
	
	do {
		do {
			cout << " Digite a fileira desejada (1 a 15): ";
			cin >> fileira;
			
			if (fileira < 1 || fileira > 15) {
				cout << " Fileira invalida. Digite novamente!" << endl;
			}
		} while (fileira < 1 || fileira > 15);
		
		do {
			cout << " Digite a poltrona desejada (1 a 40): ";
			cin >> poltrona;
			
			if (poltrona < 1 || poltrona > 40) {
				cout << " Poltrona invalida. Digite novamente!" << endl;
			}
		} while (poltrona < 1 || poltrona > 40);
		
		for(int i = 1; i < LIN; ++i) {
			for(int j = 1; j < COL; ++j) {
				if (i == fileira && j == poltrona) {
					if (mat[i][j] == 0) {
						cout << "--------------------------------------------" << endl <<
						   	    " Poltrona reservada!" << endl <<
						   	    " Pressione qualquer tecla para continuar..." << endl <<
						   	    "--------------------------------------------" << endl;
					    _getch();
					    system("cls");
						mat[i][j] = 1;
						reserva = true;
					} else {
						cout << " Poltrona ocupada! Selecione outra." << endl;
						reserva = false;
					}
				}
			}
		}
	} while(reserva != true);
}

void opcaoDois (int **mat) {
	cout << "=====================================================================================" << endl <<
			"                                  MAPA DE OCUPACAO" << endl <<
       	    "=====================================================================================" << endl;

	for(int i = 1; i < LIN; ++i) {
		if (i < 10){
			cout << i << " " << setw(3);
		} else {
			cout << i << " " << setw(2);
		}
		
		for(int j = 1; j < COL; ++j) {	
			if (mat[i][j] == 1) {
				cout << "|#";
			} else {
				cout << "|.";
			}
		}
		cout << "|" << endl;
	}
	
	cout << "-------------------------------------------------------------------------------------" << endl <<
			" Legenda:" << endl <<
			" '.' = Lugares vagos" << endl <<
	   	    " '#' = Lugares ocupados" << endl <<
	   	    "-------------------------------------------------------------------------------------" << endl <<
			" Pressione qualquer tecla para continuar...";
	_getch();
	system("cls");
}

void opcaoTres (int **mat) {
	int total = 0;
	int contador = 0;
	
	for(int i = 1; i < LIN; ++i) {
		for(int j = 1; j < COL; ++j) {
			if (mat[i][j] == 1) {
				contador++;
				
				if (i <= 5) {
					total += 50;
				}
				
				else if (i <= 10) {
					total += 30;
				}
				
				else if (i <= 15) {
					total += 15;
				}
			}
		}
	}
	
	system("cls");
	cout << "============================================" << endl <<
			"             TOTAL DE RESERVAS" << endl <<
 	    	"============================================" << endl <<
		    " Quantidade de lugares ocupados: " << contador << endl <<
	   	    " Valor da Bilheteria: R$ " << total << ",00" << endl <<
	   	    "--------------------------------------------" << endl <<
		    " Pressione qualquer tecla para continuar..." << endl;
    _getch();
    system("cls");
}

int main(int argc, char** argv)
{
	int seletor;
	int **mat;
	
	mat = new int*[LIN];
	
	for(int i = 1; i < LIN; ++i)
	{
		mat[i] = new int[COL];
	}
	
	for(int i = 1; i < LIN; ++i)
	{
		for(int j = 1; j < COL; ++j)
		{
			mat[i][j] = 0;
		}
	}
	
	int r;
	
	srand(time(0));
	
	for(int i = 0; i < 40; ++i) {
		r = rand();
	   
		for(int i = 1; i < LIN; ++i) {
			for(int j = 1; j < COL; ++j) {
				if (i == (r%10) && j == (r%100)) {
					if (mat[i][j] == 0) {
						mat[i][j] = 1;
					}
				}
			}
		}
	}
	
    cout << "=========================================" << endl <<
			"           BEM-VINDO AO TEATRO" << endl <<
       	    "=========================================" << endl <<
       	    "     Um lugar onde a magia acontece!" << endl <<
       	    "-----------------------------------------" << endl <<
   	   	    " Pressione qualquer tecla para entrar..." << endl;
    _getch();
    system("cls");
	
	do {
		cout << "========================================" << endl <<
				"             MENU PRINCIPAL" << endl <<
       	    	"========================================" << endl <<
		    	" Informe uma das seguintes opcoes:" << endl <<
		    	"----------------------------------------" << endl <<
				" 0. Finalizar" << endl <<
				" 1. Reservar poltrona" << endl <<
				" 2. Mapa de ocupacao" << endl <<
				" 3. Faturamento" << endl <<
				"----------------------------------------" << endl <<
				" Opcao desejada: ";

        cin  >> seletor;
        
        if (seletor > 3 || seletor < 0) {
        	system("cls");
			cout << "Opcao incorreta! Tente novamente." << endl;
		} else {
			switch(seletor) {
				case 1: 
					system("cls");
					opcaoUm(mat);
					break;
				case 2:
					system("cls");
					opcaoDois(mat);
					break;
				case 3:
					opcaoTres(mat);
					break;
				default:
					system("cls");
					cout << "----------------------------------------" << endl <<
							" Obrigado por visitar nosso Teatro!" << endl <<
	   	   	                "----------------------------------------" << endl;
					 
					 for(int i = 0; i < LIN; ++i) {
						delete[] mat[i];
					}
					
					delete[] mat;
			}
		}
	} while (seletor != 0);
	
	return 0;
}