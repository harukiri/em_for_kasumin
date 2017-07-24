int datakey;
int dataslide;

void setup() {
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  Serial.println("key, slide");
}

void loop() {
  datakey = analogRead(0);
  dataslide = analogRead(1);

  //analogWrite(5, datakey);
  
  Serial.print(datakey);
  Serial.print(", ");
  Serial.println(dataslide);

  //delay(333);
}
