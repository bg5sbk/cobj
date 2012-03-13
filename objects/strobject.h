#ifndef OBJECTS_STROBJECT_H
#define OBJECTS_STROBJECT_H

#include "../object.h"

struct COStrObject {
    COObject_HEAD;
    size_t co_len;
    char co_sval[1];
};

struct COTypeObject COStr_Type;

char *COStr_AsString(COObject *co);
COObject *COStr_FromString(const char *s);
COObject *COStr_FromStingN(const char *s, size_t len);
COObject *COStr_FromFormat(const char *fmt, ...);

#endif
