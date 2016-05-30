//Zork Tribute game
//Author: Joan Pareja Piñol 
//Github: https://github.com/Yulna/Zork-Tribute

//#include "MemLeaks.h"
#include "World.h"



World* NewWorld = nullptr;

int main(){
	//ReportMemoryLeaks();


	NewWorld = new World();


	while (NewWorld->Game_on()){
	};



	return 0;
}