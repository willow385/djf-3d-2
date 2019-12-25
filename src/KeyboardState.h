namespace djf_3d {

/* This struct is used to describe the state of the keyboard.
   It is the return type of djf_3d::Canvas::get_keyboard_state().
   When that method is called, it returns a KeyboardState where
   the keys that were pressed at the time of the method call are
   given a value of "true" and the keys that were not pressed are
   given a value of "false". The "dig_*" members correspond to the
   number keys at the top of a QWERTY keyboard; the rest should
   be self-explanatory by their names. */

typedef struct {
    bool escape;
    bool backtick;
    bool dig_1;
    bool dig_2;
    bool dig_3;
    bool dig_4;
    bool dig_5;
    bool dig_6;
    bool dig_7;
    bool dig_8;
    bool dig_9;
    bool dig_0;
    bool hyphen;
    bool equals;
    bool backspace;
    bool tab;
    bool Q;
    bool W;
    bool E;
    bool R;
    bool T;
    bool Y;
    bool U;
    bool I;
    bool O;
    bool P;
    bool open_bracket;
    bool close_bracket;
    bool back_slash;
    bool A;
    bool S;
    bool D;
    bool F;
    bool G;
    bool H;
    bool J;
    bool K;
    bool L;
    bool semicolon;
    bool quote;
    bool enter;
    bool shift;
    bool Z;
    bool X;
    bool C;
    bool V;
    bool B;
    bool N;
    bool M;
    bool comma;
    bool period;
    bool forward_slash;
    bool ctrl;
    bool home;
    bool alt;
    bool left_arr;
    bool up_arr;
    bool down_arr;
    bool right_arr;
} KeyboardState;

} // end of namespace djf_3d
