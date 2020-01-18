/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.2663 uuid: 0dd0f212-66eb-4a18-8da6-5e84a5cbc1ed
   from
	AsynchFilePlugin VMMaker.oscog-eem.2663 uuid: 0dd0f212-66eb-4a18-8da6-5e84a5cbc1ed
 */
static char __buildInfo[] = "AsynchFilePlugin VMMaker.oscog-eem.2663 uuid: 0dd0f212-66eb-4a18-8da6-5e84a5cbc1ed " __DATE__ ;



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

#include "AsynchFilePlugin.h"
#include "sqMemoryAccess.h"


/*** Constants ***/
#define PrimErrBadArgument 3


/*** Function Prototypes ***/
static AsyncFile * asyncFileValueOf(sqInt oop);
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) initialiseModule(void);
EXPORT(sqInt) moduleUnloaded(char *aModuleName);
EXPORT(sqInt) primitiveAsyncFileClose(void);
EXPORT(sqInt) primitiveAsyncFileOpen(void);
EXPORT(sqInt) primitiveAsyncFileReadResult(void);
EXPORT(sqInt) primitiveAsyncFileReadStart(void);
EXPORT(sqInt) primitiveAsyncFileWriteResult(void);
EXPORT(sqInt) primitiveAsyncFileWriteStart(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);
EXPORT(sqInt) shutdownModule(void);
static sqInt sqAssert(sqInt aBool);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static sqInt (*booleanValueOf)(sqInt obj);
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classByteArray)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
#if !defined(integerObjectOf)
static sqInt (*integerObjectOf)(sqInt value);
#endif
#if !defined(integerValueOf)
static sqInt (*integerValueOf)(sqInt oop);
#endif
static void * (*ioLoadFunctionFrom)(char *functionName, char *moduleName);
static sqInt (*isBooleanObject)(sqInt oop);
static sqInt (*isBytes)(sqInt oop);
#if !defined(isIntegerObject)
static sqInt (*isIntegerObject)(sqInt objectPointer);
#endif
static sqInt (*isWords)(sqInt oop);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*primitiveFail)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*slotSizeOf)(sqInt oop);
static sqInt (*stackValue)(sqInt offset);
static sqInt (*success)(sqInt aBoolean);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern sqInt booleanValueOf(sqInt obj);
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classByteArray(void);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
#if !defined(integerObjectOf)
extern sqInt integerObjectOf(sqInt value);
#endif
#if !defined(integerValueOf)
extern sqInt integerValueOf(sqInt oop);
#endif
extern void * ioLoadFunctionFrom(char *functionName, char *moduleName);
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 15)
extern sqInt isBooleanObject(sqInt oop);
#else
# define isBooleanObject(oop) 0
#endif
extern sqInt isBytes(sqInt oop);
#if !defined(isIntegerObject)
extern sqInt isIntegerObject(sqInt objectPointer);
#endif
extern sqInt isWords(sqInt oop);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt primitiveFail(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt slotSizeOf(sqInt oop);
extern sqInt stackValue(sqInt offset);
extern sqInt success(sqInt aBoolean);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"AsynchFilePlugin VMMaker.oscog-eem.2663 (i)"
#else
	"AsynchFilePlugin VMMaker.oscog-eem.2663 (e)"
#endif
;
static void * sCOAFfn;



/*	Answer a pointer to the first byte of the async file record within the
	given Smalltalk bytes object, or fail and answer nil if oop is not an
	async file record. */

	/* AsynchFilePlugin>>#asyncFileValueOf: */
static AsyncFile *
asyncFileValueOf(sqInt oop)
{
	if ((isBytes(oop))
	 && ((byteSizeOf(oop)) == (sizeof(AsyncFile)))) {
		return ((AsyncFile *) (firstIndexableField(oop)));
	}
	primitiveFailFor(PrimErrBadArgument);
	return null;
}


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


/*	Initialise the module */

	/* AsynchFilePlugin>>#initialiseModule */
EXPORT(sqInt)
initialiseModule(void)
{
	sCOAFfn = ioLoadFunctionFrom("secCanOpenAsyncFileOfSizeWritable", "SecurityPlugin");
	return asyncFileInit();
}


/*	The module with the given name was just unloaded. 
	Make sure we have no dangling references. */

	/* AsynchFilePlugin>>#moduleUnloaded: */
EXPORT(sqInt)
moduleUnloaded(char *aModuleName)
{
	if ((strcmp(aModuleName, "SecurityPlugin")) == 0) {

		/* The security plugin just shut down. How odd. Zero the function pointer we have into it */
		sCOAFfn = 0;
	}
	return 0;
}

	/* AsynchFilePlugin>>#primitiveAsyncFileClose: */
EXPORT(sqInt)
primitiveAsyncFileClose(void)
{
	AsyncFile *f;
	sqInt fh;

	fh = stackValue(0);
	if (failed()) {
		return null;
	}
	/* begin asyncFileValueOf: */
	if ((isBytes(fh))
	 && ((byteSizeOf(fh)) == (sizeof(AsyncFile)))) {
		f = ((AsyncFile *) (firstIndexableField(fh)));
		goto l1;
	}
	primitiveFailFor(PrimErrBadArgument);
	f = null;
	l1:	/* end asyncFileValueOf: */;
	if (failed()) {
		return null;
	}
	asyncFileClose(f);
	if (!(failed())) {
		pop(1);
	}
	return null;
}

	/* AsynchFilePlugin>>#primitiveAsyncFileOpen:forWrite:semaIndex: */
EXPORT(sqInt)
primitiveAsyncFileOpen(void)
{
	AsyncFile *f;
	char *fileName;
	sqInt fileNameSize;
	sqInt fOop;
	sqInt okToOpen;
	sqInt semaIndex;
	sqInt writeFlag;

	if (!((isBytes(stackValue(2)))
		 && ((isBooleanObject(stackValue(1)))
		 && (isIntegerObject((semaIndex = stackValue(0))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	fileName = ((char *) (firstIndexableField(stackValue(2))));
	writeFlag = booleanValueOf(stackValue(1));
	semaIndex = integerValueOf(semaIndex);
	if (failed()) {
		return null;
	}

	/* If the security plugin can be loaded, use it to check for permission.
	   If not, assume it's ok */
	fileNameSize = byteSizeOf(((sqInt)((fileName) - BaseHeaderSize)));
	if (sCOAFfn != 0) {
		okToOpen = ((sqInt (*) (char *, sqInt, sqInt)) sCOAFfn)(fileName, fileNameSize, writeFlag);
		if (!okToOpen) {
			return primitiveFail();
		}
	}
	fOop = instantiateClassindexableSize(classByteArray(), sizeof(AsyncFile));
	/* begin asyncFileValueOf: */
	if ((isBytes(fOop))
	 && ((byteSizeOf(fOop)) == (sizeof(AsyncFile)))) {
		f = ((AsyncFile *) (firstIndexableField(fOop)));
		goto l1;
	}
	primitiveFailFor(PrimErrBadArgument);
	f = null;
	l1:	/* end asyncFileValueOf: */;
	if (!(failed())) {
		asyncFileOpen(f, fileName, fileNameSize, writeFlag, semaIndex);
	}
	if (!(failed())) {
		popthenPush(4, fOop);
	}
	return null;
}

	/* AsynchFilePlugin>>#primitiveAsyncFileReadResult:intoBuffer:at:count: */
EXPORT(sqInt)
primitiveAsyncFileReadResult(void)
{
	sqInt buffer;
	sqInt bufferPtr;
	sqInt bufferSize;
	sqInt count;
	AsyncFile *f;
	sqInt fhandle;
	sqInt num;
	sqInt r;
	sqInt start;
	sqInt startIndex;
	sqInt _return_value;

	if (!((isIntegerObject((start = stackValue(1))))
		 && (isIntegerObject((num = stackValue(0)))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	fhandle = stackValue(3);
	buffer = stackValue(2);
	start = integerValueOf(start);
	num = integerValueOf(num);
	if (failed()) {
		return null;
	}
	/* begin asyncFileValueOf: */
	if ((isBytes(fhandle))
	 && ((byteSizeOf(fhandle)) == (sizeof(AsyncFile)))) {
		f = ((AsyncFile *) (firstIndexableField(fhandle)));
		goto l1;
	}
	primitiveFailFor(PrimErrBadArgument);
	f = null;
	l1:	/* end asyncFileValueOf: */;
	count = num;
	startIndex = start;

	/* in bytes or words */
	bufferSize = slotSizeOf(buffer);
	if (isWords(buffer)) {

		/* covert word counts to byte counts */
		count = count * 4;
		startIndex = ((startIndex - 1) * 4) + 1;
		bufferSize = bufferSize * 4;
	}
	success((startIndex >= 1)
	 && (((startIndex + count) - 1) <= bufferSize));
	if (failed()) {
		return null;
	}
	bufferPtr = ((((sqInt) (firstIndexableField(buffer)))) + startIndex) - 1;
	r = asyncFileReadResult(f, ((void *)bufferPtr), count);
	if (!(failed())) {
		_return_value = integerObjectOf(r);
		if (!(failed())) {
			popthenPush(5, _return_value);
		}
	}
	return null;
}

	/* AsynchFilePlugin>>#primitiveAsyncFileReadStart:fPosition:count: */
EXPORT(sqInt)
primitiveAsyncFileReadStart(void)
{
	sqInt count;
	AsyncFile *f;
	sqInt fHandle;
	sqInt fPosition;

	if (!((isIntegerObject((fPosition = stackValue(1))))
		 && (isIntegerObject((count = stackValue(0)))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	fHandle = stackValue(2);
	fPosition = integerValueOf(fPosition);
	count = integerValueOf(count);
	if (failed()) {
		return null;
	}
	/* begin asyncFileValueOf: */
	if ((isBytes(fHandle))
	 && ((byteSizeOf(fHandle)) == (sizeof(AsyncFile)))) {
		f = ((AsyncFile *) (firstIndexableField(fHandle)));
		goto l1;
	}
	primitiveFailFor(PrimErrBadArgument);
	f = null;
	l1:	/* end asyncFileValueOf: */;
	if (failed()) {
		return null;
	}
	asyncFileReadStart(f, fPosition, count);
	if (!(failed())) {
		pop(3);
	}
	return null;
}

	/* AsynchFilePlugin>>#primitiveAsyncFileWriteResult: */
EXPORT(sqInt)
primitiveAsyncFileWriteResult(void)
{
	AsyncFile *f;
	sqInt fHandle;
	sqInt r;
	sqInt _return_value;

	fHandle = stackValue(0);
	if (failed()) {
		return null;
	}
	/* begin asyncFileValueOf: */
	if ((isBytes(fHandle))
	 && ((byteSizeOf(fHandle)) == (sizeof(AsyncFile)))) {
		f = ((AsyncFile *) (firstIndexableField(fHandle)));
		goto l1;
	}
	primitiveFailFor(PrimErrBadArgument);
	f = null;
	l1:	/* end asyncFileValueOf: */;
	if (failed()) {
		return null;
	}
	r = asyncFileWriteResult(f);
	if (!(failed())) {
		_return_value = integerObjectOf(r);
		if (!(failed())) {
			popthenPush(2, _return_value);
		}
	}
	return null;
}

	/* AsynchFilePlugin>>#primitiveAsyncFileWriteStart:fPosition:fromBuffer:at:count: */
EXPORT(sqInt)
primitiveAsyncFileWriteStart(void)
{
	sqInt buffer;
	sqInt bufferPtr;
	sqInt bufferSize;
	sqInt count;
	AsyncFile *f;
	sqInt fHandle;
	sqInt fPosition;
	sqInt num;
	sqInt start;
	sqInt startIndex;

	if (!((isIntegerObject((fPosition = stackValue(3))))
		 && ((isIntegerObject((start = stackValue(1))))
		 && (isIntegerObject((num = stackValue(0))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	fHandle = stackValue(4);
	fPosition = integerValueOf(fPosition);
	buffer = stackValue(2);
	start = integerValueOf(start);
	num = integerValueOf(num);
	if (failed()) {
		return null;
	}
	/* begin asyncFileValueOf: */
	if ((isBytes(fHandle))
	 && ((byteSizeOf(fHandle)) == (sizeof(AsyncFile)))) {
		f = ((AsyncFile *) (firstIndexableField(fHandle)));
		goto l1;
	}
	primitiveFailFor(PrimErrBadArgument);
	f = null;
	l1:	/* end asyncFileValueOf: */;
	count = num;
	startIndex = start;

	/* in bytes or words */
	bufferSize = slotSizeOf(buffer);
	if (isWords(buffer)) {

		/* covert word counts to byte counts */
		count = count * 4;
		startIndex = ((startIndex - 1) * 4) + 1;
		bufferSize = bufferSize * 4;
	}
	success((startIndex >= 1)
	 && (((startIndex + count) - 1) <= bufferSize));
	if (failed()) {
		return null;
	}
	bufferPtr = ((((sqInt) (firstIndexableField(buffer)))) + startIndex) - 1;
	asyncFileWriteStart(f, fPosition, ((void *)bufferPtr), count);
	if (!(failed())) {
		pop(5);
	}
	return null;
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
		booleanValueOf = interpreterProxy->booleanValueOf;
		byteSizeOf = interpreterProxy->byteSizeOf;
		classByteArray = interpreterProxy->classByteArray;
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
#if !defined(integerObjectOf)
		integerObjectOf = interpreterProxy->integerObjectOf;
#endif
#if !defined(integerValueOf)
		integerValueOf = interpreterProxy->integerValueOf;
#endif
		ioLoadFunctionFrom = interpreterProxy->ioLoadFunctionFrom;
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 15)
		isBooleanObject = interpreterProxy->isBooleanObject;
#else
#if !defined(isBooleanObject)
		isBooleanObject = 0;
#endif
#endif
		isBytes = interpreterProxy->isBytes;
#if !defined(isIntegerObject)
		isIntegerObject = interpreterProxy->isIntegerObject;
#endif
		isWords = interpreterProxy->isWords;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		primitiveFail = interpreterProxy->primitiveFail;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		slotSizeOf = interpreterProxy->slotSizeOf;
		stackValue = interpreterProxy->stackValue;
		success = interpreterProxy->success;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


/*	Initialise the module */

	/* AsynchFilePlugin>>#shutdownModule */
EXPORT(sqInt)
shutdownModule(void)
{
	return asyncFileShutdown();
}

	/* SmartSyntaxInterpreterPlugin>>#sqAssert: */
static sqInt
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
	return aBool;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "AsynchFilePlugin";
void* AsynchFilePlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "initialiseModule", (void*)initialiseModule},
	{(void*)_m, "moduleUnloaded", (void*)moduleUnloaded},
	{(void*)_m, "primitiveAsyncFileClose\000\000", (void*)primitiveAsyncFileClose},
	{(void*)_m, "primitiveAsyncFileOpen\000\000", (void*)primitiveAsyncFileOpen},
	{(void*)_m, "primitiveAsyncFileReadResult\000\000", (void*)primitiveAsyncFileReadResult},
	{(void*)_m, "primitiveAsyncFileReadStart\000\000", (void*)primitiveAsyncFileReadStart},
	{(void*)_m, "primitiveAsyncFileWriteResult\000\000", (void*)primitiveAsyncFileWriteResult},
	{(void*)_m, "primitiveAsyncFileWriteStart\000\000", (void*)primitiveAsyncFileWriteStart},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{(void*)_m, "shutdownModule\000\377", (void*)shutdownModule},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveAsyncFileCloseAccessorDepth = 0;
signed char primitiveAsyncFileOpenAccessorDepth = 0;
signed char primitiveAsyncFileReadResultAccessorDepth = 0;
signed char primitiveAsyncFileReadStartAccessorDepth = 0;
signed char primitiveAsyncFileWriteResultAccessorDepth = 0;
signed char primitiveAsyncFileWriteStartAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
