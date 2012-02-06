#!/bin/bash

echo -n > local.h

LOCALTEST="localtest"

echo -n "checking for long size..."

cat << EOF > $LOCALTEST.c
#include <sys/types.h>
#include <stdio.h>
int main() {
    printf("%d", sizeof(long));
}
EOF

gcc -o $LOCALTEST $LOCALTEST.c

if [ -x $LOCALTEST ]; then
    size=`./$LOCALTEST`
    echo " $size bytes"
fi

cat >> local.h << EOF
/*
 * local header file, auto-generated by genlocal.sh
 */
#ifndef LOCAL_H
#define LOCAL_H
#define SIZEOF_LONG $size
#endif
EOF

rm -f $LOCALTEST
rm -f $LOCALTEST.c
