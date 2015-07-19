<pre>
    smartPerf::start("test long long key name1");
    run  xxxx
    clock_t timeDiff = smartPerf::end(false);

    smartPerf::print();
    
---------------------------------------------------------
|            Key            |          CPU Time         |
|-------------------------------------------------------|
|  test long long key name1 |           200 ms          |
|           test2           |           20 ms           |
---------------------------------------------------------
</pre>
