#ifndef __UTIL_H__
#define __UTIL_H__

#include <EDSDKTypes.h>

const char* getPropertyName( EdsUInt32 );
const char* getDataTypeName( EdsDataType  );
const char* getObjectEventName( EdsObjectEvent );
const char* getStateEventName( EdsStateEvent );
const char* getPropertyEventName( EdsPropertyEvent );

void dumpProperties( EdsBaseRef );

#endif /*__UTIL_H__*/
