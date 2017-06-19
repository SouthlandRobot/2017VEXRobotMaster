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
#### MovementArray* createNewMovementArray(int length)
- Discription: create a array by given length
- Parameter: lengths
***
#### MovementArray* AddToMovementArray(MovementArray *oldArray,MovementUnit newUnit);
- Discription:
- Parameter:
***
#### MovementUnit* removeFromMovementArray(MovementArray *oldArray,int place)
- Discription:remove a unit form a movement array
- Parameter: 
	1. oldArray: the pointer of the array that need to remove unit
	2. place: the position of the unit that will be remove 
***
#### void movement(int movement,int *array);
- Discription: the function that use to start movement
- Parameter:
	1. movement: the movement code that build in
	2. array: an array that cantain settings of each motor(length is four)
***
#### void resetmovement(int movement,int *array);
- Discription: this function that will reset the motor to stop movement
- Parameter:
	1. movement: the movement code that build in
	2. array: an array that cantain settings of each motor(length is four)
***
#### bool checkmovement(int movement);
- Discription: this function that use to check is any running movement that is running
- Parameter: 
	1. movement: the movement code that build in
***
#### task movementOprator();
- Discription: the background thread that control all the movement in the robot
- Parameter: N/A
***
#### void preSetFrontMove(int *array);
- Discription: this function is a preset movement that move robot forward
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### void preSetBackMove(int *array);
- Discription: this function is a preset movement that move robot backward
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### void preSetLeftMove(int *array);
- Discription: this function is a preset movement that move robot left
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### void preSetRightMove(int *array);
- Discription: this function is a preset movement that move robot right
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### void ArmMotorUpSet(int *array);
- Discription: this function is a preset movement that move robot arm up
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### void ArmMotorDownSet(int *array);
- Discription: this function is a preset movement that move robot arm down
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### void HandMotorUpSet(int *array);
- Discription: this function is a preset movement that close robot's hand 
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### void HandMotorDownSet(int *array);
- Discription: this function is a preset movement that open robot's hand 
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### void specialSetMove(int *array);
- Discription: this function is a cumstmorize movement
- Parameter:
	1. array: an array that cantain settings of each motor(length is four)
***
#### int encoderCounter();
- Discription: this function read the encoder in the base motor and output an average number
- Parameter: N/A
***
#### int timeCounter();
- Discription: this function read the timer that build in and output the time since the program start running
- Parameter: N/A
***
#### int angleCounter();
- Discription: this function read the angle senser that in the arm and output the current angle the arm have
- Parameter: N/A
***
#### void stopMovement(MovementUnit unit);
- Discription: this function is use to stop the movementUnit that put in
- Parameter:
	1. unit: the movementUnit what will stop running
***
#### bool startMovement(MovementUnit unit);
- Discription: this function is use to start the movementUnit that put in
- Parameter:
	1. unit: the movementUnit what will start running
***























