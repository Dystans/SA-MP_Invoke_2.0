#include "include\Invoke\Invoke.hxx"

typedef void (*logprintf_t) (char* format, ...);
logprintf_t logprintf;
void ** ppPluginData;
extern void * pAMXFunctions;

cell AMX_NATIVE_CALL Testing(AMX* amx, cell* params) {
	float
		x = NULL,
		y = NULL,
		z = NULL;

	//Get the player's position (and check to see if he is even connected).
	if(Invoke_Call -> Call_Native(&INVOKE::GetPlayerPos, params[1], &x, &y, &z)) {
		char name[24];

		//Get the rest of the player's information (name, interior, and virtualworld) and print it.
		Invoke_Call -> Call_Native(&INVOKE::GetPlayerName, params[1], name);
		int interior = Invoke_Call -> Call_Native(&INVOKE::GetPlayerInterior, params[1]);
		int virtualworld = Invoke_Call -> Call_Native(&INVOKE::GetPlayerVirtualWorld, params[1]);

		logprintf("%s is at X: %.2f, Y: %.2f, Z: %.2f (Virtual world: %d, Interior %d).", name, x, y, z, virtualworld, interior);
		return 1;

	}
	return 0;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) {
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	logprintf = (logprintf_t) ppData[PLUGIN_DATA_LOGPRINTF];
	return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
}

static cell AMX_NATIVE_CALL Test(AMX * amx, cell * params) {
	logprintf("Test");
	return true;
}

AMX_NATIVE_INFO projectNatives[] = {
	{"Test", Test},
};


PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
	return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx) {
	return amx_Register(amx, projectNatives, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx) {
	return AMX_ERR_NONE;
}