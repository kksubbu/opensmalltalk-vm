/* Automatically generated by
	VMPluginCodeGenerator VMMaker.oscog-eem.2663 uuid: 0dd0f212-66eb-4a18-8da6-5e84a5cbc1ed
   from
	MiscPrimitivePlugin VMMaker.oscog-eem.2663 uuid: 0dd0f212-66eb-4a18-8da6-5e84a5cbc1ed
 */
static char __buildInfo[] = "MiscPrimitivePlugin VMMaker.oscog-eem.2663 uuid: 0dd0f212-66eb-4a18-8da6-5e84a5cbc1ed " __DATE__ ;



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

#include "sqMemoryAccess.h"


/*** Constants ***/
#define PrimErrBadArgument 3
#define PrimErrBadIndex 4
#define PrimErrNoModification 8
#define PrimErrUnsupported 7


/*** Function Prototypes ***/
EXPORT(const char*) getModuleName(void);
EXPORT(sqInt) primitiveCompareString(void);
EXPORT(sqInt) primitiveCompressToByteArray(void);
EXPORT(sqInt) primitiveConvert8BitSigned(void);
EXPORT(sqInt) primitiveDecompressFromByteArray(void);
EXPORT(sqInt) primitiveFindFirstInString(void);
EXPORT(sqInt) primitiveFindSubstring(void);
EXPORT(sqInt) primitiveIndexOfAsciiInString(void);
EXPORT(sqInt) primitiveStringHash(void);
EXPORT(sqInt) primitiveTranslateStringWithTable(void);
EXPORT(sqInt) setInterpreter(struct VirtualMachine *anInterpreter);


/*** Variables ***/

#if !defined(SQUEAK_BUILTIN_PLUGIN)
static void * (*arrayValueOf)(sqInt oop);
static sqInt (*byteSizeOf)(sqInt oop);
static sqInt (*failed)(void);
static void * (*firstIndexableField)(sqInt oop);
static sqInt (*isBytes)(sqInt oop);
#if IMMUTABILITY
static sqInt (*isOopImmutable)(sqInt oop);
#endif /* IMMUTABILITY */
static sqInt (*methodArgumentCount)(void);
static sqInt (*methodReturnInteger)(sqInt integer);
static sqInt (*methodReturnReceiver)(void);
static sqInt (*pop)(sqInt nItems);
static sqInt (*primitiveFailFor)(sqInt reasonCode);
static sqInt (*sizeOfSTArrayFromCPrimitive)(void *cPtr);
static sqInt (*stackIntegerValue)(sqInt offset);
static sqInt (*stackValue)(sqInt offset);
#else /* !defined(SQUEAK_BUILTIN_PLUGIN) */
extern void * arrayValueOf(sqInt oop);
extern sqInt byteSizeOf(sqInt oop);
extern sqInt failed(void);
extern void * firstIndexableField(sqInt oop);
extern sqInt isBytes(sqInt oop);
#if IMMUTABILITY
#if IMMUTABILITY
extern sqInt isOopImmutable(sqInt oop);
#endif /* IMMUTABILITY */
#else
# define isOopImmutable(oop) 0
#endif
extern sqInt methodArgumentCount(void);
extern sqInt methodReturnInteger(sqInt integer);
extern sqInt methodReturnReceiver(void);
extern sqInt pop(sqInt nItems);
extern sqInt primitiveFailFor(sqInt reasonCode);
extern sqInt sizeOfSTArrayFromCPrimitive(void *cPtr);
extern sqInt stackIntegerValue(sqInt offset);
extern sqInt stackValue(sqInt offset);
extern
#endif
struct VirtualMachine* interpreterProxy;
static const char *moduleName =
#ifdef SQUEAK_BUILTIN_PLUGIN
	"MiscPrimitivePlugin VMMaker.oscog-eem.2663 (i)"
#else
	"MiscPrimitivePlugin VMMaker.oscog-eem.2663 (e)"
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


/*	ByteString (class) compare: string1 with: string2 collated: order */

	/* MiscPrimitivePlugin>>#primitiveCompareString */
