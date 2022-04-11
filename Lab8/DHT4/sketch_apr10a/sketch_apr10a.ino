#include <DHT.h>
 
// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 2
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11

#define Led1 4
#define Led2 5
#define Led3 3
 int hot = 30;
 int cold = 28;
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  // Inicializamos comunicación serie
  Serial.begin(9600);
  pinMode(Led1, OUTPUT); //green
  pinMode(Led2, OUTPUT); //yellow
  pinMode(Led3, OUTPUT); //red
  // Comenzamos el sensor DHT
  dht.begin();
 
}
 
void loop() {
    // Esperamos 5 segundos entre medidas
  delay(300);
  // Leemos la temperatura en grados centígrados (por defecto)
  float t = dht.readTemperature();
  
 
  // Comprobamos si ha habido algún error en la lectura
  if (isnan(t)) {
    Serial.println("Error obteniendo los datos del sensor DHT11");
    return;
  }
 
  // Calcular el índice de calor en grados centígrados
  float hic = dht.computeHeatIndex(t, false);
 
  //Serial.print("Temperatura: ");
  Serial.println(t);
  //Serial.print(" *C ");
  //Serial.print("Índice de calor: ");
  //Serial.print(hic);
  //Serial.print(" *C ");
  if (t < cold) { //cold
  digitalWrite(Led1, HIGH);
  delay(150);
  digitalWrite(Led1, LOW);
  delay(150);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);
  //Serial.println(" Hace frío.");
}
  else if (t >= hot) { //hot
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, HIGH);

  //Serial.println(" Hace calor.");
}
else { //fine
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, LOW);
  //Serial.println(" Temperatura Ambiente");
}
delay(1000);
  
}
