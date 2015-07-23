var Table = require('easy-table');
var timeData = {};
var recordData = [];
var lastItemName = "";


exports.start = function (key) {
    var startTime;
    if (key == undefined) key = "default";
    startTime = (new Date()).getTime();
    timeData[key] = startTime;
    lastItemName = key;
}

exports.end = function (display) {
    var startTime, endTime, diffMs, key;
    display = (display == undefined) ? true: display ;
    key = (timeData[lastItemName]) ? lastItemName : 'default' ;
    startTime = timeData[key];
    endTime = (new Date()).getTime();
    diffMs = parseInt(endTime, 10) - parseInt(startTime, 10);
    recordData.push({key: key, time: diffMs});
    if (true === display) {
        console.log(lastItemName + ": time diff = " + diffMs +" ms");
    }
}

exports.print = function () {
    var t = new Table();

    for (var i in recordData) {
        rec = recordData[i];
        t.cell('Key', rec.key);
        t.cell('CPU(ms)', rec.time  + " ms");
         t.newRow()
    }
    console.log(t.toString());
}

exports.clear = function () {
    timeData = {};
    recordData = [];
}

