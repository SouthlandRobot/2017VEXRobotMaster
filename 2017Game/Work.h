#define LineTrackerNumber 6
#define AngleMax 180
#define AngleMin -180
#define distanceMax 100000

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
#define MEMORY_SIZE 4096
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
typedef struct {
	enum MotorSetting motorNumber;
	enum CountingSetting countingSetting;
	int difference;
	bool stayWhenFinish;
	//unit is times
	//From -180 to 180 degree
	//unit is ms
	int specialSet[4];
} MovementUnit;
typedef struct {
	MovementUnit* movement;//May have error
	int length;
} MovementArray;


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
void preSetRightTrun(int *array);
void preSetLeftTrun(int *array);
int encoderCounter();
int timeCounter();
int angleCounter();
/********************************************************/


char heap[MEMORY_SIZE];
char info[MEMORY_SIZE];
int null = -1;
int lastCallEncoderCounter;
int lastCallTimeCounter;
MovementArray* waittingActions;
MovementArray* runningActions;
bool isBusy;
