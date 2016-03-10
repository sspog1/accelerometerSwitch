/**
 *  @var t
 *  magnatudeT[0] is the previous value of the sensor pin
 *  magnatudeT[1] is the current value of the sensor pin
 */
int magnatudeT[] = {
  0,0}; 

int accelermeterPinX = A0;
int accelermeterPinY = A1;
int accelermeterPinZ = A2;

int acclerometerX = 0;
int acclerometerY = 0;
int acclerometerZ = 0;


/**
 *  @var diff 
 *  this will need tuned.
 *  the smaller the number the more sensative
 */
int triggerValue = 5;
void setup(){
  pinMode(13, OUTPUT);
}

void loop(){
  //store previous magnatude in magnatudeT[0] before we get the current one
  magnatudeT[0] = magnatudeT[1];

  // read current analog values
  acclerometerX = analogRead( accelermeterPinX );
  acclerometerY = analogRead( accelermeterPinY );
  acclerometerZ = analogRead( accelermeterPinZ );

  //use 3D pythagoras to get a magnatued of acceleration accross all axis
  magnatudeT[1] = sqrt( sq(acclerometerX) + sq(acclerometerY) + sq(acclerometerZ) );

  //calculate the differance between current and previous acceleration
  int diff = magnatudeT[0] - magnatudeT[1];

  // if its negative get rid of th enegative we just care about the size not direction of the acceleration
  if(diff < 0) {
    // if the magnatued is negative make it posative
    diff*=(-1); 
  }

  // check the diff between current and previous and current acceleration and 
  // see if it is bigger than our trigger val
  // the smaller the trigger value the more sensative it will be
  if( diff > triggerValue ) {
    // do some shit as we are moving!
    // if we have a big delay in here remember the accelerometer will not be getting checked
    digitalWrite(13, HIGH);
    delay(1000);
  }   

  //ready to go again lets switch off the light
  digitalWrite(13, LOW);
}


