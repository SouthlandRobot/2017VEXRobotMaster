## Function view list
* [MovementArray* createNewMovementArray(int length)](#createNewMovementArray)
* [MovementArray* AddToMovementArray(MovementArray *oldArray,MovementUnit newUnit)](#AddToMovementArray)
* [MovementUnit* removeFromMovementArray(MovementArray *oldArray,int place)](#removeFromMovementArray)
* [void movement(int movement,int *array)](#movement)
* [void resetmovement(int movement,int *array)](#resetmovement)

* [void preSetFrontMove(int *array)](#preSetFrontMove)
* [void preSetBackMove(int *array)](#preSetBackMove)
* [void preSetLeftMove(int *array)](#preSetLeftMove)
* [void preSetRightMove(int *array)](#preSetRightMove)
* [void ArmMotorUpSet(int *array)](ArmMotorUpSet)
* [void ArmMotorDownSet(int *array)](#ArmMotorDownSet)
* [void HandMotorUpSet(int *array)](#HandMotorUpSet)
* [void HandMotorDownSet(int *array)](#HandMotorDownSet)
* [void specialSetMove(int *array)](#specialSetMove)
* [int encoderCounter()](#encoderCounter)
* [int timeCounter()](#timeCounter)
* [int angleCounter()](#angleCounter)
* [void stopMovement(MovementUnit unit)](#stopMovement)
* [bool startMovement(MovementUnit unit)](#startMovement)
***
#### <a name="createNewMovementArray"></a> MovementArray* createNewMovementArray(int length)
- Discription: create a array by given length
- Parameter: lengths
***
#### <a name="AddToMovementArray"></a> MovementArray* AddToMovementArray(MovementArray *oldArray,MovementUnit newUnit);
- Discription: add a movement unit to a array
- Parameter: 
	1. *oldArray the array that will put unit in
	2. newUnit the unit that will put in to a array.
***
#### <a name="removeFromMovementArray"></a> MovementUnit* removeFromMovementArray(MovementArray *oldArray,int place)
- Discription:remove a unit form a movement array
- Parameter: 
	1. oldArray: the pointer of the array that need to remove unit
	2. place: the position of the unit that will be remove 
***
#### <a name="movement"></a> void movement(int movement,int *array);
- Discription: the function that use to start movement
- Parameter:
	1. movement: the movement code that build in
	2. array: an array that cantain settings of each motor(length is four)
***
#### <a name="resetmovement"></a> void resetmovement(int movement,int *array);
- Discription: this function that will reset the motor to stop movement
- Parameter:
	1. movement: the movement code that build in
	2. array: an array that cantain settings of each motor(length is four)
***
#### <a name="checkmovement"></a> bool checkmovement(int movement);
- Discription: this function that use to check is any running movement that is running
- Parameter: 
	1. movement: the movement code that build in
***
#### <a name="movementOprator"></a> task movementOprator();
- Discription: the background thread that control all the movement in the robot
- Parameter: N/A
***
#### <a name="preSetFrontMove"></a> void preSetFrontMove(int *array);
- Discription: this function is a preset movement that move robot forward
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### <a name="preSetBackMove"></a> void preSetBackMove(int *array);
- Discription: this function is a preset movement that move robot backward
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### <a name="preSetLeftMove"></a> void preSetLeftMove(int *array);
- Discription: this function is a preset movement that move robot left
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### <a name="preSetRightMove"></a> void preSetRightMove(int *array);
- Discription: this function is a preset movement that move robot right
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### <a name="ArmMotorUpSet"></a> void ArmMotorUpSet(int *array);
- Discription: this function is a preset movement that move robot arm up
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### <a name="ArmMotorDownSet"></a> void ArmMotorDownSet(int *array);
- Discription: this function is a preset movement that move robot arm down
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### <a name="HandMotorUpSet"></a> void HandMotorUpSet(int *array);
- Discription: this function is a preset movement that close robot's hand 
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### <a name="HandMotorDownSet"></a> void HandMotorDownSet(int *array);
- Discription: this function is a preset movement that open robot's hand 
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### <a name="specialSetMove"></a> void specialSetMove(int *array);
- Discription: this function is a cumstmorize movement
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### <a name="encoderCounter"></a> int encoderCounter();
- Discription: this function read the encoder in the base motor and output an average number
- Parameter: N/A
***
#### <a name="timeCounter"></a> int timeCounter();
- Discription: this function read the timer that build in and output the time since the program start running
- Parameter: N/A
***
#### <a name="angleCounter"></a> int angleCounter();
- Discription: this function read the angle senser that in the arm and output the current angle the arm have
- Parameter: N/A
***
#### <a name="stopMovement"></a> void stopMovement(MovementUnit unit);
- Discription: this function is use to stop the movementUnit that put in
- Parameter:
	1. unit: the movementUnit what will stop running
***
#### <a name="startMovement"></a> bool startMovement(MovementUnit unit);
- Discription: this function is use to start the movementUnit that put in
- Parameter:
	1. unit: the movementUnit what will start running
***























