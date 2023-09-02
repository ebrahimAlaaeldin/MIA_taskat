
//function to return the distance in cm
float ultrasoncRight(){

  digitalWrite(trigR, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigR, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigR, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoR, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  return distance;
}
float ultrasoncLeft(){

  digitalWrite(trigL, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigL, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigL, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoL, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  return distance;
}

float ultrasoncUp(){

  digitalWrite(trigU, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigU, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigU, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoU, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  return distance;
}
float ultrasoncDown(){

  digitalWrite(trigD, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigD, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigD, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoD, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  return distance;
}