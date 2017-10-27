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
  Serial.begin (9600);
  Wire.begin();
  Serial.println("Buscando dispositivos en el bus I2C...");
  Serial.println("");
}

//*******************************************************
//        BUCLE PRINCIPAL DEL PROGRAMA
//*******************************************************
void loop(){

  //Bucle para generar las direciones a escanear
  for (int i = 1; i < 120; i++)
  {
    Wire.beginTransmission (i);
    //Si exite un dispositivo en la direccion llamada, este responderá con un CERO
    if (Wire.endTransmission () == 0)
    {
      //mostrar datos del dispositivo encontrado
      Serial.println ("Disposivivo encontrado en la direccion: ");
      Serial.print ("Decimal, ");
      Serial.print (i);
      Serial.print (" ---- Hexadecimal, (0x"); 
      Serial.print (i, HEX);
      Serial.println (")");
      numeroDispositivos++;
    } 
    delay (10); 
  } // Fin del bucle de busqueda

  //Mostrar resumen de la busqueda
  Serial.println ("\n****************************************");
  Serial.println ("  Busqueda terminada");
  Serial.println (" --------------------\n");  
  if (numeroDispositivos == 0){
    Serial.println (" No se han encontrado dispositivos");
  }
  if (numeroDispositivos == 1){
    Serial.println (" 1 dispositivo encontrado.");
  }
  if (numeroDispositivos > 1){
    Serial.print (" Encontrados "); 
    Serial.print (numeroDispositivos); 
    Serial.println (" dispositivos.");
  }
  Serial.println ("****************************************");
  while (true){
    //'Pausa' generada por bucle infinito
  }
}

//*******************************************************
//                    FIN DE PROGRAMA
//*******************************************************



