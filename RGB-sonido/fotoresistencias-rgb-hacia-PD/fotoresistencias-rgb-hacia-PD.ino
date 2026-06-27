// Asignación de pin analógico para la fotoresistencia
const int pinR = A0;   // LDR con filtro Rojo (Fila 9)

// Pin del buzzer
int buzzerPinR = 8;

void setup() {
  // Iniciamos la comunicación serie a 9600 baudios
  Serial.begin(9600); 
  pinMode(buzzerPinR, OUTPUT);
}

void loop() {
  // Lee sensor (valores de 0 a 1023)
  int valorRojo = analogRead(pinR);

  // Envía los valores en una sola línea
  Serial.println(valorRojo);

  // Mapear lectura de sensores a frecuencia audible
  int freqRojo = map(valorRojo, 100, 200, 100, 200);

if(valorRojo>100 && valorRojo<200) {
  // Generar tono en buzzer
  tone(buzzerPinR, freqRojo);
} else {
  noTone(buzzerPinR);
}
  // Pausa en milisegundos para mantener un flujo estable en Pure Data
  delay(100); 
}