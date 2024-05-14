/*
 KeyPressed on PIN1
 by Mischianti Renzo <http://www.mischianti.org>

 https://www.mischianti.org/2019/01/02/pcf8574-i2c-digital-i-o-expander-fast-easy-usage/
*/

#include "Arduino.h"
#include "PCF8574.h"

// Set i2c address
PCF8574 pcf8574(0x20);  //alamat i2c posisi speed lever
PCF8574 pcf8574B(0x21); //alamat i2c posisi levernya P N F R
int var_speed,var_pos;  //variabel sementara untuk menampung speed dan posisi lever
String data_out;        //variabel string untuk kirim data melalui i2c

void setup()
{
	Serial.begin(9600);

	pcf8574.pinMode(P0, INPUT);
	pcf8574.pinMode(P1, INPUT);
  pcf8574.pinMode(P2, INPUT);
  pcf8574.pinMode(P3, INPUT);
  pcf8574.pinMode(P4, INPUT);
  pcf8574.pinMode(P5, INPUT);
  pcf8574.pinMode(P6, INPUT);
  pcf8574.pinMode(P7, INPUT);
	pcf8574.begin();
  
  pcf8574B.pinMode(P0, INPUT);
  pcf8574B.pinMode(P1, INPUT);
  pcf8574B.pinMode(P2, INPUT);
  pcf8574B.pinMode(P3, INPUT);
  pcf8574B.begin();
}

void loop()
{
 int p0 = pcf8574.digitalRead(P0);
 int p1 = pcf8574.digitalRead(P1);
 int p2 = pcf8574.digitalRead(P2);
 int p3 = pcf8574.digitalRead(P3);
 int p4 = pcf8574.digitalRead(P4);
 int p5 = pcf8574.digitalRead(P5);
 int p6 = pcf8574.digitalRead(P6);
 int p7 = pcf8574.digitalRead(P7);

 int pb0 = pcf8574B.digitalRead(P0);
 int pb1 = pcf8574B.digitalRead(P1);
 int pb2 = pcf8574B.digitalRead(P2);
 int pb3 = pcf8574B.digitalRead(P3);
 
	delay(500);
 
 if (pb0 == 1) {
    var_pos=9;
   
 }
 else if (pb1 == 1) {
    var_pos=10;
    
 }
 else if (pb2 == 1) {
    var_pos=11;
   
 }
 else if (pb3 == 1) {
    var_pos=12;
    
 }
 else {
  var_pos=13;
 }

 //Serial.print("Var_pos : ");
 //Serial.print(var_pos);

if (var_pos == 9) {
    data_out += String('P');
   
 }
 else if (var_pos == 10) {
    data_out += String('N');
    
 }
 else if (pb2 == 1) {
    data_out += String('F');
    
   
 }
 else if (pb3 == 1) {
    data_out += String('R');
    
 }
 else {
  data_out += String('X');
 }


 
 if (p0 == 1) {
    var_speed=1;
 }
 else if (p1 == 1) {
    var_speed=2;   
 }
 else if (p2 == 1) {
    var_speed=3;
 }
 else if (p3 == 1) {
    var_speed=4;
 }
 else if (p4 == 1) {
    var_speed=5;   
 }
 else if (p5 == 1) {
    var_speed=6;  
 }
 else if (p6 == 1) {
    var_speed=7;
 }
 else if (p7 == 1) {
    var_speed=8;
 }
 else {
  var_speed=14;   //kode 14 untuk Open
 }
 //Serial.print("Var_speed : ");
 //Serial.println(var_speed);

if (var_speed == 1) {
    data_out += String('1');   
 }
 else if (var_speed == 2) {
    data_out += String('2');    
 }
 else if (var_speed == 3) {
    data_out += String('3');      
 }
 else if (var_speed == 4) {
    data_out += String('4');   
 }
 else if (var_speed == 5) {
    data_out += String('5');   
 }
 else if (var_speed == 6) {
    data_out += String('6');    
 }
 else if (var_speed == 7) {
    data_out += String('7');      
 }
 else if (var_speed == 8) {
    data_out += String('8');   
 }
 else {
  data_out += String('-'); //kode 14 untuk Open
 }

Serial.print("Speed Pos : ");
Serial.println(data_out);

data_out="";

 
}
