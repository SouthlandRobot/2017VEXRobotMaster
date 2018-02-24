#define MEMORY_SIZE 4096
#define bool char
#include <stdio.h>
struct _CoreState {
	int memorySize;
	int state;//0 not ready, 1 ready to run, 2 stop by heap full
	int freeMemoryCount;
} coreState;
enum MotorSetting {
	preSetFront = 0, preSetBack = 1,
	preSetLeft = 2, preSetRight = 3,
	ArmMotorSet = 4, HandMotorSet = 5,
	specialSet = 6
};

enum CountingSetting { distance = 0, time = 1, angle = 2 };
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
typedef struct _MovementChainUnit {
	struct _MovementChainUnit* last;
	MovementUnit unit;
	struct _MovementChainUnit* next;
	int type;
} MovementChainUnit;
int heap[MEMORY_SIZE];
char info[MEMORY_SIZE];
void init() {
	for (int i = 0; i<MEMORY_SIZE; i++) {
		heap[i] = 0;
		info[i] = 0;
	}
	coreState.memorySize = MEMORY_SIZE;
	coreState.state = 1;
	coreState.freeMemoryCount = MEMORY_SIZE;
}
int null = -1;
int* malloc(int size) {
	for (int i = 0; i<MEMORY_SIZE; i++) {
		int notEnoughSpacce = 0;
		if (info[i] == 0) {
			if ((i + size)<MEMORY_SIZE) {
				for (int j = 0; j<size; j++) {
					if (info[j + i] != 0)
						notEnoughSpacce = 1;
				}
				if (notEnoughSpacce == 0) {
					for (int j = 0; j<size; j++) {
						info[j + i] = 1;
					}
					return &(heap[i]);
				}
			}
		}
	}
	return &null;
}
void free(int* pointer, int size) {
	for (int i = 0; i<MEMORY_SIZE; i++) {
		if (&(heap[i]) == pointer) {
			for (int j = 0; j<size; j++) {
				heap[i + i] = null;
				info[j + i] = 0;
				
			}
		}
	}
}
void main() {
	init();
	for (int i = 0; i < 100; i++) {
		printf("%p   %d", &(heap[i]), i);
		printf("    %x   \n", info[i]);
	}
	MovementChainUnit* unit = (MovementChainUnit*)malloc(sizeof(MovementChainUnit));
	unit->unit.difference = 4;
	printf("%d\n", unit->unit.difference);
	printf("%p\n", unit);
	for (int i = 0; i < 100; i++) {
		printf("%p   %d", &(heap[i]),i);
		printf("    %x   \n", info[i]);
	}
	free(unit, sizeof(MovementChainUnit));
	for (int i = 0; i < 100; i++) {
		printf("%p   %d", &(heap[i]), i);
		printf("    %x   \n", info[i]);
	}
}












