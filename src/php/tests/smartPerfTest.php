<?php

require __DIR__ . "/../smartPerf.php";

class smartPerfTest extends PHPUnit_Framework_TestCase{

    public function setup() {

    }

    public function teardown() {

    }


    public function testMain() {
        smartPerf::start("Linear search");
        $num = 1;
        usleep(1000*500);

        $t1 = smartPerf::end();

        smartPerf::start("Binary search");
        $num = 1;
        usleep(1000 * 300);
        $t2 = smartPerf::end();

        smartPerf::printRecord();

        $this->assertEquals(5, substr($t1, 0, 1));
        $this->assertEquals(3, substr($t2, 0, 1));


    }

}
