#include <cstdio>
#include <stdlib.h>
#include <sys/ptrace.h>

#include <unistd.h>
//#include "BeaEngine.h"

#include "memory_patch/memory_patch.h"

//#include "Memory.h"

using namespace memory_patch;
void __attribute__ ((constructor)) module_load(void);
void __attribute__ ((destructor)) module_unload(void);


void MyGainMoney(void * _this, size_t inc)
{
	printf("Money: %d\n",inc);
}
void MyGainMoneyWithDrop(void * _this, size_t inc, bool write_log)
{
	printf("MoneyWithDrop: %d\n",inc);
}

void module_load(void)
{
	unsetenv("LD_PRELOAD");
	printf("UnsetEnv: LD_PRELOAD\n");	
// pointer 0x34FF2

	printf("pid: %d\n", getpid());

	//DISASM disasm;

	//ptrace(PTRACE_PICKDATA, 0, 0x34FF2, 0);

    printf("hello from .so!\n");

	//memory_patch::CallHook<void(void*, size_t)> patcher1(0x0807CFF2, MyGainMoney);
	CallHook<void(void*, size_t, bool)> patcher(0x0807CEC8, MyGainMoneyWithDrop);
}

void module_unload(void)
{
}


//build: g++ -fPIC *.cpp -m32 -Llibs/libBeaEngine.a -ldl -shared -o gain_money.so
