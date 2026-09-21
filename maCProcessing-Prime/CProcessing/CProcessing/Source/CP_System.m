//---------------------------------------------------------
// file:	CP_System.m
// author:	Hazel Benting
// brief:	Primary implementation of the CProcessing back-end
//
// Copyright � 2026 DigiPen, All rights reserved.
//---------------------------------------------------------

#include "cprocessing.h"
#include "Internal_System.h"
#include "tinycthread.h"
#include "Internal_Graphics.h"

//Set up for Metal Graphics Rendering

#define kMaxFramesInFlight 3

// Internal information
static bool _isInitialized = false;
static bool _isRunning = true;
CP_BOOL _deferredSizeChange = false;
int _deferredWidth = 0;
int _deferredHeight = 0;
CP_BOOL _deferredFullscreen = false;

/*
typedef struct GameStateFuncs
{
	FunctionPtr init;
	FunctionPtr update;
	FunctionPtr exit;
} GameStateFuncs;

GameStateFuncs _currState = { NULL, NULL, NULL };
GameStateFuncs _nextState = { NULL, NULL, NULL };
bool _stateIsChanging = false;

FunctionPtr _preUpdateFunction = NULL;
FunctionPtr _postUpdateFunction = NULL;

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

// FrameRate Control
static double StartingTime, EndingTime, ElapsedSeconds;
static double _frametimeTarget = 1.0 / 60.0;
static double _frametime = 1.0 / 60.0;

// Frames since the start of the program
static unsigned int _frameCount;

//---------------------------------------------------------
// ENGINE:
//		Functions managing code flow

// Run begins the CProcessing engine and starts calling init, update and exit functions.
// This is the start and core of any C Processing program.

void CP_SetWindowSizeInternal(int new_width, int new_height, bool isFullscreen)
{
    if ([view.device supportsFamily:MTLGPUFamilyMetal4]) {
        renderer = [[Metal4Renderer alloc] initWithMetalKitView:view];
    }
}

void CP_Engine_Run(void)
{
	if (_isInitialized)
	{
		// don't allow multiple Run loops
		return;
	}

	// initialize the CProcessing Engine
    //CP_Initialize();

	// main loop
	while (_isRunning)
	{
		//CP_FrameStart();
		//CP_Update();

		if (_preUpdateFunction) _preUpdateFunction();

		// change states and call associated functions
		if (_stateIsChanging)
		{
			// exit current state
			if (_currState.exit) _currState.exit();

			// switch state tracking variables
			_currState.init = _nextState.init;
			_currState.update = _nextState.update;
			_currState.exit = _nextState.exit;

			// init
			if (_currState.init) _currState.init();

			_stateIsChanging = false;
		}

		if (_currState.update) _currState.update();

		if (_postUpdateFunction) _postUpdateFunction();

		//CP_FrameEnd();
	}

	// Exit the current state when the program is terminating
	if (_currState.exit) _currState.exit();

	//CP_Shutdown();
}

 void CP_Engine_Terminate(void)
{
	// Terminate Program
}

// Set the init, update and exit functions which CProcessing will call.
// This is aware of the current state and won't re-initialize if called with the same functions.
// update must have a valid input function, init and exit may be NULL if desired.
 void CP_Engine_SetNextGameState(FunctionPtr init, FunctionPtr update, FunctionPtr exit)
{
	if (update == NULL || (_currState.init == init && _currState.update == update && _currState.exit == exit))
	{
		return;
	}

	CP_Engine_SetNextGameStateForced(init, update, exit);
}

// This forcefully overrides the current state so you can call this function
// with the same inputs and it will cause the state to exit and re-initialize.
// update must have a valid input function, init and exit may be NULL if desired.
 void CP_Engine_SetNextGameStateForced(FunctionPtr init, FunctionPtr update, FunctionPtr exit)
{
	_stateIsChanging = true;
	_nextState.init = init;
	_nextState.update = update;
	_nextState.exit = exit;
}

 void CP_Engine_SetPreUpdateFunction(FunctionPtr preUpdateFunction)
{
	_preUpdateFunction = preUpdateFunction;
}

 void CP_Engine_SetPostUpdateFunction(FunctionPtr postUpdateFunction)
{
	_postUpdateFunction = postUpdateFunction;
}


//---------------------------------------------------------
// SYSTEM:
//		OS functions supporting window management and timing

 void CP_System_SetWindowSize(int new_width, int new_height)
{
	//Set Window Size
}

 void CP_System_SetWindowPosition(int x, int y)
{
	//Set Window Position
}

 void CP_System_Fullscreen(void)
{
	//Start in fullscreen
}

 void CP_System_FullscreenAdvanced(int targetWidth, int targetHeight)
{
	//Better Fullscreen
}

 int CP_System_GetWindowWidth(void)
{
     return 0;
}

 int CP_System_GetWindowHeight(void)
{
	return 0;
}

 int CP_System_GetDisplayWidth(void)
{
	return 0;
}

 int CP_System_GetDisplayHeight(void)
{
	return 0;
}

 int CP_System_GetDisplayRefreshRate(void)
{
	return 0;
}

// HWND CP_System_GetWindowHandle(void)
//{
	//return _CORE.hwnd;
//}

 void CP_System_SetWindowTitle(const char* title)
{
	
}

 bool CP_System_GetWindowFocus(void)
{
	return true;
}

 void CP_System_ShowCursor(CP_BOOL show)
{
	
}

 unsigned CP_System_GetFrameCount(void)
{
	return _frameCount;
}

 float CP_System_GetFrameRate(void)
{
	return (float)(1.0 / _frametime);
}

 void CP_System_SetFrameRate(float fps)
{
	_frametimeTarget = 1.0 / fps; // seconds per frame
}

 float CP_System_GetDt(void)
{
	return (float)_frametime;
}

 float CP_System_GetMillis(void)
{
	return 0;
}

 float CP_System_GetSeconds(void)
{
	return 0;
}


//---------------------------------------------------------
// INTERNAL Engine and System:
//		Support functions not exposed to the user

void CP_Initialize(void)
{
	if (_isInitialized == true)
		return;

	// Initialize random number generators
	// (Random first so Noise can use the better RNG)
	CP_Random_Init();
	CP_NoiseInit();

	// Set the background color
	CP_Graphics_ClearBackground(CP_Color_Create(150, 150, 150, 255));

	// Text Init
    CP_Text_Init();

	// Image Init
	CP_Image_Init();

	_isInitialized = true;
}

void CP_Update(void)
{
	// Update Input
	//CP_Input_Update();

	// Audio Update
	//CP_Sound_Update();

	// Image Update
	CP_Image_Update();
}

void CP_Shutdown(void)
{
	CP_Text_Shutdown();
	//CP_Sound_Shutdown();
	CP_Image_Shutdown();
}

void CP_FrameStart(void)
{
    //CP_FrameRate_FrameStart();
    
    if (_deferredSizeChange)
    {
        _deferredSizeChange = false;
        //CP_DeferredSetWindowSizeInternal(_deferredWidth, _deferredHeight, _deferredFullscreen);
    }
    
}

void CP_FrameEnd(void)
{
    
}

void CP_IncFrameCount(void)
{
	++_frameCount;
}

void CP_FrameRate_Init(void)
{
	// start the app at frame zero
	_frameCount = 0;
}

void CP_FrameRate_FrameStart(void)
{

	// Update frame count
	CP_IncFrameCount();
}

double averageSleepCycles = 0.002;
double additionalBuffer = 0.001;	// Sleep() isn't very accurate and we want to make sure we don't over sleep

void CP_FrameRate_FrameEnd(void)
{
	double prevSeconds = 0;
	double currSeconds = 0;

	do
	{

		// compute remaining microseconds in the frame
		currSeconds = _frametimeTarget - ElapsedSeconds;

		// if our remaining microseconds this frame are greater than the Sleep function's
		// average margin of error (plus an additional buffer value) then go ahead and Sleep
		if (currSeconds > averageSleepCycles + additionalBuffer)
		{
			prevSeconds = currSeconds;

			// give back cycles to other processes if we don't need them
			thrd_sleep(&(struct timespec) { .tv_nsec = 1000000 }, NULL);	// sleep 1 millisecond

			// update the time after sleeping

			// recompute remaining micros
			currSeconds = _frametimeTarget - ElapsedSeconds;

			// update the average sleep over 16 samples so we maintain awareness of the system's margin of error.
			averageSleepCycles = ((averageSleepCycles * 15.0) + (prevSeconds - currSeconds)) / 16.0;	// multiply by 15, add new sample, divide by 16
		}

	} while (ElapsedSeconds < _frametimeTarget);

	// Update time of the last frame
	_frametime = ElapsedSeconds;
}

void CP_UpdateFrameTime(void)
{
	ElapsedSeconds = EndingTime - StartingTime;
}
*/
