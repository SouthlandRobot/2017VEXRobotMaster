#define MEMORY_SIZE 40960
#define HEAP_NULL null
struct _CoreState{
	int memorySize;
	int state;//0 not ready, 1 ready to run, 2 stop by heap full
	int freeMemoryCount;
} coreState
enum MotorSetting{preSetFront=0,preSetBack=1,
	preSetLeft=2,preSetRight=3,
	ArmMotorSet=4,HandMotorSet=5,
	specialSet=6};

enum CountingSetting{distance=0,time=1,angle=2};
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

typedef struct _MemoryUnit{
	MovementUnit data;
	int state;//0 not be used, 1 is using, 2 ready to free
} MemoryUnit;
MemoryUnit null;

typedef struct _MemoryArray{
	int size;
	int location;
} MemoryArray;

MemoryUnit heap[MEMORY_SIZE];
void init();
void set(MemoryArray* units,MovementUnit unit,int location);
int malloc(MemoryArray* unit,int size);
int free(MemoryArray* unit);
void recomputingMemorySize();
void init(){
	coreState.
	null.state=0;
	null.location=-1;
	MovementUnit data;
	data.motorNumber=preSetFront;
	data.countingSetting=distance;
	data.difference=0;
	data.stayWhenFinish=0;
	data.specialSet=NULL
	null.data=data;
	for(int i=0;i<MEMORY_SIZE;i++){
		heap[i]=null;
	}
	coreState.memorySize=MEMORY_SIZE;
	coreState.state=1;
	coreState.freeMemoryCount=MEMORY_SIZE;
}
MovementUnit get(MemoryArray* unit,int location){
	int pointer=unit->location+location;
	return heap[pointer].data;
}
void set(MemoryArray* units,MovementUnit unit,int location){
	int pointer=units->location+location;
	heap[pointer].data=unit;
}
int malloc(MemoryArray* unit,int size){
	while(coreState.state==0){
		init();
	}
	for(int i=0;i<MEMORY_SIZE;i++){
		int notEnoughSpacce=0;
		if((i+size)<MEMORY_SIZE){
			for(int j=0;j<size;j++){
				if(heap[j+i].state!=0)
					notEnoughSpacce=1;
			}
			if(notEnoughSpacce==0){
				for(int j=0;j<size;j++){
					heap[j+i].state=1;
					heap[j+i].location=j+i;
				}
				unit->location=i;
				unit->size=size;
				return notEnoughSpacce;
			}
		}
	}
	return 1;
}
int free(MemoryArray* unit){// clean memory by replacing data to null
	int location=unit->pointer->location;
	int size=unit->size;
	if(location+size<MEMORY_SIZE){
		for(int j=0;j<size;j++){
			heap[j+location]=null;
		}
	}
}
void recomputingMemorySize(){
	int count=0;
	for(int i=0;i<MEMORY_SIZE;i++){
		if(heap[i].state==0)count++;
	}
	coreState.freeMemoryCount=count;
}

void main(){
	MemoryArray unit;
	printf("%d",malloc(&unit,1));
	MovementUnit a;
	a.difference=123123;
	set(&unit,a,0);
	printf("%d",get(&unit,0).difference);
}
















	