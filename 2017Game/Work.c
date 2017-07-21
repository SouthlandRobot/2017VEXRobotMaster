#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    HandL,          sensorPotentiometer)
#pragma config(Sensor, in2,    HandR,          sensorPotentiometer)
#pragma config(Sensor, dgtl1,  SonarA,         sensorSONAR_cm)
#pragma config(Sensor, dgtl3,  SonarB,         sensorSONAR_cm)
#pragma config(Sensor, dgtl5,  ExEncoderA,     sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  ExEncoderA,     sensorQuadEncoder)
#pragma config(Sensor, I2C_1,  FL,             sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  FR,             sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  BL,             sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  BR,             sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port1,           HR,            tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           FL,            tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port3,           FR,            tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port4,           BL,            tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port5,           BR,            tmotorVex393_MC29, openLoop, encoderPort, I2C_4)
#pragma config(Motor,  port6,           AA,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           AB,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           AC,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           AD,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          HL,            tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#define LineTrackerNumber 6
#define AngleMax 180
#define AngleMin -180
#define distanceMax 100000

#define EncoderBaseFL getMotorEncoder(FL)
#define EncoderBaseFR getMotorEncoder(FR)
#define EncoderBaseBL getMotorEncoder(BL)
#define EncoderBaseBR getMotorEncoder(BR)

#define BaseFL motor[FL]
#define BaseFR motor[FR]
#define BaseBL motor[BL]
#define BaseBR motor[BR]

#define ArmMotorA motor[AA]
#define ArmMotorB motor[AB]
#define ArmMotorC motor[AC]
#define ArmMotorD motor[AD]

#define HandMotorA motor[HL]
#define HandMotorB motor[HL]
#define HandMotorC motor[HR]
#define HandMotorD motor[HR]

enum MotorSetting{preSetFront=0,preSetBack=1,
	preSetLeft=2,preSetRight=3,
	ArmMotorSet=4,HandMotorSet=5,
	specialSet=6};

enum CountingSetting{distance=0,time=1,angle=2};

typedef struct {
	bool motorChange;
	bool armChange;
	bool handChange;
} RobotState;
RobotState this;

typedef struct{
	MotorSetting motorNumber;
	CountingSetting countingSetting;
	int difference;
	bool stayWhenFinish;
	//unit is times
	//From -180 to 180 degree
	//unit is ms
	int specialSet[4];
} MovementUnit;

typedef struct {
	MovementUnit movement[4];//May have error
	int length;
} MovementArray;


//Mike's part
//not finish


/****************************************************/
MovementArray* createNewMovementArray(int length);//May have error
MovementArray* AddToMovementArray(MovementArray *oldArray,MovementUnit newUnit);//May have error
MovementUnit* removeFromMovementArray(MovementArray *oldArray,int place);
void movement(int movement,int *array);
void resetmovement(int movement,int *array);
bool checkmovement(int movement);
task movementOprator();
void preSetFrontMove(int *array);
void preSetBackMove(int *array);
void preSetLeftMove(int *array);
void preSetRightMove(int *array);
void ArmMotorUpSet(int *array);
void ArmMotorDownSet(int *array);
void HandMotorUpSet(int *array);
void HandMotorDownSet(int *array);
void specialSetMove(int *array);
int encoderCounter();
int timeCounter();
int angleCounter();
/********************************************************/

int encoderCounter(){
	int distance=(EncoderBaseFL+EncoderBaseFR+EncoderBaseBL+EncoderBaseBR)/4;
	return distance;
}
	int lastCallEncoderCounter;

int timeCounter(){
	return nPgmTime;
}
	int lastCallTimeCounter;

int angleCounter(){

}
//not test yet
MovementArray* createNewMovementArray(int length){
	MovementArray newArray;
	MovementUnit array[0];
	memset(array,length,sizeof(MovementUnit));
	if(!array){
		return NULL;
	}
	newArray.movement=array;
	newArray.length=length;
	return &newArray;
}

//not test yet
MovementArray* AddToMovementArray(MovementArray *oldArray,MovementUnit newUnit){
	MovementArray newArray;
	//MovementArray _oldArray=*oldArray;
	newArray.length=oldArray->length;
	MovementUnit array[1];
	memset(array,newArray.length+1,sizeof(MovementUnit));
	if(!array){
		return NULL;
	}
	for(int i=0;i<oldArray->length;i++){
		array[i]=oldArray->movement[i];
	}
	array[newArray.length]=newUnit;
	newArray.movement=array;
	newArray.length=newArray.length+1;
	return &newArray;
}

//not test yet
MovementUnit* removeFromMovementArray(MovementArray *oldArray,int place){
	//MovementArray _oldArray=*oldArray;
	MovementUnit unit;
	unit=oldArray->movement[place];
	MovementUnit array[1];
	memset(array,oldArray->length-1,sizeof(MovementUnit));
	if(!array){
		return NULL;
	}

	for(int i=0;i<place;i++){
		array[i]=oldArray->movement[i];
	}
	for(int i=place+1;i<oldArray->length;i++){
		array[i-1]=oldArray->movement[i];
	}
	oldArray->movement=array;
	oldArray->length=oldArray->length-1;
	return &unit;
}
MovementArray waittingActions;
MovementArray runningActions;
bool isBusy;
task main(){



}

//not test yet

/*Set function*/

