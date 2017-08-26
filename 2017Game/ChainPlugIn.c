#define HEAD 1
#define NODE 2
#define END 0

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

typedef struct _MovementChainUnit{
	struct _MovementChainUnit* last;
	MovementUnit unit
	struct _MovementChainUnit* next;
	int type;
} MovementChainUnit;

MovementChainUnit head;
MovementChainUnit end;
MovementChainUnit* reader;

void initChain(){
	head.last=NULL;
	head.next=&end;
	
	end.last=&head;
	end.next=NULL;
	
	head.type=HEAD;
	end.type=END;
}
void initChainByLength(int length){
	
}