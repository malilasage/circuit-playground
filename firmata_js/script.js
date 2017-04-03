var five = require('johnny-five');
var pixel = require('node-pixel');

var board = new five.Board();
var strip = null;
// var neoPixel = null;

board.on('ready', function() {
    strip = new pixel.Strip({
      board: this,
      controller: 'FIRMATA',
      strips: [{pin: 17, length: 10}]
    });
    strip.on('ready', function() {
      strip.color('#110000');
      // strip.show();
      var counter = 1;
      setInterval(function() {
        counter % 2 === 0 ? strip.color('#110000') : strip.color('#000000');
        // console.log(strip.color());
        strip.show();
        counter++;
      }, 1000);
    })
    // neoPixel.on('ready', function() {
    //   console.log('neopixel');
    //   neoPixel.color('#903');
    //   neoPixel.show();
    // });
    // led.color("4286f4");
    // led.blink(500);
});
