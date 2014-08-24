/*
 RC PulseIn Serial Read out
 By: Nick Poole
 SparkFun Electronics
 Date: 5
 License: CC-BY SA 3.0 - Creative commons share-alike 3.0
 use this code however you'd like, just keep this license and
 attribute. Let me know if you make hugely, awesome, great changes.
 */

#define ESC 27

#define casketPin 3
#define flailPin 5
#define flamePin 6

int ch1; // Here's where we'll keep our channel values
int ch2;
int ch3;


void setup() {

  // valid pins are supposedly: (PWM) 3, 5, 6, 9, 10, and 11. Provide 8-bit PWM output with the analogWrite() function.
  pinMode(casketPin, INPUT); // Set our input pins as such
  pinMode(flailPin, INPUT);
  pinMode(flamePin, INPUT);

  Serial.begin(9600); // Pour a bowl of Serial

}

// function clearAndHome()
// clear the terminal screen and send the cursor home
void clearAndHome()
{
  Serial.write(ESC); // ESC
  Serial.write("[2J"); // clear screen
  Serial.write(ESC); // ESC
  Serial.write("[H"); // cursor to home
}

// print helper function
void displayStatus(int channel, unsigned long value)
{
  Serial.print("Channel ");
  Serial.print(channel);
  Serial.print(": ");
  Serial.println(value);
}

void handleCasketRx(unsigned long value)
{
}

void handleFlailRx(unsigned long value)
{
}

void handleFlameRx(unsigned long value)
{
}

void loop() {

  ch1 = pulseIn(5, HIGH, 25000); // Read the pulse width of 
  ch2 = pulseIn(6, HIGH, 25000); // each channel
  ch3 = pulseIn(7, HIGH, 25000);

  displayStatus(5,ch1);
  displayStatus(6,ch2);
  displayStatus(7,ch3);

  delay(250); // I put this here just to make the terminal window happier
  clearAndHome();

}

