/* One Handed Keyboard based on Arduino USB Keyboard

   You must select Keyboard from the "Tools > USB Type" menu

   This example code is in the public domain.
*/

#include <Bounce.h>

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, 10);
Bounce button1 = Bounce(1, 10);  // 10 = 10 ms debounce time
Bounce button2 = Bounce(2, 10);  // which is appropriate for
Bounce button3 = Bounce(3, 10);  // most mechanical pushbuttons
Bounce button4 = Bounce(4, 10);
Bounce button5 = Bounce(5, 10);  // if a button is too "sensitive"
Bounce button6 = Bounce(6, 10);  // to rapid touch, you can
Bounce button7 = Bounce(7, 10);  // increase this time.
Bounce button8 = Bounce(8, 10);
Bounce button9 = Bounce(9, 10);
Bounce button10 = Bounce(10, 10);
Bounce button11 = Bounce(11, 10);
Bounce button12 = Bounce(12, 10);
Bounce button13 = Bounce(13, 10);
Bounce button14 = Bounce(14, 10);
Bounce button15 = Bounce(15, 10);
Bounce button16 = Bounce(16, 10);
Bounce button17 = Bounce(17, 10);
Bounce button18 = Bounce(18, 10);
Bounce button19 = Bounce(19, 10);
Bounce button20 = Bounce(20, 10);
Bounce button21 = Bounce(21, 10);

// Adjusting for right -> left
// Will likely be wiring dependent.

// Row 1
Bounce b1 = button3;
Bounce b2 = button2;
Bounce b3 = button1;
Bounce b4 = button0;

// Row 2
Bounce b5 = button7;
Bounce b6 = button6;
Bounce b7 = button5;
Bounce b8 = button4;

// Row 3
Bounce b9 = button14;
Bounce b10 = button13;
Bounce b11 = button12;
Bounce b12 = button11;

// Button -> Character code assignements
// left, top, bottom, right
// Configured for right hands, using QWERTY layout.

// Row 1
// u, q, t, 1, \
static int b1_chars[5] = {117, 113, 116, 108, 92};
// i, \, y, 2, /
static int b2_chars[5] =  {105, 34, 121, 50, 47};
// o, e, x, 3, {
static int b3_chars[5] = {111, 101, 120, 51, 123};
// p, r, |, 4, }
static int b4_chars[5] = {112, 114, 124, 52, 125};

// Row 2 -- Home Row
// j, a, g, 5, [
static int b5_chars[5] = {106, 97, 103, 53, 91};
// k, s, h, 6, ]
static int b6_chars[5] = {107, 115, 104, 54, 93};
// l, d, x, 7, (
static int b7_chars[5] = {108, 100, 120, 55, 40};
// ;, f, x, 8, )
static int b8_chars[5] = {59, 102, 120, 56, 41};

// Row 3
// n, z, b, 9, `
static int b9_chars[5] =  {110, 122, 98, 57, 96};
// m, x, x, 0, ~
static int b10_chars[5] = {109, 120, 120, 48, 126};
// , c, x, -, +
static int b11_chars[5] = {44, 99, 120, 45, 43};
// ., v, x, =, _
static int b12_chars[5] = {46, 118, 120, 61, 95};

// 5-way switch remapping logic
// TODO

/*
Toggle structure for the 5-way switch

  3
1 0 4
  2

0 is the default setting, these map to the index in our
char arrays.

*/
int toggle = 0;

void setup() {
  // Configure the pins for input mode with pullup resistors.
  // The pushbuttons connect from each pin to ground.  When
  // the button is pressed, the pin reads LOW because the button
  // shorts it to ground.  When released, the pin reads HIGH
  // because the pullup resistor connects to +5 volts inside
  // the chip.  LOW for "on", and HIGH for "off" may seem
  // backwards, but using the on-chip pullup resistors is very
  // convenient.  The scheme is called "active low", and it's
  // very commonly used in electronics... so much that the chip
  // has built-in pullup resistors!
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);  // Teensy++ LED, may need 1k resistor pullup
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  pinMode(17, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);
  pinMode(19, INPUT_PULLUP);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  b1.update();
  b2.update();
  b3.update();
  b4.update();
  b5.update();
  b6.update();
  b7.update();
  b8.update();
  b9.update();
  b10.update();
  b11.update();
  b12.update();

  
  // Check each button for "falling" edge.
  // Type a message on the Keyboard when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (b1.fallingEdge()) {
    Keyboard.press(b1_chars[toggle]); // Getting variable undefined here, don't know why.
  }
  if (b2.fallingEdge()) {
    Keyboard.press(b2_chars[toggle]);
  }
  if (b3.fallingEdge()) {
    Keyboard.press(b3_chars[toggle]);
  }
  if (b4.fallingEdge()) {
    Keyboard.press(b4_chars[toggle]);
  }
  if (b5.fallingEdge()) {
    Keyboard.press(b5_chars[toggle]);
  }
  if (b6.fallingEdge()) {
    Keyboard.press(b6_chars[toggle]);
  }
  if (b7.fallingEdge()) {
    Keyboard.press(b7_chars[toggle]);
  }
  if (b8.fallingEdge()) {
    Keyboard.press(b8_chars[toggle]);
  }
  if (b9.fallingEdge()) {
    Keyboard.press(b9_chars[toggle]);
  }
  if (b10.fallingEdge()) {
    Keyboard.press(b10_chars[toggle]);
  }
  if (b11.fallingEdge()) {
    Keyboard.press(b11_chars[toggle]);
  }
  if (b12.fallingEdge()) {
    Keyboard.press(b12_chars[toggle]);
  }
    

  // Check each button for "rising" edge
  // Type a message on the Keyboard when each button releases.
  // For many types of projects, you only care when the button
  // is pressed and the release isn't needed.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  
   if (b1.risingEdge()) {
    Keyboard.release(b1_chars[toggle]);
  }
  if (b2.risingEdge()) {
    Keyboard.release(b2_chars[toggle]);
  }
  if (b3.risingEdge()) {
    Keyboard.release(b3_chars[toggle]);
  }
  if (b4.risingEdge()) {
    Keyboard.release(b4_chars[toggle]);
  }
  if (b5.risingEdge()) {
    Keyboard.release(b5_chars[toggle]);
  }
  if (b6.risingEdge()) {
    Keyboard.release(b6_chars[toggle]);
  }
  if (b7.risingEdge()) {
    Keyboard.release(b7_chars[toggle]);
  }
  if (b8.risingEdge()) {
    Keyboard.release(b8_chars[toggle]);
  }
  if (b9.risingEdge()) {
    Keyboard.release(b9_chars[toggle]);
  }
  if (b10.risingEdge()) {
    Keyboard.release(b10_chars[toggle]);
  }
  if (b11.risingEdge()) {
    Keyboard.release(b11_chars[toggle]);
  }
  if (b12.risingEdge()) {
    Keyboard.release(b12_chars[toggle]);
  }

}

