#!/usr/bin/env python
from TAP.Simple import *

plan(1)

test_expect_result("NameError: name 'unknown' is not defined\n", "print unknown;")
