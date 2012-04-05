#!/usr/bin/env python
#
# Test special cases for syntax consistency.
#

from TAP.Simple import *

plan("no_plan")

test_expect_result("", "", "allow empty code");

# functions
test_expect_result("", "func empty end", "allow empty function body & param list");
test_expect_result("", "func sum (a, b) return a + b end", "function in one line");
test_expect_result("", "func end", "empty function iteral");
test_expect_result("", "func (a,b) return a + b end", "function iteral");

# exeptions
test_expect_result("", "try end", "allow empty try block")

# literal
test_expect_result("""[1, 2]
""", """
print [ 1
, 2
,
]""", "list span multi lines")
