/* Name: Jadon Lao           
 * Student Number: 89583587 
 * CWL & UBC email: wlao01@student.ubc.ca
 * Lab Section: L2C    
 * Assignment: Lab 8 - Whack a Mole      */      

//Define game parameters (Modify the numbers only)
#define NUM_PROMPTS   5    //modifies the amount of prompts per round
#define ROUNDS        5    //rounds per game
#define T_ON          500 //the amount of time the LEDs are ON
#define K             0.85  //the constant to multiply by every successive round

//Define Pins (DO NOT CHANGE)
#define LEDR 12
#define LEDY 11
#define LEDB 10
#define LEDG 9

#define PB_RED 		7
#define PB_YELLOW 	6
#define PB_BLUE		5
#define PB_GREEN 	4
#define PB_START 	13

//Defined keywords to help code easier
#define ON  HIGH
#define OFF LOW

//define the minimum hold it takes for button to register
#define MINHOLD 20


//initialization
void setup()
{
 
   //configure pin modes: Input for the buttons, output for the LED
  	pinMode(PB_RED, INPUT);
  	pinMode(PB_YELLOW,INPUT);
    pinMode(PB_BLUE, INPUT);
    pinMode(PB_GREEN, INPUT);
  	pinMode(PB_START, INPUT);
  
  	pinMode(LEDR, OUTPUT);
  	pinMode(LEDY,OUTPUT);
    pinMode(LEDB, OUTPUT);
    pinMode(LEDG, OUTPUT);
  
  	Serial.begin(9600);
  	
  	// Randomizes the seed/pattern
  	randomSeed(analogRead(0));
}

// ButtonState variables for all 5 Buttons:
// buttonState is one frame in the past, presentState is current frame.
int buttonStartState = 0;
int presentStartState = 0;

int buttonRedState = 0;
int presentRedState = 0;

int buttonYellowState = 0;
int presentYellowState = 0;

int buttonBlueState = 0;
int presentBlueState = 0;

int buttonGreenState = 0;
int presentGreenState = 0;

// Variables for all the time and millis functions:
unsigned long time_now = 0;
int timerPause = 0; //Turns true when code needs to run a set sequence
int starting = 0; // Turns on once its starts for the sequence

// Variables for anything related to score
int roundScore = 0; 
int totalScore = 0;
int roundNum = 0;


// Variable counting down from the amount of buttons left in the round
int buttonsLeft = NUM_PROMPTS + 1;

// Variables for time button is either clicked, held or released
int buttonPress = 0;
int buttonRelease = 0;
int buttonHeld = 0;

// Variable for determining if the player loses:
int potentialLoss = 0; //Placeholder value until code confirms player intended to hit the button
int gameLoss = 0;

