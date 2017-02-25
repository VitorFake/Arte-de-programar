#include <LiquidCrystal.h>

//Inicia o lcd nas portas digitais do arduino
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  
  lcd.begin(16, 2);//Inicializa a interface lcd 16x2
  pinMode(13, OUTPUT);//Configura o pino 13 de saída
  
}

void loop() {
  lcd.clear();//Limpa o lcd
  lcd.print("Led ligado !");//Imprime no lcd
  digitalWrite(13, HIGH);//Envia para o pino 13 um sinal  
  delay(1000);//Dá um delay  de 1000 ms          
  lcd.setCursor(0, 1);//Seta o cursor do lcd
  lcd.clear();//Limpa o lcd
  lcd.print("Led desligado !");//Imprime na tela do lcd
  digitalWrite(13, LOW);//Envia para o pino 13 um sinal fechado    
  delay(1000);//Delay de 1000 ms               
}
