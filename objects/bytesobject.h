#ifndef OBJECTS_BYTESOBJECT_H
#define OBJECTS_BYTESOBJECT_H
/**
 * Bytes object interface
 * 
 * The COBytesObject represents a mutable array of bytes.
 * A byte is from 0 to 255.
 */
#include "../object.h"

typedef struct _COBytesObject {
    COObject_HEAD;
    size_t co_size;
    size_t co_alloc;            /* bytes allocaed */
    char *co_bytes;
} COBytesObject;

COTypeObject COBytes_Type;

#define COBytes_Check(co) (CO_TYPE(co) == &COBytes_Type)

char *COBytes_AsString(COObject *co);
COObject *COBytes_FromString(const char *bytes);
COObject *COBytes_FromStringN(const char *bytes, size_t len);
void COBytes_Concat(COObject **pv, COObject *bytes);
int COBytes_Resize(COObject *this, size_t newsize);
size_t COBytes_Size(COObject *this);

#endif
