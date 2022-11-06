int smoke, cmon, flame;
int alarm = 0;
int s, c, f;

const int buzzer = 9;
const char sound_pattern_size1 = 32;
const double sound_pattern1[sound_pattern_size1] = {
  392.00, 0, 392.00, 587.33,
  523.25, 0, 466.16, 0,
  440.00, 0, 440.00, 440.00,
  523.25, 0, 466.16, 440.00,
  392.00,0, 392.00, 932.33,
  880.00, 932.33, 880.00, 932.33,
  392.00, 0, 392.00, 932.33,
  880.00, 932.33, 880.00, 932.33
};
int spp = 0;

void setup()
{
  pinMode(A0, INPUT); //smooke
  pinMode(A1, INPUT); //fire
  pinMode(A2, INPUT); //carbon mon
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
}

void loop()
{
  smoke = analogRead(A0);
  cmon = analogRead(A2);
  flame = analogRead(A1);

  Serial.print("Smoke: "); Serial.print(smoke);
  Serial.print(" CMon: "); Serial.print(cmon);
  Serial.print(" Flame: "); Serial.println(flame);

  if(alarm) {
    if(spp > 31) {
    spp = 0;
    }
    noTone(buzzer);
    tone(buzzer, sound_pattern1[spp]);
    spp++;
  }


  if(smoke > 900)
  {
    if(s == 0)
    {
      Serial.println("smoke");
      digitalWrite(2, HIGH);
      alarm = 1;
    }
    s = 1;
  }
  else
  {
    s = 0;
    digitalWrite(2, LOW);
  }
  if(cmon > 700)
  {
    if(c == 0)
    {
      Serial.println("cm");
      digitalWrite(3, HIGH);
      alarm = 1;
    }
    c = 1;
  }
  else
  {
    c = 0;
    digitalWrite(3, LOW);
  }
  if(flame > 1000)
  {
    if(f == 0)
    {
      Serial.println("flame");
      digitalWrite(4, HIGH);
      alarm = 1;
    }
    f = 1;
  }
  else
  {
    f = 0;
    digitalWrite(4, LOW);
  }
  if(smoke < 900 && cmon < 700 && flame < 1000) {
    noTone(buzzer);
    alarm = 0;
  }

}
