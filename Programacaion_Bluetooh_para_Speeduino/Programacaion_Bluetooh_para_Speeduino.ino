#include <SoftwareSerial.h>

SoftwareSerial miBT (10, 11); // pin 10 como RX, pin 11 como TX

void setup() {
  Serial.begin (9600); // comunicacion de monitor serial a 9600 bps
  Serial.println ("Listo para programar con EARChile  romeroveliz@gmail.com"); // escribe Listo en el monitor
  Serial.println ("Recuerda que la ecu Speeduino o SpeedTech funciona a 115200 baud");
  Serial.println ("cualquier consulta +56958592938");
  miBT.begin (9600); // la comunicación entre Arduino y el módulo es a 9600 bps
}

void loop() {
if (miBT.available ()) // si hay información disponible desde el módulo
   Serial.write (miBT.read ()); //primero lee Bluetooth y despues  enviando un monitor serial 
if (Serial.available ()) // si hay información disponible desde el monitor serial
   miBT.write (Serial.read ()); // lee el monitor en serie y enviando un Bluetooth

}
//----------------------------------------------------------------------------------
//CODIGOS AT PARA MODULO AT-09  4.0
// AT+VERSION     version
// AT+NAME   indica el nonbre (auqneu muchas veces no dice nada)
// AT+BAUD   velocidad de comunicacion del modulo
     // 1    1200bps
     // 2   2400bps
     // 3   4800bps
     // 4   9600bps  (defaul, es necesario cambiar para speeduino o megasquirt)
     // 5   19200bps
     // 6   38400bps
     // 7   57600bps
     // 8   115200bps
   // ai quieren configuara el Baud hay que agregar el numero despues del comando todo junto ej: AT+BAUD8
// AT+PIN   indica el codigo de seguridad
// AT+ROLEO  indca el estado si es esclavo o maestro     1 = maestro    2= escalvo   ej: AT+ROLEO1 
//------------------------------------------------------------------------------------------
// CODIGOS AT PARA MODULOS HC-05 HC-06
// alguos modulos es necesario poner el sigo ? despues del comando (todo junto) para hacer la pregunta ej: AT+VERSION?
//  AT   testeo de comunicacion (generalmente respnde con un OK)
//  AT+RESET  resetea el modulo 
//  AT+VERSION
//  AT+ORGL   vuelve los valores a fabrica
//  AT+NAME
//  AT+ROLE
//  AT+UART   pregunta la velocidad e coneccion  para cambiar la velocidad es necesario ponerlo de la siguiente manera ej: AT+UART=115200,0,0   (LOS 0 Y LAS COMAS SON IMPORTANTES)
//  AT+PSWD  o AT+PSWDAT
   // si necesita cambiar el valor solo necesitas agregar un = despues del comando con el valor nuevo  ej: AT+NAME=SpeedTech 

     
