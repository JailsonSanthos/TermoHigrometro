/*******************************************************************************************************************************************************************
                                                          PROJETO TERMO-HIGRÔMETRO

  Material: Arduino / Display LCD / Sensor DHT11 / Jampers / Protoboard

  Efeito: O sensor DHT11 faz a leitura da temperatura e umidade do ar e apresenta o resultado na tela do dispaly do LCD.

  Aluno: Jailson Coreia dos Santos

  Data: 19/02/21

********************************************************************************************************************************************************************/

/*********************************************************** IMPORTAÇÃO DE BIBLIOTECAS *****************************************************************************/

#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal.h>

/************************************************************** MAPEAMENTO DE HARDWARE *****************************************************************************/

LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

#define dhtPin 8
#define dhtType DHT11

DHT dhtSensor (dhtPin, dhtType);

/**************************************************************** ESTRUTURA DE CÓDIGO *****************************************************************************/


void setup() {

  lcd.begin (16, 2);
  dhtSensor.begin ();
  
  lcd.clear();
  lcd.setCursor (0, 0);
  
  lcd.print F("Inicializando");
  delay(1000);
  lcd.print F(".");
  delay(1000);
  lcd.print F(".");
  delay(1000);
  lcd.print F(".");
  delay(1000);

} // Final do Setup


void loop() {

  float umidade = dhtSensor.readHumidity();
  float temperatura = dhtSensor.readTemperature();

  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print F("Umid Ar:");
  lcd.print (umidade);
  lcd.print F("%");
  lcd.setCursor (0, 1);
  lcd.print F("Temp:");
  lcd.print (temperatura);
  lcd.print F("C");
  delay(1000);

} // Final do Loop principal
