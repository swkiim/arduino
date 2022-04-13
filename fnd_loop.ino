int seg_pin[8] = {4, 5, 6, 7, 8, 9, 10, 11};
int seg_data[16][8] = {{1,1,1,1,1,1,0,0}, {0,1,1,0,0,0,0,0},
                        {1,1,0,1,1,0,1,0}, {1,1,1,1,0,0,1,0},
                        {0,1,1,0,0,1,1,0}, {1,0,1,1,0,1,1,0},
                        {1,0,1,1,1,1,1,0}, {1,1,1,0,0,1,0,0},
                        {1,1,1,1,1,1,1,0}, {1,1,1,1,0,1,1,0},
                        {1,1,1,0,1,1,1,0}, {0,0,1,1,1,1,1,0},
                        {1,0,0,1,1,1,0,0}, {0,1,1,1,1,0,1,0},
                        {1,0,0,1,1,1,1,0}, {1,0,0,0,1,1,1,0}};

void fnd(int j){
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(seg_pin[i], seg_data[j][i]);
  }
  delay(1000);
}

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 8; i++)
  {
    pinMode(seg_pin[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int j = 0; j < 16; j++)
  {
    fnd(j);
  }
}
