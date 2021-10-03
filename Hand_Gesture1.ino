 const int trigPin1=10; 
 const int echoPin1=11;
 const int trigPin2=6;
 const int echoPin2=9;
 const int ledPin1=2; // Blue LED
 const int ledPin2=4; // Red LED
 long leftDistance;
 long rightDistance;
 long distance;
 long duration;
 
void setup() {
  Serial.begin(9600);
  pinMode(trigPin1,OUTPUT);
  pinMode(trigPin2,OUTPUT);
  pinMode(echoPin1,INPUT);
  pinMode(echoPin2,INPUT);
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
}

     // Detection of gestures//
  void workingStatus(bool Status1,bool Status2)
 {
     
        if(Status1==HIGH && Status2==LOW)
        {
          digitalWrite(ledPin2, LOW);    
          int Time=3;
          while(Time>0)
          {
              digitalWrite(ledPin1, HIGH);   
              delay(100);                       
              digitalWrite(ledPin1, LOW);   
              delay(100);   
              Time--;
          }
          //digitalWrite(ledPin1,Status1);
        }
        else if(Status2==HIGH && Status1==LOW )
        { 
              digitalWrite(ledPin2, HIGH);                               
        }
        
 }
 
    // Calculate distance of Object//
 void travelLength(int trigPin,int echoPin)
{
   digitalWrite(trigPin,LOW);
   delayMicroseconds(2);
   digitalWrite(trigPin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigPin,LOW);
    duration=pulseIn(echoPin,HIGH);
    distance=(0.034*duration)/2; 
    Serial.println(distance);
     if(distance>=45)
    {
      distance=45
     ;
    }
}

    //Calculate L and R  Distance//    
void moduleInitiation()
{   
       travelLength(trigPin1,echoPin1);
       leftDistance=distance;
       Serial.print("Left= ");
       Serial.println(leftDistance);
       delay(100);
       travelLength(trigPin2,echoPin2);
       rightDistance=distance;
        Serial.print("Right= ");
       Serial.println(rightDistance);
 }
void loop() {
                workingStatus(LOW,HIGH); // By default set to RED( No Detection State)//

             //Module to Detect Play and Pause Gesture// 
               moduleInitiation(); 
           if((leftDistance<=25 && rightDistance<=25) &&(leftDistance>10 && rightDistance>10))
               {  
                 workingStatus(HIGH,LOW);
                 Serial.println("Start/Stop");
                 delay(500);
                 workingStatus(LOW,HIGH);
                 
               }

          //Module to Detect FastForward Gesture// 
             moduleInitiation(); 
           if(leftDistance<10 && rightDistance<=30)
          {    
            workingStatus(HIGH,LOW);
            int tempDistance=rightDistance;
             // delay(50);
             travelLength(trigPin2,echoPin2);
             rightDistance=distance;
             
             while(rightDistance<=tempDistance  && rightDistance >=10) // && rightDistance >=10 && leftDistance<=10
            {
               Serial.println("Forward");
               tempDistance=rightDistance;
               travelLength(trigPin2,echoPin2);
               rightDistance=distance;  
               travelLength(trigPin1,echoPin1);
               leftDistance=distance;
                delay(100);
              if(rightDistance>=35 ||  leftDistance>=10 )
                {  
                  workingStatus(LOW,HIGH);
                  break;
                }           
             }
             
         } 
            
              //Module to Detect Rewind Gesture// 
              moduleInitiation(); 
                if(leftDistance<=30 && rightDistance<10 )
               { 
                 workingStatus(HIGH,LOW);
                 int tempDistance=leftDistance;
                 //delay(50);
                 travelLength(trigPin1,echoPin1);
                 leftDistance=distance;
                 
               while(leftDistance<=tempDistance  && leftDistance >=10)
                  {
                   Serial.println("Backward");
                     delay(100);
                   tempDistance=leftDistance;
                   travelLength(trigPin1,echoPin1);
                    leftDistance=distance;  
                    travelLength(trigPin2,echoPin2);
                    rightDistance=distance;
                   // delay(100);
                   if(rightDistance>=10 ||  leftDistance>=35 )
                   {  
                     workingStatus(LOW,HIGH);            
                     break;
                   }      
                 }
              }   

             //Module to Detect VolumeHigh Gesture// 
          moduleInitiation();
       if(leftDistance<=20 && rightDistance>=45)
      {
           workingStatus(HIGH,LOW);
           int tempDistance=leftDistance;
          // delay(50);
           travelLength(trigPin1,echoPin1);
           leftDistance = distance;
          

          while(tempDistance<=leftDistance && leftDistance<=35 )
          {
             Serial.println("Volumedown");
                 delay(100);
              tempDistance=leftDistance;
              travelLength(trigPin1,echoPin1);
              leftDistance = distance;
              travelLength(trigPin2,echoPin2);
              rightDistance=distance;
              //delay(100); 

             if(leftDistance>35 || rightDistance<40  )
             {
              workingStatus(LOW,HIGH);
              break;
             }
             
          }
      }
             
           //Module to Detect VolumeHigh Gesture// 
          moduleInitiation();
       if(rightDistance<=20 && leftDistance >=45)
      {
           workingStatus(HIGH,LOW);
           int tempDistance=rightDistance;
           //delay(50);
           travelLength(trigPin2,echoPin2);
           rightDistance = distance;
          

          while(tempDistance>=rightDistance && rightDistance>=5 )
          {
             Serial.println("Volumeup");
                delay(50);
              tempDistance=rightDistance;
              travelLength(trigPin2,echoPin2);
              rightDistance = distance;
              travelLength(trigPin1,echoPin1);
              leftDistance = distance;
                //delay(100); 

             if(rightDistance<5 || leftDistance <40 )
             {
              workingStatus(LOW,HIGH);
              break;
             }
             
          }
      }
                  

           //Module to Detect ScreenShot Gesture// 
           moduleInitiation();
       if((leftDistance<5 && rightDistance<5))
       {
           workingStatus(HIGH,LOW);
           Serial.println("PrintScreen");
           delay(100);
       }


//     //      delay(500);
//       void  moduleInitiation(void);
//       if((leftDistance<=25 && rightDistance<=25) &&(leftDistance>=10 && rightDistance>=10))
//       {
//           workingStatus(HIGH,LOW);
//           Serial.println("PrintScreen");
//           delay(1000);
//       }
//        void  moduleInitiation(void);
//        if(rightDistance<=6)
//        {
//          workingStatus(HIGH,LOW);
//          Serial.println("moveNext");
//        }
//        delay(1000);
//        void  moduleInitiation(void);
//         if((leftDistance<=25 && rightDistance<=25) &&(leftDistance>=10 && rightDistance>=10))
//    {  
//        workingStatus(HIGH,LOW);
//        Serial.println("Start/Stop");
//    }
//     delay(2000);
//     Serial.println("Auto4");
//     delay(100);
//     Serial.println("Auto5");
//     delay(100);
//      Serial.println("Auto6");
//     delay(100);
    
      }    

  
