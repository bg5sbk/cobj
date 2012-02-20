#include "co.h"
#include "hash.h"
#include "parser.h"
#include "scanner.h"
#include "compile.h"
#include "vm_execute.h"

int
main(int argc, const char **argv)
{
    int fd = 0;
    if (argc > 1) {
        argv++;
        fd = open(*argv, O_RDONLY);
        if (fd < 0) {
            die("open %s failed", *argv);
        }
    }

    /* compilation */
    co_scanner_startup();
    co_scanner_openfile(fd);
    init_compiler();
    coparse(&compiler_globals);
    co_scanner_shutdown();

    /* vm execution */
    co_vm_init();
    co_vm_execute(CG(active_op_array));
    return 0;
}
