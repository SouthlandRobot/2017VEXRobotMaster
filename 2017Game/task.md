## Program structure
	- Programer fill out one MovementUnit and add to waittingActions
	- Running service will get MovementUnit that in the waittingActions and start to run the movement
	- Running service will also detect running movement that in the list runningActions, and stop it when it finish.
***
## Task list
1. read VEX API in <http://www.robotc.net/wikiarchive/VEX>.
2. build a Recorder that can record user action when user control the robotc.
```C
Task userRecoder();
```
3. for each function, write a test function.
	- ex: ```C string test_UserRecoder(); ```
test2
