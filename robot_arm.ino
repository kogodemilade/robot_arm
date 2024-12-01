#include <LiquidCrystal_I2C.h>
#include <Wire.h>

int finger1 = A0;
int finger2 = A1;
int finger3 = A2;
int finger4 = A3;
int finger5 = A7;  //Initialize each inger and assign them to their respective analog pins. Finger 5 is on A7 because A4 and A5 are reserved for SCL and SDA (I2C communitcation)

int finger1_pos; int finger2_pos; int finger3_pos; int finger4_pos; int finger5_pos;

LiquidCrystal_I2C lcd(0x27, 20, 4); // Create an instance of the LiquidCrystal_I2C class called lcd. 

void setup() {
  Serial.begin(9600);
  lcd.init(); // Initialize the lcd object, which is an instance of the LiquidCrystal_I2C class
  lcd.backlight(); //Turn on the backlight
  lcd.setCursor(0, 0);
  lcd.print("Autobots... Roll out!"); 
  delay(5000);
}

void read_pots(int f1, int f2, int f3, int f4, int f5, int* result){   //This function reads the position of the potentiometers, and stores the values in an array
  result[0] = analogRead(f1);
  result[1] = analogRead(f2);
  result[2] = analogRead(f3);
  result[3] = analogRead(f4);
  result[4] = analogRead(f5);
}


void update_lcd(int* position_array){   //This function updates the values on the LCD
  lcd.clear();  //Clears what was previously on the LCD
  lcd.setCursor(0, 0);   //Returns the cursor to the origin
  lcd.print("Positions: ");

  for(int i=0; i< 5; ++i){    //A for loop that loops over each position for each finger, and sends them to the LCD, separated by a comma.
  lcd.print(map(position_array[i], 0, 1023, 0, 100));   //Maps the value from the potentiometer (which is between 0 and 1023) to 0 to 100, to convert to percentage
  lcd.print(",");
  }
}
// void send_data(int* position_array){}

void loop() {
  int finger_array[5];
  read_pots(finger1, finger2, finger3, finger4, finger5, finger_array); //returns an array of the positions of each potentiometer
  update_lcd(finger_array);
  delay(500);


}


// I tried to make it as short as possible, without compromising the code's beauty.

