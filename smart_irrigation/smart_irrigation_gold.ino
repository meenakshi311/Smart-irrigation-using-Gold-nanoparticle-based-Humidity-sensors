// int sensorPin = A1;

// void setup() {
//   Serial.begin(9600);
//   pinMode(sensorPin, INPUT);
//   Serial.println("Reading From the Sensor ...");
//   delay(2000);
// }

// void loop() {
//   // Read the analog value from the sensor
//   int sensorValue = analogRead(sensorPin);

//   // Convert the sensor value to voltage
//   float voltage = sensorValue * (5.0 / 1023.0); // Assuming a 5V reference voltage

//   // Calculate the resistance based on voltage
//   float resistance = (5.0 / voltage) - 1.0;

//   // Print the resistance value
//   Serial.print("Resistance: ");
//   Serial.print(resistance);
//   Serial.println(" ohms");

//   delay(2000); // Wait for 2 seconds before the next reading
// }




//NO VOLT DIVIDER
// int sensorPin = A1;
// int relayPin = 8;

// void setup() {
//   Serial.begin(9600);
//   pinMode(relayPin, OUTPUT); 
//   digitalWrite(relayPin, HIGH);
//   pinMode(sensorPin, INPUT);
//   Serial.println("Reading From the Sensor ...");
//   delay(2000);
// }

// void loop() {

//   int sensorValue = analogRead(sensorPin);
//   float resistance = (1023.0 / sensorValue) - 1.0;
//   // resistance = 10000.0 / resistance;

//   Serial.print("Resistance: ");
//   Serial.print(resistance);
//   Serial.println(" ohms");

//   float humidity = map(resistance, 550, 0, 0, 100);

//   Serial.print("  Humidity: ");
//   Serial.print(humidity);
//   Serial.println("%");

//   if (humidity < 70) {
//     Serial.println("Humidity level is low... Turning pump on");
//     digitalWrite(relayPin, LOW); 
//     delay(1000);
//   } else {
//     Serial.println("Humidity level is high... Turning pump off");
//     digitalWrite(relayPin, HIGH);
//     delay(600);
//   }
//   delay(2000);
// }



int relayPin = 8;
int sensor_pin = A1;
int output_value;
float resistance_value;
float vout_value;
float moisture_percentage;
float referenceVoltage = 5.0; // Change this to the reference voltage you are using (e.g., 5.0 for 5V)

void setup()
{
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  pinMode(sensor_pin, INPUT_PULLUP); // Enable internal pull-up resistor

  Serial.println("Reading From the Sensor ...");
  delay(2000);
}

void loop()
{
  output_value = analogRead(sensor_pin);
  //Serial.println(output_value);
  
  resistance_value = (referenceVoltage / output_value) * 330000.0; // R2
  vout_value = referenceVoltage * (resistance_value / (resistance_value + 330000.0)); // Vout
  
  // Serial.print("R2: ");
  // Serial.print(resistance_value);
  // Serial.print(" ohms");
  
  // Serial.print("  Vout: ");
  // Serial.print(vout_value, 4);
  // Serial.print(" volts");
  
   moisture_percentage = map(resistance_value, 1638, 1890, 0, 100); 

  Serial.print("  Moisture Level: ");
  Serial.print(moisture_percentage);
  Serial.println("%");

  delay(10);

  if (moisture_percentage < 35)
  {
    Serial.println("Moisture level low... turning pump on");
    //digitalWrite(relayPin, LOW);
    delay(600);
  }
  else
  {
    Serial.println("Moisture level high... turning water pump off");
    digitalWrite(relayPin, HIGH);
    delay(600);
  }
  delay(1);
}