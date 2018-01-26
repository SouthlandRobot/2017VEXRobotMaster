#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    HandL,          sensorPotentiometer)
#pragma config(Sensor, in2,    HandR,          sensorPotentiometer)
#pragma config(Sensor, dgtl1,  SonarA,         sensorSONAR_cm)
#pragma config(Sensor, dgtl3,  SonarB,         sensorSONAR_cm)
#pragma config(Sensor, dgtl5,  H1,             sensorDigitalOut)
#pragma config(Sensor, dgtl6,  H2,             sensorDigitalOut)
#pragma config(Sensor, dgtl7,  HW,             sensorDigitalOut)
#pragma config(Sensor, I2C_1,  FL,             sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  FR,             sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  BL,             sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  BR,             sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_5,  H1,             sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_6,  H2,             sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           FL,            tmotorVex393_HBridge, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port4,           BL,            tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port5,           BR,            tmotorVex393_MC29, openLoop, encoderPort, I2C_4)
#pragma config(Motor,  port6,           AA,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           AB,            tmotorVex393_MC29, openLoop, encoderPort, I2C_5)
#pragma config(Motor,  port8,           AC,            tmotorVex393_MC29, openLoop, encoderPort, I2C_6)
#pragma config(Motor,  port9,           AD,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          FR,            tmotorVex393_HBridge, openLoop, encoderPort, I2C_2)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define BaseFL motor[FL]
#define BaseFR motor[FR]
#define BaseBL motor[BL]
#define BaseBR motor[BR]

#define ArmMotorA motor[AA]
#define ArmMotorB motor[AB]
#define ArmMotorC motor[AC]
#define ArmMotorD motor[AD]

#define HandMotorA SensorValue[H1]
#define HandMotorB SensorValue[H1]
#define HandMotorC SensorValue[H2]
#define HandMotorD SensorValue[H2]
#define MEMORY_SIZE 4096
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
typedef struct {
	bool motorChange;
	bool armChange;
	bool handChange;
	int lYError;
	int lXError;
	int rYError;
	int rXError;
} RobotState;
RobotState this;
void preSetFrontMove(int *array);
void preSetBackMove(int *array);
void preSetLeftMove(int *array);
void preSetRightMove(int *array);

void ArmMotorUpSet(int *array);
void ArmMotorDownSet(int *array);
void HandMotorUpSet(int *array);
void HandMotorDownSet(int *array);
void specialSetMove(int *array);
void preSetRightTrun(int *array);
void preSetLeftTrun(int *array);
void resetFront(int *array);
void resetBack(int *array);
void resetLeft(int *array);
void resetRight(int *array);
void resetArmMotorSet(int *array);
void resetHandMotorSet(int *array);
void resetspecialSet(int *array);
void baseMove();
void resetAll();
int mode;
task displayInfo();
float rate;
//0:auto|1:manu
//0:Car mode|1:Coordinate mode
//0:Speed control|1:Step mode
//0:low arm state|1:hold arm state|2:changing state
//
task main()
{
	rate=1;
	this.lYError=vexRT[Ch3];
	this.lXError=vexRT[Ch4];
	this.rYError=vexRT[Ch2];
	this.rXError=vexRT[Ch1];
	mode=3;
	startTask(displayInfo);
	while(true){
		baseMove();
	}
}

void preSetFrontMove(int *array){
	BaseFL=255;
	BaseFR=-255;
	BaseBL=255;
	BaseBR=-255;
	this.motorChange=true;
}
void preSetBackMove(int *array){
	BaseFL=-255;
	BaseFR=255;
	BaseBL=-255;
	BaseBR=255;
	this.motorChange=true;
}
void preSetLeftMove(int *array){
	BaseFL=-255;
	BaseFR=-255;
	BaseBL=255;
	BaseBR=255;
	this.motorChange=true;
}
void preSetRightMove(int *array){
	BaseFL=255;
	BaseFR=255;
	BaseBL=-255;
	BaseBR=-255;
	this.motorChange=true;
}
void preSetRightTrun(int *array){
	BaseFL=255;
	BaseFR=255;
	BaseBL=255;
	BaseBR=255;
	delay(50);
	this.motorChange=true;
}
void preSetLeftTrun(int *array){
	BaseFL=-255;
	BaseFR=-255;
	BaseBL=-255;
	BaseBR=-255;
	delay(50);
	this.motorChange=true;
}
void specialSetMove(int* array){
	BaseFL=array[0];
	BaseFR=array[1];
	BaseBL=array[2];
	BaseBR=array[3];
	//this.motorChange=true;
}


