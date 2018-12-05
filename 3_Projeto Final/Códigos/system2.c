#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

int main(){

	wiringPiSetup(); //inicia wiringpi
	pinMode(25, OUTPUT); //define pino 1 como saida
	pinMode(16, OUTPUT);
	pinMode(20, INPUT); //define pino 7 como entrada
	pullUpDnControl(20, PUD_UP); //configura resistor pull-up no pino7
	
	int estadoLED = 0;
	
	while(1){
		
		if(digitalRead(20) == LOW) //detecta se a chave foi pressionada
		{
			estadoLED =! estadoLED; //inverte o estado do LED
			digitalWrite(16, estadoLED); // escreve no LED conforme o estado
			if(estadoLED == 1){
				system("python3 teste_Teste_2py");
				
					}; 
	
			delay(20);
			while(digitalRead(20) == LOW); //aguarda enquanto chave está apertada
			delay(20);
		}
		
	
	}



		return 0;
}
