Smart Performance library

* C/C++ Example

<pre>
#include "smartPerf.h"
int main () {
    smartPerf::start("test long long key name1");
    run  xxxx
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
