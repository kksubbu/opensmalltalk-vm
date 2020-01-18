/* Automatically generated by
	SmartSyntaxPluginCodeGenerator VMMaker.oscog-eem.2663 uuid: 0dd0f212-66eb-4a18-8da6-5e84a5cbc1ed
   from
	GdbARMv6Plugin Cog-eem.391 uuid: d3c56d74-20ad-4489-935c-5103aa75eb86
 */
static char __buildInfo[] = "GdbARMv6Plugin Cog-eem.391 uuid: d3c56d74-20ad-4489-935c-5103aa75eb86 " __DATE__ ;



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

#include "GdbARMPlugin.h"
#include "sqMemoryAccess.h"


/* ProcessorSimulatorPlugin class>>preambleCCode */

# define isIntegerObject(oop) ((oop) & 1)
# define integerObjectOf(oop) (((oop) << NumSmallIntegerTagBits) | 1)
# define integerValueOf(oop) ((oop) >> NumSmallIntegerTagBits)

# if SPURVM
extern sqInt classIndexOf(sqInt);
#	define LargeNegativeIntegerClassIndex 32
#	define LargePositiveIntegerClassIndex 33
#	if BytesPerOop == 4
#	  define isImmediate(oop) ((oop) & 3)
#	else
#	  define isImmediate(oop) ((oop) & 7)
#	endif
#	define isKindOfInteger(oop) (isImmediate(oop) ? isIntegerObject(oop) : (unsigned)(classIndexOf(oop) - LargeNegativeIntegerClassIndex) <= 1)
#	define isLargeIntegerObject(oop) (!isImmediate(oop) && (unsigned)(classIndexOf(oop) - LargeNegativeIntegerClassIndex) <= 1)
#	define isLargeNegativeIntegerObject(oop) (!isImmediate(oop) && classIndexOf(oop) == LargeNegativeIntegerClassIndex)
#	define isLargePositiveIntegerObject(oop) (!isImmediate(oop) && classIndexOf(oop) == LargePositiveIntegerClassIndex)
# endif /* SPURVM */

#if !defined(isKindOfInteger)
# define isLargeNegativeIntegerObject(oop) (fetchClassOf(oop) == classLargeNegativeInteger())
# define isLargePositiveIntegerObject(oop) (fetchClassOf(oop) == classLargePositiveInteger())
# define isLargeIntegerObject(oop) (isLargeNegativeIntegerObject(oop) || isLargePositiveIntegerObject(oop))
# define isKindOfInteger(oop) (isIntegerObject(oop) || isLargeNegativeIntegerObject(oop) || isLargePositiveIntegerObject(oop))
#endif

/* end ProcessorSimulatorPlugin class>>preambleCCode */


/*** Constants ***/
#define PrimErrBadArgument 3
#define PrimErrBadReceiver 2
#define PrimErrNoMemory 9


