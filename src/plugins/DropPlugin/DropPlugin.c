/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.2663 uuid: 0dd0f212-66eb-4a18-8da6-5e84a5cbc1ed
   from
	DropPlugin VMMaker.oscog-eem.2663 uuid: 0dd0f212-66eb-4a18-8da6-5e84a5cbc1ed
 */
static char __buildInfo[] = "DropPlugin VMMaker.oscog-eem.2663 uuid: 0dd0f212-66eb-4a18-8da6-5e84a5cbc1ed " __DATE__ ;



#include "config.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Default EXPORT macro that does nothing (see comment in sq.h): */
#define EXPORT(returnType) returnType

/* Do not include the entire sq.h file but just those parts needed. */
#include "sqConfig.h"			/* Configuration options */
#include "sqVirtualMachine.h"	/*  The virtual machine proxy definition */
#include "sqPlatformSpecific.h"	/* Platform specific definitions */

#define true 1
#define false 0
#define null 0  /* using 'null' because nil is predefined in Think C */
#ifdef SQUEAK_BUILTIN_PLUGIN
# undef EXPORT
# define EXPORT(returnType) static returnType
#endif

#include "DropPlugin.h"
#include "sqMemoryAccess.h"


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) primitiveDropRequestFileHandle(void);
EXPORT(sqInt) primitiveDropRequestFileName(void);
EXPORT(sqInt) setFileAccessCallback(sqInt address);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);
EXPORT(sqInt) shutdownModule(void);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*classString)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
static sqInt (*methodArgumentCount)(void);
static sqInt (*pop)(sqInt nItems);
static sqInt (*primitiveFail)(void);
static sqInt (*push)(sqInt object);
static sqInt (*stackIntegerValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt classString(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
extern sqInt methodArgumentCount(void);
extern sqInt pop(sqInt nItems);
extern sqInt primitiveFail(void);
extern sqInt push(sqInt object);
extern sqInt stackIntegerValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"DropPlugin VMMaker.oscog-eem.2663 (i)"
#else
	"DropPlugin VMMaker.oscog-eem.2663 (e)"
#endif
;



/*	Note: This is hardcoded so it can be run from Squeak.
	The module name is used for validating a module *after*
	it is loaded to check if it does really contain the module
	we're thinking it contains. This is important! */

	/* InterpreterPlugin>>#getModuleName */
EXPORT(const char*)
getModuleName(void)
{
	return moduleName;
}

	/* DropPlugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	return dropInit();
}


/*	Note: File handle creation needs to be handled by specific support code
	explicitly bypassing the plugin file sand box.
 */

	/* DropPlugin>>#primitiveDropRequestFileHandle */
EXPORT(sqInt)
primitiveDropRequestFileHandle(void)
{
    sqInt dropIndex;
    sqInt handleOop;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFail();
	}
	dropIndex = stackIntegerValue(0);

	/* dropRequestFileHandle needs to return the actual oop returned */
	handleOop = dropRequestFileHandle(dropIndex);
	if (!(failed())) {
		pop(2);
		push(handleOop);
	}
	return 0;
}


/*	Note: File handle creation needs to be handled by specific support code
	explicitly bypassing the plugin file sand box.
 */

	/* DropPlugin>>#primitiveDropRequestFileName */
EXPORT(sqInt)
primitiveDropRequestFileName(void)
{
    sqInt dropIndex;
    char *dropName;
    sqInt i;
    sqInt nameLength;
    sqInt nameOop;
    char *namePtr;

	if (!((methodArgumentCount()) == 1)) {
		return primitiveFail();
	}
	dropIndex = stackIntegerValue(0);

	/* dropRequestFileName returns name or NULL on error */
	dropName = dropRequestFileName(dropIndex);
	if (dropName == null) {
		return primitiveFail();
	}
	nameLength = strlen(dropName);
	nameOop = instantiateClassindexableSize(classString(), nameLength);
	namePtr = firstIndexableField(nameOop);
	for (i = 0; i < nameLength; i += 1) {
		namePtr[i] = (dropName[i]);
	}
	pop(2);
	push(nameOop);
	return 0;
}

	/* DropPlugin>>#setFileAccessCallback: */
EXPORT(sqInt)
setFileAccessCallback(sqInt address)
{
	return sqSecFileAccessCallback(((void *)address));
}


/*	Note: This is coded so that it can be run in Squeak. */

	/* InterpreterPlugin>>#setInterpreter: */
EXPORT(sqInt)
setInterpreter(struct VirtualMachine *anInterpreter)
{
    sqInt ok;


	/* This may seem tautological, but in a real plugin it checks that the VM provides
	   the version the plugin was compiled against which is the version the plugin expects. */
	interpreterProxy = anInterpreter;
	ok = ((interpreterProxy->majorVersion()) == (VM_PROXY_MAJOR))
	 && ((interpreterProxy->minorVersion()) >= (VM_PROXY_MINOR));
	if (ok) {
		
#if !defined(SQUEAK_BUILTIN_PLUGIN)
		classString = interpreterProxy->classString;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
		methodArgumentCount = interpreterProxy->methodArgumentCount;
		pop = interpreterProxy->pop;
		primitiveFail = interpreterProxy->primitiveFail;
		push = interpreterProxy->push;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}

	/* DropPlugin>>#shutdownModule */
EXPORT(sqInt)
shutdownModule(void)
{
	return dropShutdown();
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "DropPlugin";
void* DropPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "initialiseModule", (void*)initialiseModule},
	{(void*)_m, "primitiveDropRequestFileHandle\000\000", (void*)primitiveDropRequestFileHandle},
	{(void*)_m, "primitiveDropRequestFileName\000\000", (void*)primitiveDropRequestFileName},
	{(void*)_m, "setFileAccessCallback", (void*)setFileAccessCallback},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{(void*)_m, "shutdownModule\000\377", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveDropRequestFileHandleAccessorDepth = 0;
signed char primitiveDropRequestFileNameAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
