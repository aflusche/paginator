# paginator
reMarkable 2 is a great tablet for sheet music, except there's no way to turn the page when you play a two-handed instrument.

I started out trying to make a version of the [remarkable footpedal](https://github.com/reini1305/remarkable_footpedal), but I couldn't get a solid pogo pin connection.

I then decided to go for the [pageturner](https://github.com/FunkyFab/pageturner) version, but I wanted a sleeker design with less trip hazards involved. :)

My final device is a mashup of both. It is a self-contained, battery-powered pedal that connects to the USB-C port on the reMarkable 2. Using [this](https://www.amazon.com/dp/B0C7GCQVC6) low-profile USB cable, the tablet still sits nicely on its own bottom, even on a music stand.

**Video demo on YouTube:**

[![YouTube demo video](https://raw.githubusercontent.com/aflusche/paginator/main/thumbnail_small.png)](https://youtu.be/zBM0Pr0DNEA)

**What the inside of the pedal looks like:**

![paginator guts](https://raw.githubusercontent.com/aflusche/paginator/main/inside_with_light_small.jpg)

Build instructions are [here](build.md).

## features

#### navigation on the reMarkable
- Short press = next page
- Long press (750 ms to 1500 ms) = previous page
- Longer press (> 2.5 seconds) = flip back 4 pages, then close current doc (used to changed to the next song)

#### status LEDs
- orange LED at front displays when power on / off. Also flashes 1, 2, or 3 times to confirm press version.
- red LED on side illuminates when charging battery
- green LED on side illuminates when battery full

#### power
- 3.7v LIPO battery
- charges via the USB-C port on the pedal
- auto powers off after 2 hours of inactivity
- press the silver switch to turn pedal on
- hold the silver switch 5 seconds to turn pedal off
