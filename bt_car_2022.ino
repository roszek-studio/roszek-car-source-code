char t;
 
#define echoPin 8 // Echo Pin
#define trigPin 9// Trigger Pin
#define Pin 2
#define Pin 3
#define Pin 5
#define Pin 6

int forward = 2; // forward pin
int front = 3; // front pin
int reverse = 4; // reverse pin
int back = 5; // back pin
int red = 11;
int yellow = 12;
int green = 13;


void setup() 
{       
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(forward, OUTPUT);
 pinMode(front, OUTPUT);
 pinMode(reverse, OUTPUT);
 pinMode(back, OUTPUT);
 pinMode(red,OUTPUT);
 pinMode(yellow,OUTPUT);
 pinMode(green,OUTPUT);
}

 
void loop() {
if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
 
if(t == 'F'){            //move forward(all motors rotate in forward direction)
  
digitalWrite(green,HIGH); // turn on green led 
digitalWrite(red,LOW); // turn on green led 
digitalWrite(yellow,LOW); // turn on green led 
digitalWrite(forward,HIGH); // turn forward motor off
digitalWrite(front,LOW); // turn front motor off
digitalWrite(reverse,HIGH); // turn reverse motor on
digitalWrite(back,LOW); // turn back motor on
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
 digitalWrite(yellow,HIGH); // turn on green led 
 digitalWrite(green,LOW); // turn on green led 
digitalWrite(red,LOW); // turn on green led 
digitalWrite(forward,LOW); // turn forward motor on
digitalWrite(front,HIGH); // turn front motor on
digitalWrite(reverse,LOW); // turn reverse motor off
digitalWrite(back,HIGH); // turn back motor off
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
 digitalWrite(yellow,HIGH); // turn on green led  
digitalWrite(front,HIGH); // turn forward motor on
digitalWrite(reverse,HIGH); // turn back motor on
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
 digitalWrite(yellow,HIGH); // turn on green led  
digitalWrite(forward,HIGH); // turn forward motor on
digitalWrite(back,HIGH); // turn back motor on

}

else if(t == 'W'){    //turn led on or off)
digitalWrite(6,HIGH);
}
else if(t == 'w'){
 digitalWrite(6,LOW);
}
 
else if(t == 'S'){      //STOP (all motors stop)
 
 digitalWrite(red,HIGH); // turn on green led 
digitalWrite(green,LOW); // turn on green led 
digitalWrite(yellow,LOW); // turn on green led 
digitalWrite(reverse,LOW); // turn reverse motor off
digitalWrite(forward,LOW); // turn forward motor off
digitalWrite(front,LOW);
digitalWrite(back,LOW);
}
delay(100);
}
