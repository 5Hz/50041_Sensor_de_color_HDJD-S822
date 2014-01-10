/************************************************************************
** Código creado en Electrónica 5Hz                                    **
** www.5hz-electronica.com                                             **
** Por:                                                                **
**                                                                     **
** Descripción del código:                                             **
**                                                                     **
** Ejemplo para el sensor de color HDJD-S822                           **
** Coloca un objeto enfrente del sensor y checa en el                  **
** monitor serial los valores que esté leyendo el sensor               **
*************************************************************************
Conexiones:
UNO   HDJD-S822

5V    5V
GND   GND
3     LED
A0    VR
A1    VG
A2    VB

Conecta los pines de ganancia del sensor a los pines digitales
7-12 (o a GND)
*/

//--------------------------------------------------definiciones de pines

const int ledpin = 3;
const int GSR1 = 12;
const int GSR0 = 11;
const int GSG1 = 10;
const int GSG0 = 9;
const int GSB1 = 8;
const int GSB0 = 7;

int redpin = A0;
int greenpin = A1;
int bluepin = A2;

int red = 0;
int green = 0;
int blue = 0;

//----------------------------------------------------------configuracion

void setup() 
{
  Serial.begin(9600);

  pinMode(ledpin, OUTPUT);
  pinMode(GSR1, OUTPUT);
  pinMode(GSR0, OUTPUT);
  pinMode(GSG1, OUTPUT);
  pinMode(GSG0, OUTPUT);
  pinMode(GSB1, OUTPUT);
  pinMode(GSB0, OUTPUT);
  analogWrite(ledpin, 100);
  //ajusta las ganancias
  digitalWrite(GSR1, LOW);
  digitalWrite(GSR0, LOW);
  digitalWrite(GSG1, LOW);
  digitalWrite(GSG0, LOW);
  digitalWrite(GSB1, LOW);
  digitalWrite(GSB0, LOW);
  Serial.println("-------------------5HZ ELECTRONICA---------------------------");
  Serial.println("");
  Serial.println("                     PRESENTA");
  Serial.println("");
  Serial.println("*************************************************************");
  Serial.println("");
  Serial.println("      BIEVENIDO AL PROGRAMA DE PRUEBAS DEL HDJD-S822");
  Serial.println("");
  Serial.println("*************************************************************");
  Serial.println("");
}

//########################################################ciclo principal

void loop() 
{
  
  // Lee sensores
  // En la página 7 de la hoja de datos, hay una gráfica de la 
  // respuesta espectral del chip. Los factores de escala fueron
  // seleccionados basados en esta gráfica para que la ganancia de  
  // cada color sea casi igual
  red = analogRead(redpin) * 10;
  green = analogRead(greenpin) * 14;
  blue = analogRead(bluepin) * 17;
  
  //imprime los valores en el monitor serial
  Serial.print("Red: ");
  Serial.print(red, DEC);
  Serial.print("\t\tGreen: ");
  Serial.print(green, DEC);
  Serial.print("\tBlue: ");
  Serial.println(blue, DEC);
  delay(200);
}

//################################################fin del ciclo principal
