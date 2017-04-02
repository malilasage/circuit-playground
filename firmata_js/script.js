var five = require('johnny-five');
var pixel = require('node-pixel');

var board = new five.Board();
var strip = null;

board.on('ready', function() {
    // var led = new five.Led(17);
    strip = new pixel.Strip({
      board: this,
      controller: 'FIRMATA',
      strips: [{pin: 17, length: 10}]
    });
    strip.on('ready', function() {
      strip.color('#903');
      strip.show();
    })
    // led.on();
    // led.color("4286f4");
    // led.blink(500);
});