void ArmMotorUpSet(int *array){
	ArmMotorA=-255;
	ArmMotorB=255;
	ArmMotorC=-255;
	ArmMotorD=255;
	this.armChange=true;
}
void ArmMotorDownSet(int *array){
	ArmMotorA=-255;
	ArmMotorB=-255;
	ArmMotorC=-255;
	ArmMotorD=-255;
	this.armChange=true;
}
void HandMotorUpSet(int *array){
	HandMotorA=1;
	HandMotorB=1;
	HandMotorC=1;
	HandMotorD=1;
	this.handChange=true;
}
void HandMotorDownSet(int *array){
	HandMotorA=-255;
	HandMotorB=-255;
	HandMotorC=-255;
	HandMotorD=-255;
	this.handChange=true;
}
/*Reset function*/
//not test yet
void resetFront(int *array){
	BaseFL=0;
	BaseFR=0;
	BaseBL=0;
	BaseBR=0;
	this.motorChange=false;
}
void resetBack(int *array){
	resetFront(array);
}
void resetLeft(int *array){
	resetFront(array);
}
void resetRight(int *array){
	resetFront(array);
}
void resetArmMotorSet(int *array){
	ArmMotorA=0;
	ArmMotorB=0;
	ArmMotorC=0;
	ArmMotorD=0;
	this.armChange=false;
}
void resetHandMotorSet(int *array){
	HandMotorA=0;
	HandMotorB=0;
	HandMotorC=0;
	HandMotorD=0;
	this.handChange=false;
}
void resetspecialSet(int *array){
	BaseFL=array[0];
	BaseFR=array[1];
	BaseBL=array[2];
	BaseBR=array[3];
	this.motorChange=false;
}
task displayInfo(){
	int lastMode=-1;
	int count=0;
	float lastValue=-1;
 //Build the value to be displayed
string mainBattery, backupBattery;
	while(true){
		 switch(count){
		    case 0:
		    {
			    if(lastMode!=mode||mode==4){


						if(mode==0){
								clearLCDLine(0);
						clearLCDLine(1);
							displayLCDString(0, 0, "System Mode:");
							displayLCDString(1, 0, "Car");
						}
						else if(mode==1){
								clearLCDLine(0);
						clearLCDLine(1);
							displayLCDString(0, 0, "System Mode:");
							displayLCDString(1, 0, "Coordinate");
						}
						else if(mode==3){
								clearLCDLine(0);
						clearLCDLine(1);
							displayLCDString(0, 0, "System Mode:");
							displayLCDString(1, 0, "Locked");
						}
						else if(mode ==4||lastValue!=rate){
							clearLCDLine(0);
							clearLCDLine(1);
							displayLCDString(0, 0, "Set value:");
							displayLCDString(1, 0, "SpeedSet");
							string rateS;
							sprintf(rateS, "%5.4f", rate);
							displayNextLCDString(rateS);
							lastValue=rate;
						}
						lastMode=mode;
					}
				}
		    break;
		    case 1:
		    {
		    	lastMode=-1;
			    clearLCDLine(0);
					clearLCDLine(1);
					displayLCDString(0, 0, "Primary: ");
					sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
					displayNextLCDString(mainBattery);
					displayLCDString(1, 0, "Backup: ");
					sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');
					displayNextLCDString(backupBattery);
				}
		    break;
		 }
		if(nLCDButtons == leftButton)
       count=0;
     else if(nLCDButtons == rightButton)
       count=1;
	}
}
int signs[]={1,-1,1,-1};
void baseMove(){
	int lY=vexRT[Ch3]-this.lYError;
	int lX=vexRT[Ch4]-this.lXError;
	int rY=vexRT[Ch2]-this.rYError;
	int rX=vexRT[Ch1]-this.rXError;
	if(vexRT[Btn5D]==1&&vexRT[Btn6D]==1){
		mode=3;
		resetAll();
	}
	while(mode==3){
		if(vexRT[Btn5U]==1&&vexRT[Btn6U]==1){
			mode=0;
			SensorValue[HW]=true
			break;
		}
		else if(vexRT[Btn8D]==1){
			delay(1000);
			if(vexRT[Btn8D]==1){
				mode=4;
			}
		}
		while(mode==4){
			if(vexRT[Btn5U]==1&&vexRT[Btn6U]==1){
				mode=0;
				break;
			}
			else if(vexRT[Btn5D]==1&&vexRT[Btn6D]==1){
				mode=3;
				resetAll();
			}
			else if(vexRT[Btn8L]==1)
				rate=rate+0.000001;
			else if(vexRT[Btn8R]==1)
				rate=rate-0.000001;
		}
	}
	if(mode==0){
		int values[4];
		for(int i=0;i<4;i++){
			values[i]=signs[i]*(lY)+lX;
		}
		specialSetMove(values);

		if(vexRT[Btn7U] == 1)
			preSetFrontMove(NULL);
		else if(vexRT[Btn7D] == 1)
			preSetBackMove(NULL);
		else if(vexRT[Btn7L] == 1)
			preSetLeftMove(NULL);
		else if(vexRT[Btn7R] == 1)
			preSetRightMove(NULL);
		else if(this.motorChange==true)
			resetFront(NULL);
	}
	else if(mode==1){
		if(lY>10)
			preSetFrontMove(NULL);
		else if(lY<-10)
			preSetBackMove(NULL);
		else if(lX>10)
			preSetLeftMove(NULL);
		else if(lX<-10)
			preSetRightMove(NULL);
		else
			resetFront(NULL);

		if(vexRT[Btn7U] == 1)
			preSetFrontMove(NULL);
		else if(vexRT[Btn7D] == 1)
			preSetBackMove(NULL);
		else if(vexRT[Btn7L] == 1)
			preSetLeftTrun(NULL);
		else if(vexRT[Btn7R] == 1)
			preSetRightTrun(NULL);
		else if(this.motorChange==true)
			resetFront(NULL);
	}

	if(vexRT[Btn5U] == 1)
		mode=0;
	else if(vexRT[Btn5D] == 1)
		mode=1;

	if(vexRT[Btn6U] == 1){
		SensorValue[H1]=true;
		SensorValue[H2]=true;
	}
	else{
		SensorValue[H1]=false;
		SensorValue[H2]=false;
	}

	if(vexRT[Btn8D] == 1){
		this.lYError=vexRT[Ch3];
		this.lXError=vexRT[Ch4];
		this.rYError=vexRT[Ch2];
		this.rXError=vexRT[Ch1];
	}

	if(vexRT[Btn6D] == 1){
		ArmMotorA=-1*rY*rate;
		ArmMotorB=rY*rate;
		ArmMotorC=-1*rY*rate;
		ArmMotorD=rY*rate;
	}
	else
		resetArmMotorSet(NULL);
}
void resetAll(){
	resetArmMotorSet(NULL);
	resetFront(NULL);
	resetHandMotorSet(NULL);
}