EXPORT(sqInt)
primitiveCompareString(void)
{
    unsigned char c1;
    unsigned char c2;
    sqInt i;
    sqInt len1;
    sqInt len2;
    unsigned char *order;
    sqInt orderOop;
    unsigned char *string1;
    sqInt string1Oop;
    unsigned char *string2;
    sqInt string2Oop;

	orderOop = stackValue(0);
	string2Oop = stackValue(1);
	string1Oop = stackValue(2);
	if (!((isBytes(orderOop))
		 && ((isBytes(string2Oop))
		 && (isBytes(string1Oop))))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	order = firstIndexableField(orderOop);
	if ((sizeOfSTArrayFromCPrimitive(order)) < 256) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	string1 = firstIndexableField(string1Oop);
	string2 = firstIndexableField(string2Oop);
	len1 = sizeOfSTArrayFromCPrimitive(string1);
	len2 = sizeOfSTArrayFromCPrimitive(string2);
	for (i = 0; i < (((len1 < len2) ? len1 : len2)); i += 1) {
		c1 = order[string1[i]];
		c2 = order[string2[i]];
		if (!(c1 == c2)) {
			return methodReturnInteger((c1 < c2
				? 1
				: 3));
		}
	}
	methodReturnInteger((len1 == len2
		? 2
		: (len1 < len2
				? 1
				: 3)));
	return 0;
}


/*	Bitmap compress: bm toByteArray: ba */

	/* MiscPrimitivePlugin>>#primitiveCompressToByteArray */
EXPORT(sqInt)
primitiveCompressToByteArray(void)
{
    unsigned char *ba;
    int *bm;
    sqInt destSize;
    sqInt eqBytes;
    sqInt i;
    sqInt j;
    sqInt j1;
    sqInt j2;
    sqInt j3;
    sqInt j4;
    sqInt j5;
    sqInt j6;
    sqInt j7;
    sqInt k;
    int lowByte;
    sqInt m;
    sqInt size;
    int word;

	bm = arrayValueOf(stackValue(1));
	if (failed()) {
		return null;
	}
	if (!(isBytes(stackValue(0)))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	if (isOopImmutable(stackValue(0))) {
		return primitiveFailFor(PrimErrNoModification);
	}
	ba = firstIndexableField(stackValue(0));
	size = sizeOfSTArrayFromCPrimitive(bm);
	destSize = sizeOfSTArrayFromCPrimitive(ba);
	if (destSize < (((size * 4) + 7) + ((size / 0x7C0) * 3))) {
		return primitiveFailFor(PrimErrUnsupported);
	}
	/* begin encodeInt:in:at: */
	if (size <= 223) {
		ba[0] = size;
		i = 0 + 1;
		goto l7;
	}
	if (size <= 7935) {
		ba[0] = ((size / 256) + 224);
		ba[0 + 1] = (size % 256);
		i = 0 + 2;
		goto l7;
	}
	ba[0] = 0xFF;
	/* begin encodeBytesOf:in:at: */
	for (j7 = 0; j7 <= 3; j7 += 1) {
		ba[(0 + 1) + j7] = ((((usqInt) size) >> ((3 - j7) * 8)) & 0xFF);
	}
	i = (0 + 1) + 4;
	l7:	/* end encodeInt:in:at: */;
	k = 0;
	while (k < size) {
		word = bm[k];
		lowByte = word & 0xFF;
		eqBytes = (((((usqInt) word) >> 8) & 0xFF) == lowByte)
		 && ((((((usqInt) word) >> 16) & 0xFF) == lowByte)
		 && (((((usqInt) word) >> 24) & 0xFF) == lowByte));
		j = k;
		while (((j + 1) < size)
		 && (word == (bm[j + 1]))) {
			j += 1;
		}
		if (j > k) {
			if (eqBytes) {
				/* begin encodeInt:in:at: */
				if (((((j - k) + 1) * 4) + 1) <= 223) {
					ba[i] = ((((j - k) + 1) * 4) + 1);
					i += 1;
					goto l1;
				}
				if (((((j - k) + 1) * 4) + 1) <= 7935) {
					ba[i] = ((((((j - k) + 1) * 4) + 1) / 256) + 224);
					ba[i + 1] = (((((j - k) + 1) * 4) + 1) % 256);
					i += 2;
					goto l1;
				}
				ba[i] = 0xFF;
				/* begin encodeBytesOf:in:at: */
				for (j1 = 0; j1 <= 3; j1 += 1) {
					ba[(i + 1) + j1] = ((((usqInt) ((((j - k) + 1) * 4) + 1)) >> ((3 - j1) * 8)) & 0xFF);
				}
				i = (i + 1) + 4;
	l1:	/* end encodeInt:in:at: */;
				ba[i] = lowByte;
				i += 1;
			}
			else {
				/* begin encodeInt:in:at: */
				if (((((j - k) + 1) * 4) + 2) <= 223) {
					ba[i] = ((((j - k) + 1) * 4) + 2);
					i += 1;
					goto l2;
				}
				if (((((j - k) + 1) * 4) + 2) <= 7935) {
					ba[i] = ((((((j - k) + 1) * 4) + 2) / 256) + 224);
					ba[i + 1] = (((((j - k) + 1) * 4) + 2) % 256);
					i += 2;
					goto l2;
				}
				ba[i] = 0xFF;
				/* begin encodeBytesOf:in:at: */
				for (j2 = 0; j2 <= 3; j2 += 1) {
					ba[(i + 1) + j2] = ((((usqInt) ((((j - k) + 1) * 4) + 2)) >> ((3 - j2) * 8)) & 0xFF);
				}
				i = (i + 1) + 4;
	l2:	/* end encodeInt:in:at: */;
				/* begin encodeBytesOf:in:at: */
				for (j3 = 0; j3 <= 3; j3 += 1) {
					ba[i + j3] = ((((usqInt) word) >> ((3 - j3) * 8)) & 0xFF);
				}
				i += 4;
			}
			k = j + 1;
		}
		else {
			if (eqBytes) {
				/* begin encodeInt:in:at: */
				if (((1 * 4) + 1) <= 223) {
					ba[i] = ((1 * 4) + 1);
					i += 1;
					goto l4;
				}
				if (((1 * 4) + 1) <= 7935) {
					ba[i] = ((((1 * 4) + 1) / 256) + 224);
					ba[i + 1] = (((1 * 4) + 1) % 256);
					i += 2;
					goto l4;
				}
				ba[i] = 0xFF;
				/* begin encodeBytesOf:in:at: */
				for (j4 = 0; j4 <= 3; j4 += 1) {
					ba[(i + 1) + j4] = ((((usqInt) ((1 * 4) + 1)) >> ((3 - j4) * 8)) & 0xFF);
				}
				i = (i + 1) + 4;
	l4:	/* end encodeInt:in:at: */;
				ba[i] = lowByte;
				i += 1;
				k += 1;
			}
			else {
				while (((j + 1) < size)
				 && ((bm[j]) != (bm[j + 1]))) {
					j += 1;
				}
				if ((j + 1) == size) {
					j += 1;
				}
				/* begin encodeInt:in:at: */
				if ((((j - k) * 4) + 3) <= 223) {
					ba[i] = (((j - k) * 4) + 3);
					i += 1;
					goto l6;
				}
				if ((((j - k) * 4) + 3) <= 7935) {
					ba[i] = (((((j - k) * 4) + 3) / 256) + 224);
					ba[i + 1] = ((((j - k) * 4) + 3) % 256);
					i += 2;
					goto l6;
				}
				ba[i] = 0xFF;
				/* begin encodeBytesOf:in:at: */
				for (j6 = 0; j6 <= 3; j6 += 1) {
					ba[(i + 1) + j6] = ((((usqInt) (((j - k) * 4) + 3)) >> ((3 - j6) * 8)) & 0xFF);
				}
				i = (i + 1) + 4;
	l6:	/* end encodeInt:in:at: */;
				for (m = k; m < j; m += 1) {
					/* begin encodeBytesOf:in:at: */
					for (j5 = 0; j5 <= 3; j5 += 1) {
						ba[i + j5] = ((((usqInt) (bm[m])) >> ((3 - j5) * 8)) & 0xFF);
					}
					i += 4;
				}
				k = j;
			}
		}
	}
	methodReturnInteger(i);
	return 0;
}


/*	SampledSound (class) convert8bitSignedFrom: aByteArray to16Bit:
	aSoundBuffer 
 */

	/* MiscPrimitivePlugin>>#primitiveConvert8BitSigned */
EXPORT(sqInt)
primitiveConvert8BitSigned(void)
{
    unsigned char *aByteArray;
    sqInt arraySize;
    unsigned short *aSoundBuffer;
    sqInt byteArrayOop;
    sqInt i;
    unsigned char s;
    sqInt soundBufferOop;

	byteArrayOop = stackValue(1);
	if (!(isBytes(byteArrayOop))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	aByteArray = firstIndexableField(byteArrayOop);
	soundBufferOop = stackValue(0);
	aSoundBuffer = arrayValueOf(soundBufferOop);
	if (failed()) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	if (isOopImmutable(soundBufferOop)) {
		return primitiveFailFor(PrimErrNoModification);
	}
	arraySize = sizeOfSTArrayFromCPrimitive(aByteArray);
	if ((byteSizeOf(soundBufferOop)) < (2 * arraySize)) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	for (i = 0; i < arraySize; i += 1) {
		s = aByteArray[i];
		aSoundBuffer[i] = ((s > 0x7F
	? ((usqInt) (s - 256) << 8)
	: ((usqInt) s << 8)));
	}
	methodReturnReceiver();
	return 0;
}


/*	Bitmap decompress: bm fromByteArray: ba at: index */

	/* MiscPrimitivePlugin>>#primitiveDecompressFromByteArray */
EXPORT(sqInt)
primitiveDecompressFromByteArray(void)
{
    unsigned int anInt;
    unsigned char *ba;
    int *bm;
    unsigned int code;
    unsigned int data;
    sqInt end;
    sqInt i;
    sqInt index;
    sqInt j;
    sqInt k;
    sqInt m;
    unsigned int n;
    sqInt pastEnd;

	bm = arrayValueOf(stackValue(2));
	if (isOopImmutable(stackValue(2))) {
		return primitiveFailFor(PrimErrNoModification);
	}
	if (!(isBytes(stackValue(1)))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	ba = firstIndexableField(stackValue(1));
	index = stackIntegerValue(0);
	if (failed()) {
		return null;
	}
	i = index - 1;
	k = 0;
	end = sizeOfSTArrayFromCPrimitive(ba);
	pastEnd = sizeOfSTArrayFromCPrimitive(bm);
	while (i < end) {
		anInt = ba[i];
		i += 1;
		if (!(anInt <= 223)) {
			if (anInt <= 0xFE) {
				anInt = ((anInt - 224) * 256) + (ba[i]);
				i += 1;
			}
			else {
				anInt = 0;
				for (j = 1; j <= 4; j += 1) {
					anInt = (((usqInt) anInt << 8)) + (ba[i]);
					i += 1;
				}
			}
		}
		n = ((usqInt) anInt) >> 2;
		if ((k + n) > pastEnd) {
			return primitiveFailFor(PrimErrBadIndex);
		}

		/* code = 0 ifTrue: [nil]. */
		code = anInt & 3;
		if (code == 1) {
			data = ba[i];
			i += 1;
			data = data | (((usqInt) data << 8));
			data = data | (((usqInt) data << 16));
			for (j = 1; j <= n; j += 1) {
				bm[k] = data;
				k += 1;
			}
		}
		if (code == 2) {
			data = 0;
			for (j = 1; j <= 4; j += 1) {
				data = (((usqInt) data << 8)) | (ba[i]);
				i += 1;
			}
			for (j = 1; j <= n; j += 1) {
				bm[k] = data;
				k += 1;
			}
		}
		if (code == 3) {
			for (m = 1; m <= n; m += 1) {
				data = 0;
				for (j = 1; j <= 4; j += 1) {
					data = (((usqInt) data << 8)) | (ba[i]);
					i += 1;
				}
				bm[k] = data;
				k += 1;
			}
		}
	}
	pop(methodArgumentCount());
	return 0;
}


/*	ByteString (class) findFirstInString: aString inSet: inclusionMap
	startingAt: start */

	/* MiscPrimitivePlugin>>#primitiveFindFirstInString */
EXPORT(sqInt)
primitiveFindFirstInString(void)
{
    unsigned char *aString;
    sqInt aStringOop;
    sqInt i;
    unsigned char *inclusionMap;
    sqInt inclusionMapOop;
    sqInt stringSize;

	aStringOop = stackValue(2);
	if (!(isBytes(aStringOop))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	inclusionMapOop = stackValue(1);
	if (!(isBytes(inclusionMapOop))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	i = stackIntegerValue(0);
	if (failed()) {
		return primitiveFailFor(PrimErrBadArgument);
	}

	/* Convert to 0-based index. */
	i -= 1;
	if (i < 0) {
		return primitiveFailFor(PrimErrBadIndex);
	}
	inclusionMap = firstIndexableField(inclusionMapOop);
	if ((sizeOfSTArrayFromCPrimitive(inclusionMap)) != 256) {
		return methodReturnInteger(0);
	}
	aString = firstIndexableField(aStringOop);
	stringSize = sizeOfSTArrayFromCPrimitive(aString);
	while ((i < stringSize)
	 && ((inclusionMap[aString[i]]) == 0)) {
		i += 1;
	}
	methodReturnInteger((i >= stringSize
		? 0
		: i + 1));
	return 0;
}


/*	ByteString findSubstring: key in: body startingAt: start matchTable:
	matchTable 
 */

	/* MiscPrimitivePlugin>>#primitiveFindSubstring */
EXPORT(sqInt)
primitiveFindSubstring(void)
{
    unsigned char *body;
    sqInt bodyOop;
    sqInt index;
    unsigned char *key;
    sqInt keyOop;
    sqInt keySize;
    unsigned char *matchTable;
    sqInt matchTableOop;
    sqInt start;
    sqInt startIndex;
    sqInt startIndexLimiT;

	keyOop = stackValue(3);
	if (!(isBytes(keyOop))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	bodyOop = stackValue(2);
	if (!(isBytes(bodyOop))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	start = stackIntegerValue(1);
	if (failed()) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	matchTableOop = stackValue(0);
	if (!(isBytes(matchTableOop))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	matchTable = firstIndexableField(matchTableOop);
	if ((sizeOfSTArrayFromCPrimitive(matchTable)) < 256) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	key = firstIndexableField(keyOop);
	if (((keySize = sizeOfSTArrayFromCPrimitive(key))) > 0) {

		/* adjust for zero relative indexes */
		keySize -= 1;

		/* adjust for zero relative indexes */
		start = (((start - 1) < 0) ? 0 : (start - 1));
		body = firstIndexableField(bodyOop);
		for (startIndex = start, startIndexLimiT = (((sizeOfSTArrayFromCPrimitive(body)) - 1) - keySize); startIndex <= startIndexLimiT; startIndex += 1) {
			index = 0;
			while ((matchTable[body[startIndex + index]]) == (matchTable[key[index]])) {
				if (index == keySize) {
					return methodReturnInteger(startIndex + 1);
				}
				index += 1;
			}
		}
	}
	return methodReturnInteger(0);
}


/*	ByteString indexOfAscii: anInteger inString: aString startingAt: start */

	/* MiscPrimitivePlugin>>#primitiveIndexOfAsciiInString */
EXPORT(sqInt)
primitiveIndexOfAsciiInString(void)
{
    sqInt anInteger;
    unsigned char *aString;
    sqInt aStringOop;
    sqInt pos;
    sqInt start;
    sqInt stringSize;

	anInteger = stackIntegerValue(2);
	if (failed()) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	aStringOop = stackValue(1);
	if (!(isBytes(aStringOop))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	start = stackIntegerValue(0);
	if (failed()) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	if (!(start >= 1)) {
		return primitiveFailFor(PrimErrBadIndex);
	}
	aString = firstIndexableField(aStringOop);
	stringSize = sizeOfSTArrayFromCPrimitive(aString);
	for (pos = (start - 1); pos < stringSize; pos += 1) {
		if ((aString[pos]) == anInteger) {
			return methodReturnInteger(pos + 1);
		}
	}
	return methodReturnInteger(0);
}


/*	ByteArray (class) hashBytes: aByteArray startingWith: speciesHash */

	/* MiscPrimitivePlugin>>#primitiveStringHash */
EXPORT(sqInt)
primitiveStringHash(void)
{
    unsigned char *aByteArray;
    sqInt byteArrayOop;
    unsigned int hash;
    sqInt pos;
    sqInt posLimiT;

	hash = stackIntegerValue(0);
	if (failed()) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	byteArrayOop = stackValue(1);
	if (!(isBytes(byteArrayOop))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	aByteArray = firstIndexableField(byteArrayOop);
	for (pos = 0, posLimiT = ((sizeOfSTArrayFromCPrimitive(aByteArray)) - 1); pos <= posLimiT; pos += 1) {
		hash = (hash + (aByteArray[pos])) * 1664525;
	}
	methodReturnInteger(hash & 0xFFFFFFF);
	return 0;
}


/*	ByteString (class) translate: aString from: start to: stop table: table */

	/* MiscPrimitivePlugin>>#primitiveTranslateStringWithTable */
EXPORT(sqInt)
primitiveTranslateStringWithTable(void)
{
    unsigned char *aString;
    sqInt aStringOop;
    sqInt i;
    sqInt start;
    sqInt stop;
    unsigned char *table;
    sqInt tableOop;

	aStringOop = stackValue(3);
	if (!(isBytes(aStringOop))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	if (isOopImmutable(aStringOop)) {
		return primitiveFailFor(PrimErrNoModification);
	}
	start = stackIntegerValue(2);
	if (failed()) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	stop = stackIntegerValue(1);
	if (failed()) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	tableOop = stackValue(0);
	if (!(isBytes(tableOop))) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	aString = firstIndexableField(aStringOop);
	if (!((start >= 1)
		 && (stop <= (sizeOfSTArrayFromCPrimitive(aString))))) {
		return primitiveFailFor(PrimErrBadIndex);
	}
	table = firstIndexableField(tableOop);
	if ((sizeOfSTArrayFromCPrimitive(table)) < 256) {
		return primitiveFailFor(PrimErrBadArgument);
	}
	for (i = (start - 1); i < stop; i += 1) {
		aString[i] = (table[aString[i]]);
	}
	methodReturnReceiver();
	return 0;
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
		failed = interpreterProxy->failed;
		firstIndexableField = interpreterProxy->firstIndexableField;
		isBytes = interpreterProxy->isBytes;
#if IMMUTABILITY
		isOopImmutable = interpreterProxy->isOopImmutable;
#else
#if !defined(isOopImmutable)
		isOopImmutable = 0;
#endif
#endif
		methodArgumentCount = interpreterProxy->methodArgumentCount;
		methodReturnInteger = interpreterProxy->methodReturnInteger;
		methodReturnReceiver = interpreterProxy->methodReturnReceiver;
		pop = interpreterProxy->pop;
		primitiveFailFor = interpreterProxy->primitiveFailFor;
		sizeOfSTArrayFromCPrimitive = interpreterProxy->sizeOfSTArrayFromCPrimitive;
		stackIntegerValue = interpreterProxy->stackIntegerValue;
		stackValue = interpreterProxy->stackValue;
#endif /* !defined(SQUEAK_BUILTIN_PLUGIN) */
	}
	return ok;
}


#ifdef SQUEAK_BUILTIN_PLUGIN

static char _m[] = "MiscPrimitivePlugin";
void* MiscPrimitivePlugin_exports[][3] = {
	{(void*)_m, "getModuleName", (void*)getModuleName},
	{(void*)_m, "primitiveCompareString\000\002", (void*)primitiveCompareString},
	{(void*)_m, "primitiveCompressToByteArray\000\377", (void*)primitiveCompressToByteArray},
	{(void*)_m, "primitiveConvert8BitSigned\000\002", (void*)primitiveConvert8BitSigned},
	{(void*)_m, "primitiveDecompressFromByteArray\000\000", (void*)primitiveDecompressFromByteArray},
	{(void*)_m, "primitiveFindFirstInString\000\002", (void*)primitiveFindFirstInString},
	{(void*)_m, "primitiveFindSubstring\000\002", (void*)primitiveFindSubstring},
	{(void*)_m, "primitiveIndexOfAsciiInString\000\002", (void*)primitiveIndexOfAsciiInString},
	{(void*)_m, "primitiveStringHash\000\001", (void*)primitiveStringHash},
	{(void*)_m, "primitiveTranslateStringWithTable\000\001", (void*)primitiveTranslateStringWithTable},
	{(void*)_m, "setInterpreter", (void*)setInterpreter},
	{NULL, NULL, NULL}
};

#else /* ifdef SQ_BUILTIN_PLUGIN */

signed char primitiveCompareStringAccessorDepth = 2;
signed char primitiveConvert8BitSignedAccessorDepth = 2;
signed char primitiveDecompressFromByteArrayAccessorDepth = 0;
signed char primitiveFindFirstInStringAccessorDepth = 2;
signed char primitiveFindSubstringAccessorDepth = 2;
signed char primitiveIndexOfAsciiInStringAccessorDepth = 2;
signed char primitiveStringHashAccessorDepth = 1;
signed char primitiveTranslateStringWithTableAccessorDepth = 1;

#endif /* ifdef SQ_BUILTIN_PLUGIN */
