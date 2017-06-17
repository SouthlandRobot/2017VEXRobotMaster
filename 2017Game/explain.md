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
	1. movement:
***
#### void resetmovement(int movement,int *array);
- Discription:
- Parameter:
***
#### bool checkmovement(int movement);
- Discription:
- Parameter:
***
#### task movementOprator();
- Discription:
- Parameter:
***
#### void preSetFrontMove(int *array);
- Discription:
- Parameter:
***
#### void preSetBackMove(int *array);
- Discription:
- Parameter:
***
#### void preSetLeftMove(int *array);
- Discription:
- Parameter:
***
#### void preSetRightMove(int *array);
- Discription:
- Parameter:
***
#### void ArmMotorUpSet(int *array);
- Discription:
- Parameter:
***
#### void ArmMotorDownSet(int *array);
- Discription:
- Parameter:
***
#### void HandMotorUpSet(int *array);
- Discription:
- Parameter:
***
#### void HandMotorDownSet(int *array);
- Discription:
- Parameter:
***
#### void specialSetMove(int *array);
- Discription:
- Parameter:
***
#### int encoderCounter();
- Discription:
- Parameter:
***
#### int timeCounter();
- Discription:
- Parameter:
***
#### int angleCounter();
- Discription:
- Parameter:
***
#### void stopMovement(MovementUnit unit);
- Discription:
- Parameter:
***
#### bool startMovement(MovementUnit unit);
- Discription:
- Parameter:
***























