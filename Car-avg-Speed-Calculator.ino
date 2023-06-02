const int pins = 2;
const float triggerDist = 25;
const float fullDist = 320;

float getDist(int trigPin, int echoPin) {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  float duration = pulseIn(echoPin, HIGH);
  
  return  duration * 0.034 / 2;
}

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT);
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() == 0) {}
  float dist = 30;
  while (dist >= triggerDist) {
    float mass = Serial.read();
    float time1;
    float time2;
    float timeTaken;
    dist = getDist(2, 3);
    Serial.print("Sensor1: ");
    Serial.println(dist);
    delay(10);
    if (dist < triggerDist) {
      Serial.println("Obect detected on sensor 1");
      time1 = millis();
      time2 = millis();
      float dist2 = getDist(5, 6);
      while (dist2 > triggerDist) {
        delay(10);
        dist2 = getDist(5, 6);
        Serial.print("Sensor2: ");
        Serial.println(dist2);
        time2 = millis();
      }
      Serial.println("Object detected on sensor ");
      timeTaken = (time2 - time1) * 0.001;
      // Serial.print("time taken: ");
      // Serial.println(timeTaken);
Serial.print("Speed: ");~
      Serial.println((triggerDist / timeTaken));
    }
  }
}