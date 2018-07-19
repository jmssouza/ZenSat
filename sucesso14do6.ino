
#include <Wire.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <avr/wdt.h>
#include "LoRa.h"
#include <avr/io.h>
#include <SPI.h>
#define RADIOPIN 5
char str_aux[35] = "";
char str_rp[33] = "";
char str_add[300] = "";
char str_lora[300] = "";
char str_env[300] = "";
int datacounter = 0;

int loracounter = 0;
int pkcounter = 0;
int packetSize = 0;
int vezes = 0;
int j = 0;
int k = 0;
int rec = 0;
int e = 0;
int f = 0;
char str_a[33] = "";
char str_b[33] = "";
char str_c[33] = "";
char str_d[33] = "";
char str_e[33] = "";
char str_f[33] = "";
char str_g[33] = "";
char str_h[33] = "";

//Interrupção a ser atendida para receber dados do I2C Master (rasp)
void receive_from_rasp(int howMany) {
  e = 0;
  Serial.println(f);
  while(Wire.available()){

  str_rp[e] = Wire.read();    // receive byte as an integer
 // Serial.println(str_rp);
  e = e+ 1;
  //Serial.println("Chegou da rasp pacote:");
  //Serial.println(e);
}
  f = f+1;
  if (f == 1){
  strcpy(str_a,str_rp);
  //Serial.println(str_a);
  }
  if (f == 2){
  strcpy(str_b,str_rp);
  //Serial.println(str_b);
  }
  if (f == 3){
  strcpy(str_c,str_rp);
  //Serial.println(str_c);
  }
  if (f == 4){
  strcpy(str_d,str_rp);
  //Serial.println(str_d);
  }
  if (f == 5){
  strcpy(str_e,str_rp);
  //Serial.println(str_e);
  }
  if (f == 6){
  strcpy(str_f,str_rp);
  //Serial.println(str_f);
  }
  if (f == 7){
  strcpy(str_g,str_rp);
  //Serial.println(str_g);
  }
  if (f == 8){
  strcpy(str_h,str_rp);
  //Serial.println(str_h);
  }
 
    
}
  

//Interrupção a ser atendida para enviar dados ao I2C Master (rasp)
void send_to_rasp() {
  //Wire.write(pkcounter);
  if (loracounter){
  vezes = pkcounter*8;
  Serial.println("ay");
  if (j < 7) 
    { Serial.println("by");
      for (k = 0;k < 32;k++)
      {
      str_aux[k] = str_lora[32*j + k];
      }
      
    Wire.write(str_aux);
    j = j+1;
    }
      
  else{
  for (k = 0;k<30;k++)
   {
      str_aux[k] = str_lora[32*7 + k];
    }
    
    Wire.write(str_aux);
    j = 0;
  }
  }
}

// Funcao pra inverter string
void reverse(char *str)
{
  
    char *src = str;
    char *end = &str_rp[0] + sizeof(str_rp) - 1;
    while (end > &str_rp[0])
    {
        char t = *end;
        *end-- = *src;
        *src++ = t;
    }
}


void setup(){
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  wdt_enable(WDTO_8S);

  Wire.begin(94);  //endereço i2c
  Wire.onRequest(send_to_rasp); //handler da função a ser chamada quando há requisição de dados por parte da rasp
  Wire.onReceive(receive_from_rasp); //handler da função a ser chamada quando a rasp envia dados

  LoRa.setPins(7, A0, 2);
  if (!LoRa.begin(433.955E6)) {
    Serial.println("Starting LoRa failed!");
  }
  LoRa.setTxPower(20, 1);
  LoRa.setSignalBandwidth(125E3);
  LoRa.setSpreadingFactor(7);
  LoRa.enableCrc();
  int packetSize = 0;
  memset(&str_rp[0], 0, sizeof(str_rp));
  wdt_reset();
}


void loop(){

  
  packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    memset(&str_lora[0], 0, sizeof(str_lora));
    loracounter = 0;
    Serial.println("Chegou do Lora:");
    // read packet
    while (LoRa.available()) {
    str_lora[loracounter] = LoRa.read();
    loracounter++;

    }
    
    Serial.println(str_lora);
    pkcounter = pkcounter + 1;
    }
    

  if (f == 8)
      { Serial.println("aqui");
        Serial.println(str_a);
        Serial.println(str_b);
        Serial.println(str_c);
        Serial.println(str_d);
        Serial.println(str_e);
        Serial.println(str_f);
        Serial.println(str_g);
        Serial.println(str_h);
        
      strcat(str_env,str_a);
      Serial.println("a");
      Serial.println(str_env);
      strcat(str_env,str_b);
      Serial.println("b");
      Serial.println(str_env);
      strcat(str_env,str_c);
      Serial.println("C");
      Serial.println(str_env);
      strcat(str_env,str_d);
      Serial.println("d");
      Serial.println(str_env);
      strcat(str_env,str_e);
      Serial.println("e");
      Serial.println(str_env);
      strcat(str_env,str_f);
      strcat(str_env,str_g);
      strcat(str_env,str_h);
        Serial.println("Chegou da rasp e enviarei pro Lora:");
        Serial.println(str_env);
        LoRa.beginPacket();  
    LoRa.print(str_env);
    LoRa.endPacket();
    f = 0;    
        }
    
}

///*/*
/*pos 0 numero do pacote
pos 123 e 252 numero do pacote
pos 2 124 253 modo de operacao
pos 1 package cycle*/
