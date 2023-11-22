//author Ryan Bailey

//the aim of this code is to be able to control all the motors from the serial monitor

enum class Motor{
  Z_AXIS_,
  X_AXIS_,
  RM1,
  RM2,
  PICKER,
};

void setup() {
  Serial.begin(9600);
  
  //setup Z Axis Motor Pins
  pinMode(get_motor_pins_from_id(Motor::Z_AXIS_, 1), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::Z_AXIS_, 2), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::Z_AXIS_, 3), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::Z_AXIS_, 4), OUTPUT);

  //setup X Axis Motor Pins
  pinMode(get_motor_pins_from_id(Motor::X_AXIS_, 1), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::X_AXIS_, 2), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::X_AXIS_, 3), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::X_AXIS_, 4), OUTPUT);

  //setup Rising Frame 1 Motor Pins (Soldering Iron)
  pinMode(get_motor_pins_from_id(Motor::RM1, 1), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::RM1, 2), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::RM1, 3), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::RM1, 4), OUTPUT);

  //setup Rising Frame 2 Motor Pins (Picker)
  pinMode(get_motor_pins_from_id(Motor::RM2, 1), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::RM2, 2), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::RM2, 3), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::RM2, 4), OUTPUT);

  //setup Picker Motor Pins
  pinMode(get_motor_pins_from_id(Motor::PICKER, 1), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::PICKER, 2), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::PICKER, 3), OUTPUT);
  pinMode(get_motor_pins_from_id(Motor::PICKER, 4), OUTPUT);

  Serial.print("Enter Command: ");
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()){ //only do something if a command has been send from the Serial Monitor
    String str_recieved = Serial.readString();
    if(str_recieved == "Z_AXIS_FORWARD"){
      Serial.print("Move Z Axis forward by how many motor revolutions? : ");
      while (!Serial.available());
      float revolutions_float = Serial.readString().toFloat();
      if(revolutions_float == 0.0f){
        Serial.println("Either 0 or invalid value entered. Ignoring Request.");
      }
      else{
        for(int i {0}; i < 2048/revolutions_float/4; i++){
          full_step_forward(Motor::Z_AXIS_, 5); //delay amount set to 5ms.
        }
      }
    }
    else if(str_recieved == "Z_AXIS_BACKWARD"){
      Serial.print("Move Z Axis backward by how many motor revolutions? : ");
      while (!Serial.available());
      float revolutions_float = Serial.readString().toFloat();
      if(revolutions_float == 0.0f){
        Serial.println("Either 0 or invalid value entered. Ignoring Request.");
      }
      else{
        for(int i {0}; i < 2048/revolutions_float/4; i++){
          full_step_backward(Motor::Z_AXIS_, 5); //delay amount set to 5ms.
        }
      }
    }
    else if(str_recieved == "X_AXIS_FORWARD"){
      Serial.print("Move X Axis forward by how many motor revolutions? : ");
      while (!Serial.available());
      float revolutions_float = Serial.readString().toFloat();
      if(revolutions_float == 0.0f){
        Serial.println("Either 0 or invalid value entered. Ignoring Request.");
      }
      else{
        for(int i {0}; i < 2048/revolutions_float/4; i++){
          full_step_forward(Motor::X_AXIS_, 5); //delay amount set to 5ms.
        }
      }
    }
    else if(str_recieved == "X_AXIS_BACKWARD"){
      Serial.print("Move X Axis backward by how many motor revolutions? : ");
      while (!Serial.available());
      float revolutions_float = Serial.readString().toFloat();
      if(revolutions_float == 0.0f){
        Serial.println("Either 0 or invalid value entered. Ignoring Request.");
      }
      else{
        for(int i {0}; i < 2048/revolutions_float/4; i++){
          full_step_backward(Motor::X_AXIS_, 5); //delay amount set to 5ms.
        }
      }
    }
    else if(str_recieved == "RM1_FORWARD"){
      Serial.print("Move RM1 forward by how many motor revolutions? : ");
      while (!Serial.available());
      float revolutions_float = Serial.readString().toFloat();
      if(revolutions_float == 0.0f){
        Serial.println("Either 0 or invalid value entered. Ignoring Request.");
      }
      else{
        for(int i {0}; i < 2048/revolutions_float/4; i++){
          full_step_forward(Motor::RM1, 5); //delay amount set to 5ms.
        }
      }
    }
    else if(str_recieved == "RM1_BACKWARD"){
      Serial.print("Move RM1 backward by how many motor revolutions? : ");
      while (!Serial.available());
      float revolutions_float = Serial.readString().toFloat();
      if(revolutions_float == 0.0f){
        Serial.println("Either 0 or invalid value entered. Ignoring Request.");
      }
      else{
        for(int i {0}; i < 2048/revolutions_float/4; i++){
          full_step_backward(Motor::RM1, 5); //delay amount set to 5ms.
        }
      }
    }
    else if(str_recieved == "RM2_FORWARD"){
      Serial.print("Move RM2 forward by how many motor revolutions? : ");
      while (!Serial.available());
      float revolutions_float = Serial.readString().toFloat();
      if(revolutions_float == 0.0f){
        Serial.println("Either 0 or invalid value entered. Ignoring Request.");
      }
      else{
        for(int i {0}; i < 2048/revolutions_float/4; i++){
          full_step_forward(Motor::RM2, 5); //delay amount set to 5ms.
        }
      }
    }
    else if(str_recieved == "RM2_BACKWARD"){
      Serial.print("Move RM2 backward by how many motor revolutions? : ");
      while (!Serial.available());
      float revolutions_float = Serial.readString().toFloat();
      if(revolutions_float == 0.0f){
        Serial.println("Either 0 or invalid value entered. Ignoring Request.");
      }
      else{
        for(int i {0}; i < 2048/revolutions_float/4; i++){
          full_step_backward(Motor::RM2, 5); //delay amount set to 5ms.
        }
      }
    }
    else if(str_recieved == "PICKER_FORWARD"){
      Serial.print("Move Picker forward by how many motor revolutions? : ");
      while (!Serial.available());
      float revolutions_float = Serial.readString().toFloat();
      if(revolutions_float == 0.0f){
        Serial.println("Either 0 or invalid value entered. Ignoring Request.");
      }
      else{
        for(int i {0}; i < 2048/revolutions_float/4; i++){
          full_step_forward(Motor::PICKER, 5); //delay amount set to 5ms.
        }
      }
    }
    else if(str_recieved == "PICKER_BACKWARD"){
      Serial.print("Move Picker backward by how many motor revolutions? : ");
      while (!Serial.available());
      float revolutions_float = Serial.readString().toFloat();
      if(revolutions_float == 0.0f){
        Serial.println("Either 0 or invalid value entered. Ignoring Request.");
      }
      else{
        for(int i {0}; i < 2048/revolutions_float/4; i++){
          full_step_backward(Motor::PICKER, 5); //delay amount set to 5ms.
        }
      }
    }
    else{
      Serial.println("Unrecognised Command. Ignoring.");
    }
    Serial.print("Enter Command: ");
  }
}