//main program loop
void loop()
{
  // Added a fancy start up sequence
  if (starting == 0) {
    starting = 1;
    timerPause = 1;
    startUp();
  }
  //Initializes the millis function: Internal timer
  if (millis() >= time_now + T_ON*pow(K,roundNum - 1) && roundNum > 0 && buttonsLeft > 0 && timerPause == 0){
    time_now = time_now + T_ON*pow(K,roundNum-1);
    // Turns on the light every interval
    digitalWrite(LEDR, OFF); 
  	digitalWrite(LEDY, OFF); 
  	digitalWrite(LEDB, OFF); 
  	digitalWrite(LEDG, OFF);
    // Randomly selects a LED to light with a bit of delay
    delay(100*pow(K,roundNum - 1));
    digitalWrite(random(9,13),ON);
    buttonsLeft -= 1;
    }
  
  // If all lights in the round flash, queue another round
  else if (buttonsLeft == 0 && roundNum > 0) {
    // Runs if there are no game loss errors
    if (gameLoss != 1) {
      // If points gained is the maximum, then run a perfect sequence
      if (roundScore == roundNum * ROUNDS) {
      	buttonsLeft = NUM_PROMPTS + 1;
        roundNum += 1;
        timerPause = 1;
      	successfulRun();
      }
      // If the user is inactive, close the game
      else if (roundScore == 0) {
        Serial.print("Button not pressed. Game over!");
      	timerPause = 1;
      	finished();
      	roundNum = 0;
      }
      // Otherwise, run the regular round end sequence
      else {
      	buttonsLeft = NUM_PROMPTS + 1;
      	roundNum += 1;
        timerPause = 1;
      	finishedRound();
      }
    }
    
    // If the user misses and clicks the wrong button, this will run:
    else {
      Serial.print("Game over! Score: ");
      Serial.println(totalScore);
      timerPause = 1;
      finished();
      roundNum = 0;
    }
    
    // If the game is over: round ends with score displayed
    if (roundNum == ROUNDS) {
      Serial.print("Game over! Score: ");
      Serial.println(totalScore);
      timerPause = 1;
      finished();
      roundNum = 0;
    }
  }
  
  // Code that runs if the start button is pressed
  // Checks if the Start button is already pressed
  buttonStartState = digitalRead(PB_START);
  // Edge detection for the start button
  if (buttonStartState != presentStartState) {
    if (presentStartState == 0) {
      buttonPress = millis();
      
    }
    
    // If the button is released, start the game
    if (presentStartState == 1) {
      buttonRelease = millis();
      buttonHeld = buttonRelease - buttonPress;
      if (buttonHeld > MINHOLD){
        roundNum = 1;
        time_now = millis() - T_ON*pow(K,roundNum - 1) - 10;
      }
    }
  }
  presentStartState = buttonStartState;
  
  //When Red button is pressed:
  //Checks if buttons is already pressed
  buttonRedState = digitalRead(PB_RED);
  //Button Edge detection:
  if (buttonRedState != presentRedState) {
    if (presentRedState == 0) {
      buttonPress = millis();
      
      //If the button is pressed while respective lightbulb is on:
      if (digitalRead(LEDR) != 0) {
        digitalWrite(LEDR, OFF);
    	buttonHeld = 0;
        // Add to score for success and print it:
        totalScore += roundNum;
        roundScore += roundNum;
        Serial.print("Round ");
      	Serial.print(roundNum);
      	Serial.print(" -- Score: ");
      	Serial.println(totalScore);
      }
      // If the button is pressed while other lights are on: check if they accidentally clicked it
      else if (digitalRead(LEDY) == 1 || digitalRead(LEDB) == 1 ||digitalRead(LEDG) == 1)
      	potentialLoss = 1;
    }
    
    //Release: Check if the click was accidental, runs through time it takes to release
    if (presentRedState == 1) {
      buttonRelease = millis();
      buttonHeld = buttonRelease - buttonPress;
    }
    if (potentialLoss == 1){
      // If it was accidental, waived the misclick
      if (buttonHeld < MINHOLD) {
        potentialLoss = 0;

      }
      // Otherwise, queue a loss when round is over
      else {
        gameLoss = 1;
      }
    }
  }
  presentRedState = buttonRedState;
  
  
  //When Yellow button is pressed:
  //Checks if button is pressed
  buttonYellowState = digitalRead(PB_YELLOW);
  // Edge detection sequence for yellow button
  if (buttonYellowState != presentYellowState) {
    if (presentYellowState == 0) {
      buttonPress = millis();
      
      //If the button is pressed while respective lightbulb is on:
      if (digitalRead(LEDY) != 0) {
        digitalWrite(LEDY, OFF);
    	buttonHeld = 0;
        // Add to score for success and print it:
        totalScore += roundNum;
        roundScore += roundNum;
        Serial.print("Round ");
      	Serial.print(roundNum);
      	Serial.print(" -- Score: ");
      	Serial.println(totalScore);
      }
      // If the button is pressed while other lights are on: check if they accidentally clicked it
      else if (digitalRead(LEDR) == 1 || digitalRead(LEDB) == 1 ||digitalRead(LEDG) == 1)
      	potentialLoss = 1;
    }
    
    //Release: Check if the click was accidental, runs through time it takes to release
    if (presentYellowState == 1) {
      buttonRelease = millis();
      buttonHeld = buttonRelease - buttonPress;
    }
    if (potentialLoss == 1){
      // If it was accidental, waived the misclick
      if (buttonHeld < MINHOLD) {
        potentialLoss = 0;

      }
      // Otherwise, queue a loss when round is over
      else {
        gameLoss = 1;
      }
    }
  }
  presentYellowState = buttonYellowState;
  
  //When Blue button is pressed:
  buttonBlueState = digitalRead(PB_BLUE);
  
  // Edge detection conditionals for blue button:
  if (buttonBlueState != presentBlueState) {
    if (presentBlueState == 0) {
      buttonPress = millis();
      //If the button is pressed while respective lightbulb is on:
      if (digitalRead(LEDB) != 0) {
        digitalWrite(LEDB, OFF);
    	buttonHeld = 0;
        // Add to score for success and print it:
        totalScore += roundNum;
        roundScore += roundNum;
        Serial.print("Round ");
      	Serial.print(roundNum);
      	Serial.print(" -- Score: ");
      	Serial.println(totalScore);
      }
      // If the button is pressed while other lights are on: check if they accidentally clicked it
      else if (digitalRead(LEDY) == 1 || digitalRead(LEDR) == 1 ||digitalRead(LEDG) == 1)
      	potentialLoss = 1;
    }
    
    //Release: Check if the click was accidental, runs through time it takes to release
    if (presentBlueState == 1) {
      buttonRelease = millis();
      buttonHeld = buttonRelease - buttonPress;
    }
    if (potentialLoss == 1){
      // If it was accidental, waived the misclick
      if (buttonHeld < MINHOLD) {
        potentialLoss = 0;

      }
      // Otherwise, queue a loss when round is over
      else {
        gameLoss = 1;
      }
    }
  }
  presentBlueState = buttonBlueState;
  
  // When Green button is pressed:
  buttonGreenState = digitalRead(PB_GREEN);
  
  if (buttonGreenState != presentGreenState) {
    if (presentGreenState == 0) {
      buttonPress = millis();
      
      //If the button is pressed while respective lightbulb is on:
      if (digitalRead(LEDG) != 0) {
        digitalWrite(LEDG, OFF);
    	buttonHeld = 0;
        // Add to score for success and print it:
        totalScore += roundNum;
        roundScore += roundNum;
        Serial.print("Round ");
      	Serial.print(roundNum);
      	Serial.print(" -- Score: ");
      	Serial.println(totalScore);
      }
      // If the button is pressed while other lights are on: check if they accidentally clicked it
      else if (digitalRead(LEDY) == 1 || digitalRead(LEDB) == 1 ||digitalRead(LEDR) == 1)
      	potentialLoss = 1;
    }
    
    //Release: Check if the click was accidental, runs through time it takes to release
    if (presentGreenState == 1) {
      buttonRelease = millis();
      buttonHeld = buttonRelease - buttonPress;
    }
    if (potentialLoss == 1){
      // If it was accidental, waived the misclick
      if (buttonHeld < MINHOLD) {
        potentialLoss = 0;

      }
      // Otherwise, queue a loss when round is over
      else {
        gameLoss = 1;
      }
    }
  }
  presentGreenState = buttonGreenState;

}
// Start up sequence
void startUp() {
  digitalWrite(LEDR, ON);
  delay(200);
  digitalWrite(LEDY, ON);
  delay(200);
  digitalWrite(LEDB, ON);
  digitalWrite(LEDR, OFF);
  delay(200);
  digitalWrite(LEDG, ON);
  digitalWrite(LEDY, OFF);
  delay(200);
  digitalWrite(LEDB, OFF);
  delay(200);
  digitalWrite(LEDG, OFF);
  time_now += 1000;
  timerPause = 0;
}