//not test yet
void preSetFrontMove(int *array){
	BaseFL=255;
	BaseFR=255;
	BaseBL=255;
	BaseBR=255;
	this.motorChange=true;
}
void preSetBackMove(int *array){
	BaseFL=-255;
	BaseFR=-255;
	BaseBL=-255;
	BaseBR=-255;
	this.motorChange=true;
}
void preSetLeftMove(int *array){
	BaseFL=255;
	BaseFR=255;
	BaseBL=-255;
	BaseBR=-255;
	this.motorChange=true;
}
void preSetRightMove(int *array){
	BaseFL=-255;
	BaseFR=-255;
	BaseBL=255;
	BaseBR=255;
	this.motorChange=true;
}
void ArmMotorUpSet(int *array){
	ArmMotorA=255;
	ArmMotorB=255;
	ArmMotorC=255;
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
	HandMotorA=255;
	HandMotorB=255;
	HandMotorC=255;
	HandMotorD=255;
	this.handChange=true;
}
void HandMotorDownSet(int *array){
	HandMotorA=255;
	HandMotorB=255;
	HandMotorC=255;
	HandMotorD=255;
	this.handChange=true;
}
void specialSetMove(int *array){
	BaseFL=array[0];
	BaseFR=array[1];
	BaseBL=array[2];
	BaseBR=array[3];
	this.motorChange=true;
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
/*check function*/
//not test yet
bool checkMotor(){
	return this.motorChange;
}
bool checkArmMotorSet(){
	return this.armChange;
}
bool checkHandMotorSet(){
	return this.handChange;
}
/********************************************************/
void movement(int movement,int *array){
	switch(movement){
		case 0:
		preSetFrontMove(array);
			break;
		case 1:
		preSetBackMove(array);
			break;
		case 2:
		preSetLeftMove(array);
			break;
		case 3:
		preSetRightMove(array);
			break;
		case 4:
		ArmMotorUpSet(array);
			break;
		case 5:
		ArmMotorDownSet(array);
			break;
		case 6:
		HandMotorUpSet(array);
			break;
		case 7:
		HandMotorDownSet(array);
			break;
		case 8:
		specialSetMove(array);
			break;
	}
}
void resetmovement(int movement,int* array){
	switch(movement){
		case 0:
		resetFront(array);
			break;
		case 1:
		resetBack(array);
			break;
		case 2:
		resetLeft(array);
			break;
		case 3:
		resetRight(array);
			break;
		case 4:
		resetArmMotorSet(array);
			break;
		case 5:
		resetArmMotorSet(array);
			break;
		case 6:
		resetHandMotorSet(array);
			break;
		case 7:
		resetHandMotorSet(array);
			break;
		case 8:
		resetspecialSet(array);
			break;
	}
}
bool checkmovement(int movement){
	bool check=false;
	switch(movement){
		case 0:
		check=checkMotor();
			break;
		case 1:
		check=checkMotor();
			break;
		case 2:
		check=checkMotor();
			break;
		case 3:
		check=checkMotor();
			break;
		case 4:
		check=checkArmMotorSet();
			break;
		case 5:
		check=checkArmMotorSet();
			break;
		case 6:
		check=checkHandMotorSet();
			break;
		case 7:
		check=checkHandMotorSet();
			break;
		case 8:
		check=checkMotor();
			break;
	}
	return check;
}
bool startMovement(MovementUnit unit);
bool startMovement(MovementUnit unit){
	if(checkmovement(unit.motorNumber)){
		movement(unit.motorNumber,unit.specialSet);
		return true;
	}
	return false;
}
void stopMovement(MovementUnit unit);
void stopMovement(MovementUnit unit){
	resetmovement(unit.motorNumber,unit.specialSet);
}
//not test yet
task movementOprator(){
	MovementUnit unit;
	isBusy=true;
	if(waittingActions.length>0){
		unit=*removeFromMovementArray(&waittingActions,0);//error
		if(startMovement(unit)){
			MovementArray newList;
			newList=*AddToMovementArray(&runningActions,unit);
			runningActions=newList;
		}

	}
	isBusy=false;

	int encodeCounterBuff=encoderCounter();
	int encoderDiff=encodeCounterBuff-lastCallEncoderCounter;
	lastCallEncoderCounter=encodeCounterBuff;

	int timeCounterBuff=timeCounter();
	int timeCounterDiff=timeCounterBuff-lastCallTimeCounter;
	lastCallTimeCounter=timeCounterBuff;

	int angleCounterBuff=angleCounter();

	int diffArray[3];
	diffArray[0]=encoderDiff;
	diffArray[1]=timeCounterDiff;
	diffArray[2]=angleCounterBuff;

	for(int i=0;i<runningActions.length;i++){
		runningActions.movement[i].difference=runningActions.movement[i].difference-
												diffArray[runningActions.movement[i].countingSetting];
		if(runningActions.movement[i].difference<=0){
			if(!runningActions.movement[i].stayWhenFinish)
				stopMovement(runningActions.movement[i]);
			removeFromMovementArray(&runningActions,i);
		}
	}
}

task userRecorder(){
	MovementUnit unit;
		if(runningActions.movement[i].movement>0){
			unit=recordFromRemoteData(&runningActions,units);
			if(runningActions.movement[i].movement<=0){
				unit=recordFromRemoteData(&runningActions,units);
				stopRecorder(runningActions.movement[i]);
			}
		}
}