/*** Function Prototypes ***/
static void forceStopOnInterrupt(void);
EXPORT(const char*) getModuleName(void);
static sqInt is64BitISA(void);
EXPORT(sqInt) primitiveDisassembleAtInMemory(void);
EXPORT(sqInt) primitiveErrorAndLog(void);
EXPORT(sqInt) primitiveFlushICacheFromTo(void);
EXPORT(sqInt) primitiveIntegerRegisterState(void);
EXPORT(sqInt) primitiveNewCPU(void);
EXPORT(sqInt) primitiveResetCPU(void);
EXPORT(sqInt) primitiveRunInMemoryMinAddressMaxAddressReadWrite(void);
EXPORT(sqInt) primitiveRunInMemoryMinimumAddressReadWrite(void);
EXPORT(sqInt) primitiveSingleStepInMemoryMinAddressMaxAddressReadWrite(void);
EXPORT(sqInt) primitiveSingleStepInMemoryMinimumAddressReadWrite(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);
static sqInt sizeField(sqInt rcvr);
static sqInt sqAssert(sqInt aBool);
static sqInt startOfData(sqInt rcvr);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static void * (*arrayValueOf)(sqInt oop);
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*classArray)(void);
static sqInt (*classDoubleByteArray)(void);
static sqInt (*classString)(void);
static sqInt (*classWordArray)(void);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*getInterruptPending)(void);
static sqInt (*instantiateClassindexableSize)(sqInt classPointer, sqInt size);
#if !defined(integerObjectOf)
static sqInt (*integerObjectOf)(sqInt value);
#endif
#if !defined(integerValueOf)
static sqInt (*integerValueOf)(sqInt oop);
#endif
#if !defined(isIntegerObject)
static sqInt (*isIntegerObject)(sqInt objectPointer);
#endif
static sqInt (*isWordsOrBytes)(sqInt oop);
static sqInt (*pop)(sqInt nItems);
static sqInt (*popthenPush)(sqInt nItems, sqInt oop);
static sqInt (*popRemappableOop)(void);
static sqInt (*positive32BitIntegerFor)(unsigned int integerValue);
static sqInt (*positive64BitIntegerFor)(usqLong integerValue);
static sqInt (*primitiveFail)(void);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*primitiveFailForOSError)(sqLong osError);
static sqInt (*pushRemappableOop)(sqInt oop);
static void (*(*setInterruptCheckChain)(void (*aFunction)(void)))() ;
static sqInt (*stackValue)(sqInt offset);
static sqInt (*storePointerofObjectwithValue)(sqInt index, sqInt oop, sqInt valuePointer);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern void * arrayValueOf(sqInt oop);
extern sqInt byteSizeOf(sqInt oop);
extern sqInt classArray(void);
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 16)
extern sqInt classDoubleByteArray(void);
#else
# define classDoubleByteArray() 0
#endif
extern sqInt classString(void);
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 16)
extern sqInt classWordArray(void);
#else
# define classWordArray() 0
#endif
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt getInterruptPending(void);
extern sqInt instantiateClassindexableSize(sqInt classPointer, sqInt size);
#if !defined(integerObjectOf)
extern sqInt integerObjectOf(sqInt value);
#endif
#if !defined(integerValueOf)
extern sqInt integerValueOf(sqInt oop);
#endif
#if !defined(isIntegerObject)
extern sqInt isIntegerObject(sqInt objectPointer);
#endif
extern sqInt isWordsOrBytes(sqInt oop);
extern sqInt pop(sqInt nItems);
extern sqInt popthenPush(sqInt nItems, sqInt oop);
extern sqInt popRemappableOop(void);
extern sqInt positive32BitIntegerFor(unsigned int integerValue);
extern sqInt positive64BitIntegerFor(usqLong integerValue);
extern sqInt primitiveFail(void);
extern sqInt primitiveFailFor(sqInt reasonCode);
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 14)
extern sqInt primitiveFailForOSError(sqLong osError);
#else
# define primitiveFailForOSError(osError) 0
#endif
extern sqInt pushRemappableOop(sqInt oop);
extern void (*setInterruptCheckChain(void (*aFunction)(void)))() ;
extern sqInt stackValue(sqInt offset);
extern sqInt storePointerofObjectwithValue(sqInt index, sqInt oop, sqInt valuePointer);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"GdbARMPlugin Cog-eem.391 (i)"
#else
	"GdbARMPlugin Cog-eem.391 (e)"
#endif
;


	/* ProcessorSimulatorPlugin>>#forceStopOnInterrupt */