// Regular round flashes lights once
void finishedRound() {
  digitalWrite(LEDR, ON); 
  digitalWrite(LEDY, ON); 
  digitalWrite(LEDB, ON); 
  digitalWrite(LEDG, ON); 
  delay(500);
  digitalWrite(LEDR, OFF); 
  digitalWrite(LEDY, OFF); 
  digitalWrite(LEDB, OFF); 
  digitalWrite(LEDG, OFF); 
  time_now += 500;
  timerPause = 0;
}

// [Bonus] Successful round: Function runs when there is a no mistake round
// Perfect round adds a lights turn on in a sequence
void successfulRun() {
  digitalWrite(LEDR, ON); 
  digitalWrite(LEDY, ON); 
  digitalWrite(LEDB, ON); 
  digitalWrite(LEDG, ON); 
  delay(500);
  digitalWrite(LEDR, OFF); 
  digitalWrite(LEDY, OFF); 
  digitalWrite(LEDB, OFF); 
  digitalWrite(LEDG, OFF);  
  delay(300);
  digitalWrite(LEDR, ON);
  delay(300);
  digitalWrite(LEDY, ON);
  delay(300);
  digitalWrite(LEDB, ON);
  delay(300);
  digitalWrite(LEDG, ON);
  delay(300);
  digitalWrite(LEDR, OFF); 
  digitalWrite(LEDY, OFF); 
  digitalWrite(LEDB, OFF); 
  digitalWrite(LEDG, OFF);
  time_now += 2000;
  timerPause = 0;
  
}
void finished() {
  digitalWrite(LEDR, ON); 
  digitalWrite(LEDY, ON); 
  digitalWrite(LEDB, ON); 
  digitalWrite(LEDG, ON); 
  delay(500);
  digitalWrite(LEDR, OFF); 
  digitalWrite(LEDY, OFF); 
  digitalWrite(LEDB, OFF); 
  digitalWrite(LEDG, OFF);  
  delay(300);
  digitalWrite(LEDR, ON); 
  digitalWrite(LEDY, ON); 
  digitalWrite(LEDB, ON); 
  digitalWrite(LEDG, ON); 
  delay(500);
  digitalWrite(LEDR, OFF); 
  digitalWrite(LEDY, OFF); 
  digitalWrite(LEDB, OFF); 
  digitalWrite(LEDG, OFF);  
  delay(300);
  digitalWrite(LEDR, ON); 
  digitalWrite(LEDY, ON); 
  digitalWrite(LEDB, ON); 
  digitalWrite(LEDG, ON); 
  delay(500);
  digitalWrite(LEDR, OFF); 
  digitalWrite(LEDY, OFF); 
  digitalWrite(LEDB, OFF); 
  digitalWrite(LEDG, OFF);
  delay(300);
  digitalWrite(LEDG, ON);
  delay(300);
  digitalWrite(LEDB, ON);
  delay(300);
  digitalWrite(LEDY, ON);
  delay(300);
  digitalWrite(LEDR, ON);
  delay(300);
  digitalWrite(LEDR, OFF); 
  digitalWrite(LEDY, OFF); 
  digitalWrite(LEDB, OFF); 
  digitalWrite(LEDG, OFF);
  time_now += 3600;
  timerPause = 0;
}

