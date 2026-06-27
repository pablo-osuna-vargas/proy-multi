// Asignación de pines analógicos para las tres fotoresistencias
const int pinR = A0;   // LDR con filtro Rojo (Fila 9)
//const int pinG = A1;  // LDR con filtro Verde
//const int pinB = A2;   // LDR con filtro Azul

// Pin del buzzer
int buzzerPinR = 8;
//int buzzerPinG = 8;
//int buzzerPinB = 8;

void setup() {
  // Iniciamos la comunicación serie a 9600 baudios
  Serial.begin(9600); 
  pinMode(buzzerPinR, OUTPUT);
//  pinMode(buzzerPinG, OUTPUT);
//  pinMode(buzzerPinB, OUTPUT);
}

void loop() {
  // Lee los tres sensores simultáneamente (valores de 0 a 1023)
  int valorRojo = analogRead(pinR);
//  int valorVerde = analogRead(pinG);
//  int valorAzul = analogRead(pinB);

  // Envía los tres números en una sola línea, separados por un espacio
  
  Serial.print(valorRojo);
  Serial.println(" ");
//  Serial.print(valorVerde); 
//  Serial.println(" ");
//  Serial.println(valorAzul); // El último lleva 'println' para el salto de línea

  // Mapear lectura de sensores a frecuencia audible
  int freqR = map(valorRojo, 150, 200, 102, 122);
//  int freqG = map(valorVerde, 100, 200, 124, 147);
//  int freqB = map(valorAzul, 100, 200, 148, 169);

  // Generar tono en cada buzzer
  //tone(buzzerPinR, freqR);
  //tone(buzzerPinG, freqG);
  //tone(buzzerPinB, freqB);

  // Pausa en milisegundos para mantener un flujo estable en Pure Data
  delay(100); 
}