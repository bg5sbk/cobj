#include "../cobj.h"

static COObject *
cfunction_repr(COCFunctionObject *this)
{
    COObject *s;
    s = COStr_FromFormat("<cfunction '%s'>", this->c_name);
    return s;
}

static void
cfunction_dealloc(COCFunctionObject *this)
{
    COObject_Mem_FREE(this);
}

COTypeObject COCFunction_Type = {
    COVarObject_HEAD_INIT(&COType_Type, 0),
    "cfunction",
    sizeof(COCFunctionObject),
    0,
    0,
    0,                          /* tp_alloc */
    0,                          /* tp_init */
    (deallocfunc)cfunction_dealloc,     /* tp_dealloc */
    (reprfunc)cfunction_repr,   /* tp_repr */
    0,                          /* tp_print */
    0,                          /* tp_hash */
    0,                          /* tp_compare */
    0,                          /* tp_traverse */
    0,                          /* tp_clear */
    0,                          /* tp_call */
    0,                          /* tp_iter */
    0,                          /* tp_iternext */
    0,                          /* tp_arithmetic_interface */
    0,                          /* tp_mapping_interface */
    0,                          /* tp_sequence_interface */
};

COObject *
COCFunction_New(const char *name, COCFunction func)
{
    COCFunctionObject *this =
        COObject_NEW(COCFunctionObject, &COCFunction_Type);
    if (!this)
        return NULL;

    this->c_name = name;
    this->c_func = func;

    return (COObject *)this;
}
