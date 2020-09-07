/*
#       _\|/_   A ver..., ¿que tenemos por aqui?
#       (O-O)        
# ---oOO-(_)-OOo---------------------------------
 
 
#################################################
# ********************************************* #
# *    Escaner de dispositivos en Bus I2C     * #
# *      Autor: Eulogio López Cayuela         * #
# *                                           * #
# *    Versión 1.0    Fecha: 26/04/2015       * #
# ********************************************* #
#################################################
*/

#include <Wire.h>
int numeroDispositivos = 0;

//*******************************************************
//         FUNCION DE CONFIGURACION
//*******************************************************
void setup() {
/*
Iniciamos el puerto serie para poder mostrar los datos generados
en consola, e iniciamos tambien el bus I2C.
*/
  Serial.begin (115200);
  Wire.begin();
  Serial.println(F("Buscando dispositivos en el bus I2C...\n"));
}

//*******************************************************
//        BUCLE PRINCIPAL DEL PROGRAMA
//*******************************************************
void loop(){

  //Bucle para generar las direciones a escanear
  for (int i = 1; i < 120; i++) {
    Wire.beginTransmission (i);
    uint8_t respuesta = Wire.endTransmission();
    //Si exite un dispositivo en la direccion llamada, este responderá con un CERO
    if (respuesta == 0) {
      //mostrar datos del dispositivo encontrado
      Serial.println (F("Disposivivo encontrado en la direccion: "));
      Serial.print (F("Decimal, "));
      Serial.print (i);
      Serial.print (F(" ---- Hexadecimal, (0x"));
      if (i<16) { Serial.print(F("0")); }
      Serial.print (i, HEX);
      Serial.println (F(")"));
      numeroDispositivos++;
    }
    else if (respuesta == 4) {
      Serial.print(F("Error en la direccion  0x"));
      if (i<16) { Serial.print(F("0")); }
      Serial.println (i, HEX);
    }
   
    delay (10); 
  } // Fin del bucle de busqueda

  //Mostrar resumen de la busqueda
  Serial.println (F("\n****************************************"));
  Serial.println (F("  Busqueda terminada"));
  Serial.println (F(" --------------------\n"));  
  if (numeroDispositivos == 0) {
    Serial.println (F(" No se han encontrado dispositivos"));
  }
  if (numeroDispositivos == 1) {
    Serial.println (F(" 1 dispositivo encontrado."));
  }
  if (numeroDispositivos > 1) {
    Serial.print (F(" Encontrados ")); 
    Serial.print (numeroDispositivos); 
    Serial.println (F(" dispositivos."));
  }
  Serial.println (F("****************************************"));
  while (true) {
    //'Pausa' generada por bucle infinito
  }
}

//*******************************************************
//                    FIN DE PROGRAMA
//*******************************************************



