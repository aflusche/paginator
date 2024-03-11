# build instructions

## materials

- pedal - Yamaha FC5 sustain pedal - [Amazon](https://www.amazon.com/gp/product/B00005ML71/) - $14.95 (I first tried one of [these](https://www.digikey.com/en/products/detail/adafruit-industries-llc/423/5353597) from Digikey, but it has a LOUD click.)
- Teensy 4.0 - the brains - [Teensy](https://www.pjrc.com/store/teensy40.html) - $23.80
- power switch - these from [Amazon](https://www.amazon.com/gp/product/B09DJY5Y5L/) perfectly fit the hole in the Yamaha pedal - $5.99
- battery - [Amazon](https://www.amazon.com/gp/product/B08214DJLJ/) - $13.99
- micro-lipo charger - [Adafruit](https://www.adafruit.com/product/1904) - $6.99
- light pipe / fiber optics - [Amazon](https://www.amazon.com/gp/product/B09J15KT2H/) - $7.09
- hookup wire
- hot glue
- USB C cable - for connecting paginator to reMarkable - [Amazon](https://www.amazon.com/gp/product/B0C7GCQVC6/) - $16.99
- USB C to micro USB adapter - to connect the cable to the Teensy micro USB port - [Amazon](https://www.amazon.com/gp/product/B0B8PBDZS9/) - $6.88

## steps

1. Open the pedal by removing the screws on each side. De-solder the wire from the switch. Remove the wire and discard.
2. Using a step drill bit, drill two large holes in the pedal to accommodate the USB ports for both the Teensy and the micro-lipo charger. Drill them very close to the bottom of the pedal. *Mine are slightly too high, so the pedal top interferes a bit with the charging port.*
3. Solder everything together as pictured.5. Load the [Arduino sketch](pedal2.ino) onto the Teensy.
4. Plug the USB C cable into a computer to test that you can actually send the "right arrow" and "left arrow" keys to the computer.
5. Follow [FunkyFab's instructions](https://github.com/FunkyFab/pageturner/wiki/Enabling-the-USB-C-port-of-the-reMarkable-2-tablet-in-host-mode) to get your reMarkable USB input working.
6. Plug the USB C cable into the reMarkable to make sure that works. *I had many struggles getting this working. I had to uninstall ddvk from my reMarkable. I also couldn't get it work on any software version higher than 2.13.*
7. Once it's all working, test fit into the pedal. Do a complete test with the top of the pedal screwed on. Make sure you can actually plug cables into the rear USB ports as needed. *see my note on #2 above*
8. Once it's for sure good, mark holes for the light pipes. Drill those holes and cut your light pipes to fit. *I used a utility knife, which didn't give me a very clean cut.*
9. Glue everything into place with hot glue.
