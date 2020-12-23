// https://www.paulotrentin.com.br/programacao/dicas/lendo-uma-string-com-arduino-via-serial/



#include <Servo.h>

Servo coxa;
Servo canela;

String str_serial;
String st_str_serial[0] = 'p';

void le_serial(){
  str_serial = "";
  while(Serial.available() > 0){
      char  char_receb = Serial.read();

      if (char_receb != '\n'){
        str_serial.concat(char_receb);      
      }
      delay(10);
    }
  }

void andar(char direcao){
  int tmp = 1000;
  int esq = 50;
  int dir = 120;
  int reto = 90;
  int canela_esq = 00;
  int canela_dir = 50;
  int canela_reto = 90;
  
  switch(direcao){

  case 'p':
    Serial.println("parado");
    //perana reta
    coxa.write(reto);
    canela.write(reto);
    delay(tmp);
    break;
  
  case 'f':
    Serial.print("frente");
   //abre perna
    canela.write(canela_esq);
    delay(tmp);
    coxa.write(esq);
    delay(tmp);
    canela.write(canela_reto);
    delay(tmp);
    coxa.write(reto);
    delay(tmp);
    coxa.write(dir);
    delay(tmp);
    canela.write(canela_esq);
    delay(tmp);
    break;   
  }
}

void move_pernas(){
//  int v_coxa;
//  int v_canela;
  
//  Serial.print("movendo ");
//  Serial.println(str_serial);
//  v_coxa = (str_serial.substring(0, 3)).toInt();
//  v_canela = (str_serial.substring(4, 7)).toInt();
   
//  Serial.println(v_coxa);
//  Serial.println(v_canela);
  
//  coxa.write(v_coxa);
//  canela.write(v_canela);
  
  }

void setup() {
  Serial.begin(115200); 
  coxa.attach(3); 
  canela.attach(4);
}

void loop() {  
  if (Serial.available() > 0) {
    le_serial();
    char dir = str_serial[0]; 
    andar(dir);
  }
   
}
