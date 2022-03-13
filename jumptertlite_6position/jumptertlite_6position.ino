/*
 *      ___         __
 *     |   |.-----.|  |--.-----.-----.--.--.
 *   __|   ||  _  ||     |     |  -__|_   _|
 *   |_____||_____||__|__|__|__|_____|__.__|
 *    Jumper T-Lite - 6 Position Switch Mod
 *
 * -------------------------------------------
 * (C) 2022 John Norrbin <jlnorrbin@johnex.se>
 *
 */

// Global Variables
u16 g_u16KnobVal = 0;
u8  g_u8Pos = 1, g_u8OldPos = 0;

// Setup
void setup() {}

// Loop
void loop()
{
    // Read Knob Value
    g_u16KnobVal = u16(analogRead(A0));

    // Switch Position
    switch (g_u16KnobVal)
    {
        case 0   ... 100  : g_u8Pos = 1; break;
        case 101 ... 225  : g_u8Pos = 2; break;
        case 226 ... 295  : g_u8Pos = 3; break;
        case 296 ... 425  : g_u8Pos = 4; break;
        case 426 ... 760  : g_u8Pos = 5; break;
        case 761 ... 1024 : g_u8Pos = 6; break;
    }

    // Check Previous Position
    if (g_u8Pos != g_u8OldPos)
    {
        // Switch Outputs
        switch (g_u8Pos)
        {
            case 1: DDRD = B00001000; break;
            case 2: DDRD = B00000000; break;
            case 3: DDRD = B00010000; break;
            case 4: DDRD = B00001100; break;
            case 5: DDRD = B00000100; break;
            case 6: DDRD = B00010100; break;
        }

        // Update Position
        g_u8OldPos = g_u8Pos;
    }
}
