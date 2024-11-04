// Definimos los pines
const int pirPin = 2;    // Pin del sensor PIR
const int ledPin = 3;    // Pin del LED
int entradaLuz;          // Valor de lectura del sensor de luz

void setup() {
    // Configuramos el pin del sensor PIR como entrada
    pinMode(pirPin, INPUT);
    // Configuramos el pin del LED como salida
    pinMode(ledPin, OUTPUT);
  	Serial.begin(9600);
  	
}

void loop() {
    // Leemos el estado del sensor PIR
    int motionDetected = digitalRead(pirPin);
    // Leemos el valor del sensor de luz
    entradaLuz = analogRead(A0);
  
    if (motionDetected) {
        // Mapear el valor de entradaLuz a un rango de brillo (0-255)
        int brilloLed = map(entradaLuz, 1023, 600, 0, 255); // Ajusta el rango según tus condiciones de luz

        // Limitar el rango de brillo para asegurarse de que esté dentro de los valores válidos de PWM
        brilloLed = constrain(brilloLed, 0, 255);

        // Ajustar el brillo del LED
        analogWrite(ledPin, brilloLed);
    } else {
        // Apagar el LED si no hay movimiento
        analogWrite(ledPin, 0);
    }
}
