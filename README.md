Smart Performance library

* C/C++ Example

<pre>
#include "smartPerf.h"
int main () {
    smartPerf::start("Complicated Process");
    run_test_function1();
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

* Node Example
* npm install -g smart-perf

<pre>
var smartPerf = require("smart-perf");
smartPerf.start("Linear search");
run_linear_search();
smartPerf.end(false);

smartPerf.start("Binary search");
run_binary_search();
smartPerf.end(false);

smartPerf.print();
</pre>

The sample result:

<pre>
Key            CPU(ms)
-------------  -------
Linear search  207 ms
Binary search  129 ms
</pre>
