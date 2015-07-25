 
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