int get_motor_pins_from_id(Motor id, int in_num){
  //give the id of the motor and the in number that you want (i.e. 1 for IN1) and the function will return the pin number.
  if (in_num < 1 || in_num > 5){
    //if an incorrect in_num gets passed, send an error message and stall the program indefinitely so that it requires restarting.
    Serial.println("Error: get_motor_pins_from_id passed invalid in_num.");
    while (true);
    return -1;
  }
  if(id == Motor::Z_AXIS_){
    switch(in_num){
      case 1: return 22;
      case 2: return 23;
      case 3: return 24;
      case 4: return 25;
    }
  }
  else if(id == Motor::X_AXIS_){
    switch(in_num){
      case 1: return 26;
      case 2: return 27;
      case 3: return 28;
      case 4: return 29;
    }
  }
  else if(id == Motor::RM1){
    switch(in_num){
      case 1: return 30;
      case 2: return 31;
      case 3: return 32;
      case 4: return 33;
    }
  }
  else if(id == Motor::RM2){
    switch(in_num){
      case 1: return 34;
      case 2: return 35;
      case 3: return 36;
      case 4: return 37;
    }
  }
  else if(id == Motor::PICKER){
    switch(in_num){
      case 1: return 38;
      case 2: return 39;
      case 3: return 40;
      case 4: return 41;
    }
  }
  else{
    //if an incorrect motor id gets passed, send an error message and stall the program indefinitely so that it requires restarting.
    Serial.println("Error: get_motor_pins_from_id passed invalid motor id.");
    while (true);
    return -1;
  }
}

void full_step_forward(Motor id, int delay_amount){ //delay_amount minimum: 2(ms)
  //full step drive
  //!A, !B,  C,  D
  // A, !B, !C,  D
  // A,  B, !C, !D
  //!A,  B,  C, !D
  
  setOutputState(id, false, false, true, true);
  delay(delay_amount);
  setOutputState(id, true, false, false, true);
  delay(delay_amount);
  setOutputState(id, true, true, false, false);
  delay(delay_amount);
  setOutputState(id, false, true, true, false);
  delay(delay_amount);
  
}

void full_step_backward(Motor id, int delay_amount){ //delay_amount minimum: 2(ms)
  setOutputState(id, true, true, false, false);
  delay(delay_amount);
  setOutputState(id, true, false, false, true);
  delay(delay_amount);
  setOutputState(id, false, false, true, true);
  delay(delay_amount);
  setOutputState(id, false, true, true, false);
  delay(delay_amount);
}

void setOutputState(Motor id, bool A, bool B, bool C, bool D){
  digitalWrite(get_motor_pins_from_id(id, 1), (A) ? HIGH : LOW);
  digitalWrite(get_motor_pins_from_id(id, 2), (B) ? HIGH : LOW);
  digitalWrite(get_motor_pins_from_id(id, 3), (C) ? HIGH : LOW);
  digitalWrite(get_motor_pins_from_id(id, 4), (D) ? HIGH : LOW);
}
