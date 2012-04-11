#ifndef STATE_H
#define STATE_H
/**
 * State etc.
 */

#include "object.h"

typedef struct _COThreadState {
    COObject *mainfunc;
    COObject *funcargs;
    COObject *frame;

    COObject *curexc_type;
    COObject *curexc_value;
    COObject *curexc_traceback;
} COThreadState;

COThreadState *threadstate_current;
#define TS(o)    (threadstate_current)->o

COThreadState *COThreadState_New();

#endif
