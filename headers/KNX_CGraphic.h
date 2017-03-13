#ifndef KNX_CGRAPH
#define KNX_CGRAPH

/*
Interactive control graphics

The following structures and methods allow for simple
creation of text based GUI's, with peripheral support.
*/

//declares
typedef struct cgBuffer cgBuffer;
//base control structure
typedef struct cgComponent cgComponent;
//main display structure
typedef struct cgConsole cgConsole;
//independant viewport
typedef struct cgWindow cgWindow;

//default structures
typedef struct cgTextBox cgTextBox;
typedef struct cgTextArea cgTextArea;
typedef struct cgScrollBar cgScrollBar;
typedef struct cgLoadBar cgLoadBar;
typedef struct cgButton cgButton;
typedef struct cgToggle cgToggle;
typedef struct cgRadio cgRadio;
typedef struct cgLabel cgLabel;

//TODO add static type size registry. Allow for custom type registration

//signatures
//update object
typedef  void (*f_update)();
//resize object buffer to X and Y
typedef  void (*f_resize)(cgBuffer, size_t, size_t);
//add new component to set {set}{component}{size pointer}
typedef  void (*f_addcomponent)(cgComponent**, cgComponent*, size_t*);

typedef struct cgBuffer{
  size_t width, height;
  char * buffer;
}cgBuffer;

typedef struct cgWindow{
  cgBuffer buffer;
  size_t componentCount;
  cgComponent ** components;

  f_update update;
  f_resize resize;
}cgWindow;

typedef struct cgComponent{
  f_update update;
}cgComponent;

typedef struct cgTextBox{
  cgComponent * base;
}cgTextBox;


//default method

#endif