static void
forceStopOnInterrupt(void)
{
	if (getInterruptPending()) {
		forceStopRunning();
	}
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

	/* GdbARMv6Plugin>>#is64BitISA */
static sqInt
is64BitISA(void)
{
	return 0;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Integer> */
/*	<Bitmap|ByteArray|WordArray> */
/*	Return an Array of the instruction length and its decompilation as a
	string for the instruction at address in memory.
 */

	/* ProcessorSimulatorPlugin>>#primitiveDisassembleAt:InMemory: */
EXPORT(sqInt)
primitiveDisassembleAtInMemory(void)
{
	sqInt address;
	void *cpu;
	sqInt cpuAlien;
	sqInt instrLenOrErr;
	char *log;
	long logLen;
	sqInt logObj;
	char *logObjData;
	char *memory;
	sqInt resultObj;

	logLen = 0;
	if (!((isIntegerObject((address = stackValue(1))))
		 && (isWordsOrBytes(stackValue(0))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	address = integerValueOf(address);
	memory = ((char *) (firstIndexableField(stackValue(0))));
	cpuAlien = stackValue(2);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	instrLenOrErr = disassembleForAtInSize(cpu, address, memory, byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize)));
	if (instrLenOrErr < 0) {
		return primitiveFailForOSError(-instrLenOrErr);
	}
	log = getlog((&logLen));
	resultObj = instantiateClassindexableSize(classArray(), 2);
	if (resultObj == 0) {
		return primitiveFailFor(PrimErrNoMemory);
	}
	pushRemappableOop(resultObj);
	logObj = instantiateClassindexableSize(classString(), logLen);
	if (failed()) {
		popRemappableOop();
		return primitiveFailFor(PrimErrNoMemory);
	}
	logObjData = arrayValueOf(logObj);
	memcpy(logObjData, log, logLen);
	resultObj = popRemappableOop();
	storePointerofObjectwithValue(0, resultObj, integerObjectOf(instrLenOrErr));
	storePointerofObjectwithValue(1, resultObj, logObj);
	if (!(failed())) {
		popthenPush(3, resultObj);
	}
	return null;
}

	/* ProcessorSimulatorPlugin>>#primitiveErrorAndLog */
EXPORT(sqInt)
primitiveErrorAndLog(void)
{
	char *log;
	long logLen;
	sqInt logObj;
	char *logObjData;
	sqInt resultObj;

	logLen = 0;
	log = getlog((&logLen));
	resultObj = instantiateClassindexableSize(classArray(), 2);
	if (resultObj == 0) {
		return primitiveFailFor(PrimErrNoMemory);
	}
	storePointerofObjectwithValue(0, resultObj, integerObjectOf(errorAcorn()));
	if (logLen > 0) {
		pushRemappableOop(resultObj);
		logObj = instantiateClassindexableSize(classString(), logLen);
		if (failed()) {
			popRemappableOop();
			return primitiveFailFor(PrimErrNoMemory);
		}
		resultObj = popRemappableOop();
		logObjData = arrayValueOf(logObj);
		memcpy(logObjData, log, logLen);
		storePointerofObjectwithValue(1, resultObj, logObj);
	}
	popthenPush(1, resultObj);
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Integer> */
/*	<Integer> */
/*	Flush the icache in the requested range */

	/* ProcessorSimulatorPlugin>>#primitiveFlushICacheFrom:To: */
EXPORT(sqInt)
primitiveFlushICacheFromTo(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt endAddress;
	sqInt startAddress;

	if (!((isIntegerObject((startAddress = stackValue(1))))
		 && (isIntegerObject((endAddress = stackValue(0)))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	startAddress = integerValueOf(startAddress);
	endAddress = integerValueOf(endAddress);
	cpuAlien = stackValue(2);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	flushICacheFromTo(cpu, startAddress, endAddress);
	if (!(failed())) {
		pop(2);
	}
	return null;
}


/*	Answer an IntegerArray of the processor's integer register state, ending
	with, if these are not otherwise
	included in the register state, the pc and the flags (if the processor has
	flags). 
	 This primitive is unnecessary; it exists only to speed up
	single stepping.
 */

	/* ProcessorSimulatorPlugin>>#primitiveIntegerRegisterState */
EXPORT(sqInt)
primitiveIntegerRegisterState(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt registerStateVector;

	cpuAlien = stackValue(0);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	registerStateVector = instantiateClassindexableSize((0
		? classDoubleByteArray()
		: classWordArray()), NumIntegerRegisterStateFields);
	if (registerStateVector == 0) {
		return primitiveFailFor(PrimErrNoMemory);
	}
	if ((byteSizeOf(registerStateVector)) != (NumIntegerRegisterStateFields * (sizeof(int)))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	storeIntegerRegisterStateOfinto(cpu, firstIndexableField(registerStateVector));
	if (!(failed())) {
		popthenPush(1, registerStateVector);
	}
	return null;
}

	/* ProcessorSimulatorPlugin>>#primitiveNewCPU */
EXPORT(sqInt)
primitiveNewCPU(void)
{
	void *cpu;

	cpu = newCPU();
	if (cpu == 0) {
		return primitiveFail();
	}
	popthenPush(1, (BytesPerWord == 8
		? positive64BitIntegerFor(((usqIntptr_t) cpu))
		: positive32BitIntegerFor(((usqIntptr_t) cpu))));
	return null;
}

	/* ProcessorSimulatorPlugin>>#primitiveResetCPU */
EXPORT(sqInt)
primitiveResetCPU(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maybeErr;

	cpuAlien = stackValue(0);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	maybeErr = resetCPU(cpu);
	if (maybeErr != 0) {
		return primitiveFailForOSError(maybeErr);
	}
	if (!(failed())) {
		popthenPush(1, cpuAlien);
	}
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Bitmap|ByteArray|WordArray> */
/*	<Integer> */
/*	<Integer> */
/*	<Integer> */
/*	Run the cpu using the first argument as the memory and the following
	arguments defining valid addresses, running until it halts or hits an
	exception. 
 */

	/* ProcessorSimulatorPlugin>>#primitiveRunInMemory:minimumAddress:maximumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveRunInMemoryMinAddressMaxAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maxAddress;
	sqInt maybeErr;
	char *memory;
	sqInt memorySize;
	sqInt minAddress;
	sqInt minWriteMaxExecAddress;

	if (!((isWordsOrBytes(stackValue(3)))
		 && ((isIntegerObject((minAddress = stackValue(2))))
		 && ((isIntegerObject((maxAddress = stackValue(1))))
		 && (isIntegerObject((minWriteMaxExecAddress = stackValue(0)))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	memory = ((char *) (firstIndexableField(stackValue(3))));
	minAddress = integerValueOf(minAddress);
	maxAddress = integerValueOf(maxAddress);
	minWriteMaxExecAddress = integerValueOf(minWriteMaxExecAddress);
	cpuAlien = stackValue(4);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	if ((minAddress < 0)
	 || ((maxAddress < 0)
	 || (minWriteMaxExecAddress < 0))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	prevInterruptCheckChain = setInterruptCheckChain(forceStopOnInterrupt);
	if (prevInterruptCheckChain == (forceStopOnInterrupt)) {
		prevInterruptCheckChain = 0;
	}
	memorySize = byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize));
	maybeErr = runCPUInSizeMinAddressReadWrite(cpu, memory, ((memorySize < maxAddress) ? memorySize : maxAddress), minAddress, minWriteMaxExecAddress);
	setInterruptCheckChain(prevInterruptCheckChain);
	if (maybeErr != 0) {
		return primitiveFailForOSError(maybeErr);
	}
	if (!(failed())) {
		popthenPush(5, cpuAlien);
	}
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Bitmap|ByteArray|WordArray> */
/*	<Integer> */
/*	<Integer> */
/*	Run the cpu using the first argument as the memory and the following
	arguments defining valid addresses, running until it halts or hits an
	exception. 
 */

	/* ProcessorSimulatorPlugin>>#primitiveRunInMemory:minimumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveRunInMemoryMinimumAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maybeErr;
	char *memory;
	sqInt minAddress;
	sqInt minWriteMaxExecAddress;

	if (!((isWordsOrBytes(stackValue(2)))
		 && ((isIntegerObject((minAddress = stackValue(1))))
		 && (isIntegerObject((minWriteMaxExecAddress = stackValue(0))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	memory = ((char *) (firstIndexableField(stackValue(2))));
	minAddress = integerValueOf(minAddress);
	minWriteMaxExecAddress = integerValueOf(minWriteMaxExecAddress);
	cpuAlien = stackValue(3);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	if ((minAddress < 0)
	 || (minWriteMaxExecAddress < 0)) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	prevInterruptCheckChain = setInterruptCheckChain(forceStopOnInterrupt);
	if (prevInterruptCheckChain == (forceStopOnInterrupt)) {
		prevInterruptCheckChain = 0;
	}
	maybeErr = runCPUInSizeMinAddressReadWrite(cpu, memory, byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize)), minAddress, minWriteMaxExecAddress);
	setInterruptCheckChain(prevInterruptCheckChain);
	if (maybeErr != 0) {
		return primitiveFailForOSError(maybeErr);
	}
	if (!(failed())) {
		popthenPush(4, cpuAlien);
	}
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Bitmap|ByteArray|WordArray> */
/*	<Integer> */
/*	<Integer> */
/*	<Integer> */
/*	Single-step the cpu using the first argument as the memory and the
	following arguments defining valid addresses.
 */

	/* ProcessorSimulatorPlugin>>#primitiveSingleStepInMemory:minimumAddress:maximumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveSingleStepInMemoryMinAddressMaxAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maxAddress;
	sqInt maybeErr;
	char *memory;
	sqInt memorySize;
	sqInt minAddress;
	sqInt minWriteMaxExecAddress;

	if (!((isWordsOrBytes(stackValue(3)))
		 && ((isIntegerObject((minAddress = stackValue(2))))
		 && ((isIntegerObject((maxAddress = stackValue(1))))
		 && (isIntegerObject((minWriteMaxExecAddress = stackValue(0)))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	memory = ((char *) (firstIndexableField(stackValue(3))));
	minAddress = integerValueOf(minAddress);
	maxAddress = integerValueOf(maxAddress);
	minWriteMaxExecAddress = integerValueOf(minWriteMaxExecAddress);
	cpuAlien = stackValue(4);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	if ((minAddress < 0)
	 || ((maxAddress < 0)
	 || (minWriteMaxExecAddress < 0))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	memorySize = byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize));
	maybeErr = singleStepCPUInSizeMinAddressReadWrite(cpu, memory, ((memorySize < maxAddress) ? memorySize : maxAddress), minAddress, minWriteMaxExecAddress);
	if (maybeErr != 0) {
		return primitiveFailForOSError(maybeErr);
	}
	if (!(failed())) {
		popthenPush(5, cpuAlien);
	}
	return null;
}


/*	cpuAlien <BochsIA32|X86Alien> */
/*	<Bitmap|ByteArray|WordArray> */
/*	<Integer> */
/*	<Integer> */
/*	Single-step the cpu using the first argument as the memory and the
	following arguments defining valid addresses.
 */

	/* ProcessorSimulatorPlugin>>#primitiveSingleStepInMemory:minimumAddress:readOnlyBelow: */
EXPORT(sqInt)
primitiveSingleStepInMemoryMinimumAddressReadWrite(void)
{
	void *cpu;
	sqInt cpuAlien;
	sqInt maybeErr;
	char *memory;
	sqInt minAddress;
	sqInt minWriteMaxExecAddress;

	if (!((isWordsOrBytes(stackValue(2)))
		 && ((isIntegerObject((minAddress = stackValue(1))))
		 && (isIntegerObject((minWriteMaxExecAddress = stackValue(0))))))) {
		primitiveFailFor(PrimErrBadArgument);
		return null;
	}
	memory = ((char *) (firstIndexableField(stackValue(2))));
	minAddress = integerValueOf(minAddress);
	minWriteMaxExecAddress = integerValueOf(minWriteMaxExecAddress);
	cpuAlien = stackValue(3);
	if (failed()) {
		return null;
	}
	if (((cpu = ((void *) (((longAt(cpuAlien + BaseHeaderSize)) > 0
	? (cpuAlien + BaseHeaderSize) + BytesPerOop
	: longAt((cpuAlien + BaseHeaderSize) + BytesPerOop)))))) == 0) {
		return primitiveFailFor(PrimErrBadReceiver);
	}
	if ((minAddress < 0)
	 || (minWriteMaxExecAddress < 0)) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	maybeErr = singleStepCPUInSizeMinAddressReadWrite(cpu, memory, byteSizeOf(((sqInt)(sqIntptr_t)(memory) - BaseHeaderSize)), minAddress, minWriteMaxExecAddress);
	if (maybeErr != 0) {
		return primitiveFailForOSError(maybeErr);
	}
	if (!(failed())) {
		popthenPush(4, cpuAlien);
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
		arrayValueOf = interpreterProxy->arrayValueOf;
		byteSizeOf = interpreterProxy->byteSizeOf;
		classArray = interpreterProxy->classArray;
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 16)
		classDoubleByteArray = interpreterProxy->classDoubleByteArray;
#else
#if !defined(classDoubleByteArray)
		classDoubleByteArray = 0;
#endif
#endif
		classString = interpreterProxy->classString;
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 16)
		classWordArray = interpreterProxy->classWordArray;
#else
#if !defined(classWordArray)
		classWordArray = 0;
#endif
#endif
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		getInterruptPending = interpreterProxy->getInterruptPending;
		instantiateClassindexableSize = interpreterProxy->instantiateClassindexableSize;
#if !defined(integerObjectOf)
		integerObjectOf = interpreterProxy->integerObjectOf;
#endif
#if !defined(integerValueOf)
		integerValueOf = interpreterProxy->integerValueOf;
#endif
#if !defined(isIntegerObject)
		isIntegerObject = interpreterProxy->isIntegerObject;
#endif
		isWordsOrBytes = interpreterProxy->isWordsOrBytes;
		pop = interpreterProxy->pop;
		popthenPush = interpreterProxy->popthenPush;
		popRemappableOop = interpreterProxy->popRemappableOop;
		positive32BitIntegerFor = interpreterProxy->positive32BitIntegerFor;
		positive64BitIntegerFor = interpreterProxy->positive64BitIntegerFor;
		primitiveFail = interpreterProxy->primitiveFail;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
#if VM_PROXY_MAJOR > 1 || (VM_PROXY_MAJOR == 1 && VM_PROXY_MINOR >= 14)
		primitiveFailForOSError = interpreterProxy->primitiveFailForOSError;
#else
#if !defined(primitiveFailForOSError)
		primitiveFailForOSError = 0;
#endif
#endif
		pushRemappableOop = interpreterProxy->pushRemappableOop;
		setInterruptCheckChain = interpreterProxy->setInterruptCheckChain;
		stackValue = interpreterProxy->stackValue;
		storePointerofObjectwithValue = interpreterProxy->storePointerofObjectwithValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


/*	Answer the first field of rcvr which is assumed to be an Alien of at least
	8 bytes
 */

	/* ProcessorSimulatorPlugin>>#sizeField: */
static sqInt
sizeField(sqInt rcvr)
{
	return longAt(rcvr + BaseHeaderSize);
}

	/* SmartSyntaxInterpreterPlugin>>#sqAssert: */
static sqInt
sqAssert(sqInt aBool)
{
	/* missing DebugCode */;
	return aBool;
}


/*	<Alien oop> ^<Integer> */
/*	Answer the start of rcvr's data. For direct aliens this is the address of
	the second field. For indirect and pointer aliens it is what the second
	field points to. */

	/* ProcessorSimulatorPlugin>>#startOfData: */
static sqInt
startOfData(sqInt rcvr)
{
	return ((longAt(rcvr + BaseHeaderSize)) > 0
		? (rcvr + BaseHeaderSize) + BytesPerOop
		: longAt((rcvr + BaseHeaderSize) + BytesPerOop));
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "GdbARMPlugin";
void* GdbARMPlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveDisassembleAtInMemory\000\000", (void*)primitiveDisassembleAtInMemory},
	{(void*)_m, "primitiveErrorAndLog\000\377", (void*)primitiveErrorAndLog},
	{(void*)_m, "primitiveFlushICacheFromTo\000\000", (void*)primitiveFlushICacheFromTo},
	{(void*)_m, "primitiveIntegerRegisterState\000\000", (void*)primitiveIntegerRegisterState},
	{(void*)_m, "primitiveNewCPU\000\377", (void*)primitiveNewCPU},
	{(void*)_m, "primitiveResetCPU\000\000", (void*)primitiveResetCPU},
	{(void*)_m, "primitiveRunInMemoryMinAddressMaxAddressReadWrite\000\000", (void*)primitiveRunInMemoryMinAddressMaxAddressReadWrite},
	{(void*)_m, "primitiveRunInMemoryMinimumAddressReadWrite\000\000", (void*)primitiveRunInMemoryMinimumAddressReadWrite},
	{(void*)_m, "primitiveSingleStepInMemoryMinAddressMaxAddressReadWrite\000\000", (void*)primitiveSingleStepInMemoryMinAddressMaxAddressReadWrite},
	{(void*)_m, "primitiveSingleStepInMemoryMinimumAddressReadWrite\000\000", (void*)primitiveSingleStepInMemoryMinimumAddressReadWrite},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveDisassembleAtInMemoryAccessorDepth = 0;
signed char primitiveFlushICacheFromToAccessorDepth = 0;
signed char primitiveIntegerRegisterStateAccessorDepth = 0;
signed char primitiveResetCPUAccessorDepth = 0;
signed char primitiveRunInMemoryMinAddressMaxAddressReadWriteAccessorDepth = 0;
signed char primitiveRunInMemoryMinimumAddressReadWriteAccessorDepth = 0;
signed char primitiveSingleStepInMemoryMinAddressMaxAddressReadWriteAccessorDepth = 0;
signed char primitiveSingleStepInMemoryMinimumAddressReadWriteAccessorDepth = 0;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
