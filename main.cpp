#include <cstdio>
#include <stdlib.h>

#include "XID.h"
#include "GRoleBase.h"
#include "mempatch/memory_patch.h"


using namespace memory_patch;

void __attribute__ ((constructor)) module_load(void);
void __attribute__ ((destructor)) module_unload(void);


void MyGainMoney(void * _this, size_t inc)
{
	printf("Money: %d\n",inc);
}


TrampolineHook<void(void*, size_t, bool)> *GainMoneyWithDropPatcher;
void GainMoneyWithDrop(void * _this, size_t inc, bool write_log)
{
	printf("[PLUGIN] GainMoney: received value %d\n",inc);
    inc += 322;
    printf("[PLUGIN] GainMoney: changed value to %d\n", inc);

	GainMoneyWithDropPatcher->CallOriginal(_this, inc, write_log);
}

TrampolineHook<void(void*, XID*)> *OnDuelStartPatcher;
void OnDuelStart(void *_this, XID *target)
{
    printf("[PLUGIN] OnDuelStart: received values %d  %d\n", target->id, target->type);

    OnDuelStartPatcher->CallOriginal(_this, target);
}

TrampolineHook<void(void*,XID*,bool,char)> *DiePatcher;
void Die(void *_this, XID *attacker, bool is_pariah, char attack_mode)
{
    printf("[PLUGIN] Die: received values attacker.id = %d, attacker.type = %d, is_pariah = %d, attack_mode = %c\n", attacker->id, attacker->type, is_pariah, attack_mode);

    DiePatcher->CallOriginal(_this, attacker, is_pariah, attack_mode);
}


TrampolineHook<void(void*, XID*, bool)> *duel_resultParcher;
void duel_result(void *_this, XID* target, bool is_failed)
{
    printf("[PLUGIN] duel_result: received values target.id = %d, target.type = %d, is_failed = %d\n", target->id, target->type, is_failed);
    duel_resultParcher->CallOriginal(_this, target, is_failed);
}

TrampolineHook<void*(GRoleBase*, void*)> *GRoleBase_MarshalPatcher;
void * GRoleBase_Marshal(GRoleBase *_this, void*os)
{
    printf("[PLUGIN] GRoleBase_Marshal: received value id = %d, reserved2 = %d\n", _this->id, _this->reserved2);

    return GRoleBase_MarshalPatcher->CallOriginal(_this, os);
}
void module_load(void)
{
	printf("[PLUGIN] GainMoney: loaded\n");
	DiePatcher = new TrampolineHook<void(void*, XID*, bool, char)>(0x0807D78E, Die);
	duel_resultParcher = new TrampolineHook<void(void*, XID*, bool)>(0x080708A0, duel_result);
    OnDuelStartPatcher = new TrampolineHook<void(void*, XID*)>(0x0811D08A, OnDuelStart);
	GainMoneyWithDropPatcher = new TrampolineHook<void(void*, size_t, bool)>(0x0807CEC8, GainMoneyWithDrop);
    GRoleBase_MarshalPatcher = new TrampolineHook<void*(GRoleBase*, void*)>(0x082E5CC0, GRoleBase_Marshal);
    printf("[PLUGIN] GainMoney: patched\n");
}

void module_unload(void)
{
    delete OnDuelStartPatcher;
    delete GainMoneyWithDropPatcher;
}

