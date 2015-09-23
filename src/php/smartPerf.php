<?php

class smartPerf {
    static protected $timeData;
    static protected $recordData;
    static protected $lastItemName;

    static public function clear() {
        self::$timeData = array();
        self::$recordData = array();
        self::$lastItemName = "";
    }

    static public function end() {
        $startTime = self::$timeData[self::$lastItemName];
        list($usec, $sec) = explode(" ", microtime());
        $endTime = $sec*1000 + intval($usec*1000);

        self::$recordData[self::$lastItemName] = $endTime - $startTime;
        return self::$recordData[self::$lastItemName];
    }

    static public function printRecord() {
        $maxWidth = 16;
        $maxKeyLength = 1;
        $fieldNum = 2; 
        foreach (self::$recordData as $name => $ms) {
            if (strlen($name) > $maxKeyLength) $maxKeyLength = strlen($name);

//            echo $name . " = " . $ms . "\n";
        }
        if ($maxKeyLength % 2 ==1) $maxKeyLength++;
        if ($maxKeyLength > $maxWidth) $maxWidth = $maxKeyLength + 2;
        
        $borderLen = $maxWidth * $fieldNum +  (1 + $fieldNum);

        $border = "+";
        for ($i = 0 ; $i < $borderLen; $i++)  $border .= '-';
        $border .= "+\n";

        echo "\n";
        echo $border;
        echo "|";
        echo self::printByWidth("Key", $maxWidth);
        echo "|";
        echo self::printByWidth("CPU(ms)", $maxWidth);
        echo "|\n";
        echo $border;

        foreach (self::$recordData as $name => $ms) {
            echo "|";
            echo self::printByWidth($name, $maxWidth);
            echo "|";
            echo self::printByWidth($ms, $maxWidth);
            echo "|\n";
        }

        echo $border;

    }

    static public function printByWidth($str, $maxLength) {
        $len = strlen($str);
        $spaceLen = ($maxLength - $len) /2;
        $space = "";
        for ($i = 0; $i < $spaceLen; $i++) $space .= " ";
        echo $space;
        echo $str;
        echo $space;
    }

    static public function start($name) {
        list($usec, $sec) = explode(" ", microtime());
        self::$timeData[$name] = $sec*1000 + intval($usec*1000);
        self::$lastItemName = $name;
    }

}
