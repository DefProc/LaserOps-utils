# hashDecode.ino Example sketch for IRLib2

Instead of decoding using a standard encoding scheme
(e.g. Sony, NEC, RC5), the code is hashed to a 32-bit value.
This should produce a unique 32-bit number however that number
cannot be used to retransmit the same code. This is just a quick
and dirty way to detect a unique code for controlling a device
when you don't really care what protocol or values are being sent.

This is an almost exact copy of the libary example original adjusted for the
Circuit Playground Express: 

 * https://github.com/cyborg5/IRLib2/blob/master/IRLib2/examples/hashDecode/hashDecode.ino
