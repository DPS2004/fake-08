#include "stdio.h"
#include <cstdlib>
#include <string.h>
#include <math.h>

#include <string>


#include "vm.h"
#include "logger.h"
#include "host.h"
#include "hostVmShared.h"

#include "pdnewlib.h"

extern "C"
{
#include "pd_api.h"
}



volatile int order = 1;
int next2(void);
int next(void) {return order++;}


namespace
{
    int O_ST = order++;
    int O_INITSEC = 0;
    int O_CONSTRUC = 0;
    int O_STATICCON = 0;
    int O_MAIN = 0;
}

__attribute__((constructor))
void T2()
{
    O_CONSTRUC = next();
}

struct A {
    A()
    {
        O_STATICCON = next();
    }
} _;

int _main();

int* a = (int*)malloc(sizeof(int));
int* b = new int;



int	updateLoop(void* userdata) {
	//presumably, a lot of code goes here.
	return 1;
}

extern "C"
int eventHandler(PlaydateAPI* playdate, PDSystemEvent event, uint32_t arg)
{
    eventHandler_pdnewlib(playdate, event, arg);
    
    if (event == kEventInit)
    {
		
		playdate->system->setUpdateCallback(updateLoop, 0);
		
		#define print playdate->system->logToConsole
        #define printO(X) print(#X ": %d\n", X)
        print("notLUA_INIT\n");
        printO(O_ST);
        printO(O_INITSEC);
        printO(O_CONSTRUC);
        printO(O_STATICCON);
        printO(O_MAIN);
        
        printf("printf test\n");
        
        
        print("DONE!\n");
		
		Logger_Initialize_Playdate(playdate);
		
		Logger_Write("logger writing test \n");
		
		Host *host = new Host();
		Logger_Write("Made playdate host \n");
		
		PicoRam *memory = new PicoRam();
		Logger_Write("Made picoram \n");
		
		Audio *audio = new Audio(memory);
		Logger_Write("Made audio \n");
		
		Vm *vm = new Vm(host, memory, nullptr, nullptr, audio);
		Logger_Write("Made vm \n");
		
		host->setUpPaletteColors();
		host->oneTimeSetup(audio);
		Logger_Write("host setup done \n");
		
		vm->SetCartList(host->listcarts());
		Logger_Write("set cart list \n");
		
		bool loadCart = false;
		char* cart;
		
		Logger_Write("Loading Bios cart\n");
		if (loadCart){
			vm->LoadCart(cart);
		}
		else {
			vm->LoadBiosCart();
		}
		Logger_Write("Bios Cart Loaded\n");
		
    }
    
    return 0;
}