Smart Performance library

* C/C++ Example

<pre>
#include "smartPerf.h"
int main () {
    smartPerf::start("Complicated Process");
    run_function1();
    clock_t timeDiff = smartPerf::end(false);

    smartPerf::start("Simple Process");
    run_function2();
    clock_t timeDiff = smartPerf::end(false);
    
    smartPerf::print();
}
</pre>

The sample result: 

<pre> 
+---------------------------------------------+
|          Key         |       CPU Time       |
+---------------------------------------------+
|  Complicated Process |         20 ms        |
|    Simple Process    |        200 ms        |
+---------------------------------------------+
</pre>
