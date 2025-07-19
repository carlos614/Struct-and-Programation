#include <iostream>

using namespace std; 

	 main(){
		
		int n1, n2, resultado;
		char operador; 
		
		cout <<"Digite o primeiro numero: ";
		cin >> n1;
		cout <<"Digite o segundo numero: ";
		cin >> n2;
		cout<<"Digite a operação: (+, -, *, /)";
		cin >> operador;
		
		if (operador == '+'){
			resultado = n1 + n2;
			
		}
		else if (operador == '-'){
			resultado = n1 - n2;
			
		}
			else if (operador == '*'){
			resultado = n1 * n2;
			
		}
			else if (operador == '/'){
			resultado = n1 / n2;
			
		}
		cout <<"Resultado: " <<resultado;
	}
