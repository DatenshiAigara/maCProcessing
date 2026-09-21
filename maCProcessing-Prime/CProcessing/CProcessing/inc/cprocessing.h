//---------------------------------------------------------
// CProcessing
// A functional programming library focusing on game development
//
// author:			Justin Chambers
// contributors:	Daniel Hamilton, Zachary Logsdon,
//					Andrea Ellinger, Jason Thiel, Kenny Mecham
//
// project and documentation:
// https://github.com/DigiPen-Faculty/CProcessing
//
//---------------------------------------------------------
// MIT License
// 
// Copyright(c) 2021 DigiPen Institute of Technology
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// 
//---------------------------------------------------------
// Acknowledgment:
//
// NanoVG by Mikko Mononen
// FMOD Studio by Firelight Technologies Pty Ltd.
// 
//---------------------------------------------------------

#pragma once

#ifdef __cplusplus
extern "C"
{
#endif

#include "cprocessing_common.h"

/*

//---------------------------------------------------------
// ENGINE:
//		Functions managing code flow
void CP_Engine_Run(void);
void CP_Engine_Terminate(void);
void CP_Engine_SetNextGameState(FunctionPtr init, FunctionPtr update, FunctionPtr exit);
void CP_Engine_SetNextGameStateForced(FunctionPtr init, FunctionPtr update, FunctionPtr exit);
void CP_Engine_SetPreUpdateFunction(FunctionPtr preUpdateFunction);
void CP_Engine_SetPostUpdateFunction(FunctionPtr postUpdateFunction);

//---------------------------------------------------------
// SYSTEM:
//		OS functions supporting window management and timing
void CP_System_SetWindowSize(int new_width, int new_height);
void CP_System_SetWindowPosition(int x, int y);
void CP_System_Fullscreen(void);
void CP_System_FullscreenAdvanced(int targetWidth, int targetHeight);
int CP_System_GetWindowWidth(void);
int CP_System_GetWindowHeight(void);
int CP_System_GetDisplayWidth(void);
int CP_System_GetDisplayHeight(void);
int CP_System_GetDisplayRefreshRate(void);
//HWND CP_System_GetWindowHandle(void);
void CP_System_SetWindowTitle(const char* title);
bool CP_System_GetWindowFocus(void);
void CP_System_ShowCursor(CP_BOOL show);
unsigned CP_System_GetFrameCount(void);
float CP_System_GetFrameRate(void);
void CP_System_SetFrameRate(float fps);
float CP_System_GetDt(void);
float CP_System_GetMillis(void);
float CP_System_GetSeconds(void);

//---------------------------------------------------------
// SETTINGS:
//		Render settings
void CP_Settings_Fill(CP_Color c);
void CP_Settings_NoFill(void);
void CP_Settings_Stroke(CP_Color c);
void CP_Settings_NoStroke(void);
void CP_Settings_StrokeWeight(float weight);
void CP_Settings_Tint(CP_Color c);
void CP_Settings_NoTint(void);
void CP_Settings_AntiAlias(CP_BOOL antiAlias);
void CP_Settings_LineCapMode(CP_LINE_CAP_MODE capMode);
void CP_Settings_LineJointMode(CP_LINE_JOINT_MODE jointMode);
void CP_Settings_RectMode(CP_POSITION_MODE mode);
void CP_Settings_EllipseMode(CP_POSITION_MODE mode);
void CP_Settings_ImageMode(CP_POSITION_MODE mode);
void CP_Settings_BlendMode(CP_BLEND_MODE blendMode);
void CP_Settings_ImageFilterMode(CP_IMAGE_FILTER_MODE filterMode);
void CP_Settings_ImageWrapMode(CP_IMAGE_WRAP_MODE wrapMode);
void CP_Settings_TextSize(float size);
void CP_Settings_TextAlignment(CP_TEXT_ALIGN_HORIZONTAL h, CP_TEXT_ALIGN_VERTICAL v);
void CP_Settings_Scale(float xScale, float yScale);
void CP_Settings_Rotate(float degrees);
void CP_Settings_Translate(float x, float y);
void CP_Settings_ApplyMatrix(CP_Matrix matrix);
void CP_Settings_ResetMatrix(void);
void CP_Settings_Save(void);
void CP_Settings_Restore(void);

//---------------------------------------------------------
// COLOR:
//		RGBA values are in the range of 0-255
//		HSLA values are h (0-360), s (0-100), l (0-100), a (0-255)
CP_Color CP_Color_Create(int r, int g, int b, int a);
CP_Color CP_Color_CreateHex(int hexCode);
CP_Color CP_Color_Lerp(CP_Color a, CP_Color b, float t);
CP_Color CP_Color_FromColorHSL(CP_ColorHSL hsl);
CP_ColorHSL CP_ColorHSL_Create(int h, int s, int l, int a);
CP_ColorHSL CP_ColorHSL_Lerp(CP_ColorHSL a, CP_ColorHSL b, float t);
CP_ColorHSL CP_ColorHSL_FromColor(CP_Color rgb);

//---------------------------------------------------------
// GRAPHICS:
//		Functions related to drawing primitive shapes
void CP_Graphics_ClearBackground(CP_Color c);
void CP_Graphics_DrawPoint(float x, float y);
void CP_Graphics_DrawLine(float x1, float y1, float x2, float y2);
void CP_Graphics_DrawLineAdvanced(float x1, float y1, float x2, float y2, float degrees);
void CP_Graphics_DrawRect(float x, float y, float w, float h);
void CP_Graphics_DrawRectAdvanced(float x, float y, float w, float h, float degrees, float cornerRadius);
void CP_Graphics_DrawEllipse(float x, float y, float w, float h);
void CP_Graphics_DrawEllipseAdvanced(float x, float y, float w, float h, float degrees);
void CP_Graphics_DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3);
void CP_Graphics_DrawTriangleAdvanced(float x1, float y1, float x2, float y2, float x3, float y3, float degrees);
void CP_Graphics_DrawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
void CP_Graphics_DrawQuadAdvanced(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float degrees);
void CP_Graphics_BeginShape(void);
void CP_Graphics_AddVertex(float x, float y);
void CP_Graphics_EndShape(void);

//---------------------------------------------------------
// IMAGE:
//		All functions related to loading, creating, and drawing images
CP_Image CP_Image_Load(const char* filepath);
void CP_Image_Free(CP_Image* img);
int CP_Image_GetWidth(CP_Image img);
int CP_Image_GetHeight(CP_Image img);
void CP_Image_Draw(CP_Image img, float x, float y, float w, float h, int alpha);
void CP_Image_DrawAdvanced(CP_Image img, float x, float y, float w, float h, int alpha, float degrees);
void CP_Image_DrawSubImage(CP_Image img, float x, float y, float w, float h, float u0, float v0, float u1, float v1, int alpha);
void CP_Image_DrawSubImageAdvanced(CP_Image img, float x, float y, float w, float h, float u0, float v0, float u1, float v1, int alpha, float degrees);
CP_Image CP_Image_CreateFromData(int w, int h, unsigned char* pixelDataInput);
CP_Image CP_Image_Screenshot(int x, int y, int w, int h);
void CP_Image_GetPixelData(CP_Image img, CP_Color* pixelDataOutput);
void CP_Image_UpdatePixelData(CP_Image img, CP_Color* pixelDataInput);

//---------------------------------------------------------
// SOUND:
//		All functions related to loading and playing sounds
 CP_Sound CP_Sound_Load(const char* filepath);
 CP_Sound CP_Sound_LoadStream(const char* filepath);
 void CP_Sound_Free(CP_Sound* sound);
 void CP_Sound_Play(CP_Sound sound);
 void CP_Sound_PlayAdvanced(CP_Sound sound, float volume, float pitch, CP_BOOL looping, CP_SOUND_GROUP group);
 void CP_Sound_PauseAll(void);
 void CP_Sound_PauseGroup(CP_SOUND_GROUP group);
 void CP_Sound_ResumeAll(void);
 void CP_Sound_ResumeGroup(CP_SOUND_GROUP group);
 void CP_Sound_StopAll(void);
 void CP_Sound_StopGroup(CP_SOUND_GROUP group);
 void CP_Sound_SetGroupVolume(CP_SOUND_GROUP group, float volume);
 float CP_Sound_GetGroupVolume(CP_SOUND_GROUP group);
 void CP_Sound_SetGroupPitch(CP_SOUND_GROUP group, float pitch);
 float CP_Sound_GetGroupPitch(CP_SOUND_GROUP group);

//---------------------------------------------------------
// FONT:
//		All functions related to loading and drawing fonts
 CP_Font CP_Font_GetDefault(void);
 CP_Font CP_Font_Load(const char* filepath);
 void CP_Font_Free(CP_Font* font);
 void CP_Font_Set(CP_Font font);
 void CP_Font_DrawText(const char* text, float x, float y);
 void CP_Font_DrawTextBox(const char* text, float x, float y, float rowWidth);

//---------------------------------------------------------
// INPUT:
//		Keyboard, mouse and gamepad support
 CP_BOOL CP_Input_KeyTriggered(CP_KEY keyCode);
 CP_BOOL CP_Input_KeyReleased(CP_KEY keyCode);
 CP_BOOL CP_Input_KeyDown(CP_KEY keyCode);
 CP_BOOL CP_Input_MouseTriggered(CP_MOUSE button);
 CP_BOOL CP_Input_MouseReleased(CP_MOUSE button);
 CP_BOOL CP_Input_MouseDown(CP_MOUSE button);
 CP_BOOL CP_Input_MouseMoved(void);
 CP_BOOL CP_Input_MouseClicked(void);
 CP_BOOL CP_Input_MouseDoubleClicked(void);
 CP_BOOL CP_Input_MouseDragged(CP_MOUSE button);
 float CP_Input_MouseWheel(void);
 float CP_Input_GetMouseX(void);
 float CP_Input_GetMouseY(void);
 float CP_Input_GetMousePreviousX(void);
 float CP_Input_GetMousePreviousY(void);
 float CP_Input_GetMouseDeltaX(void);
 float CP_Input_GetMouseDeltaY(void);
 float CP_Input_GetMouseWorldX(void);
 float CP_Input_GetMouseWorldY(void);
 CP_BOOL CP_Input_GamepadTriggered(CP_GAMEPAD button);
 CP_BOOL CP_Input_GamepadTriggeredAdvanced(CP_GAMEPAD button, unsigned gamepadIndex);
 CP_BOOL CP_Input_GamepadReleased(CP_GAMEPAD button);
 CP_BOOL CP_Input_GamepadReleasedAdvanced(CP_GAMEPAD button, unsigned gamepadIndex);
 CP_BOOL CP_Input_GamepadDown(CP_GAMEPAD button);
 CP_BOOL CP_Input_GamepadDownAdvanced(CP_GAMEPAD button, unsigned gamepadIndex);
 float CP_Input_GamepadRightTrigger(void);
 float CP_Input_GamepadRightTriggerAdvanced(unsigned gamepadIndex);
 float CP_Input_GamepadLeftTrigger(void);
 float CP_Input_GamepadLeftTriggerAdvanced(unsigned gamepadIndex);
 CP_Vector CP_Input_GamepadRightStick(void);
 CP_Vector CP_Input_GamepadRightStickAdvanced(unsigned gamepadIndex);
 CP_Vector CP_Input_GamepadLeftStick(void);
 CP_Vector CP_Input_GamepadLeftStickAdvanced(unsigned gamepadIndex);
 CP_BOOL CP_Input_GamepadConnected(void);
 CP_BOOL CP_Input_GamepadConnectedAdvanced(unsigned gamepadIndex);

//---------------------------------------------------------
// MATH:
//		Mathematical support functions
 int CP_Math_ClampInt(int value, int min, int max);
 float CP_Math_ClampFloat(float value, float min, float max);
 int CP_Math_LerpInt(int a, int b, float lerpFactor);
 float CP_Math_LerpFloat(float a, float b, float lerpFactor);
 float CP_Math_Square(float value);
 float CP_Math_Distance(float x1, float y1, float x2, float y2);
 float CP_Math_Degrees(float radians);
 float CP_Math_Radians(float degrees);
 void CP_Math_ScreenToWorld(float xIn, float yIn, float* xOut, float* yOut);
 void CP_Math_WorldToScreen(float xIn, float yIn, float* xOut, float* yOut);

//---------------------------------------------------------
// VECTOR:
//		Create, set and use vector for basic 2D linear algebra
 CP_Vector CP_Vector_Set(float x, float y);
 CP_Vector CP_Vector_Zero(void);
 CP_Vector CP_Vector_Negate(CP_Vector vec);
 CP_Vector CP_Vector_Add(CP_Vector a, CP_Vector b);
 CP_Vector CP_Vector_Subtract(CP_Vector a, CP_Vector b);
 CP_Vector CP_Vector_Scale(CP_Vector vec, float scale);
 CP_Vector CP_Vector_Normalize(CP_Vector vec);
 CP_Vector CP_Vector_MatrixMultiply(CP_Matrix mat, CP_Vector vec);
 float CP_Vector_Length(CP_Vector vec);
 float CP_Vector_Distance(CP_Vector a, CP_Vector b);
 float CP_Vector_DotProduct(CP_Vector a, CP_Vector b);
 float CP_Vector_CrossProduct(CP_Vector a, CP_Vector b);
 float CP_Vector_Angle(CP_Vector a, CP_Vector b);
 float CP_Vector_AngleCW(CP_Vector from, CP_Vector to);
 float CP_Vector_AngleCCW(CP_Vector from, CP_Vector to);

//---------------------------------------------------------
// MATRIX:
//		Create, set and use matrix for basic 2D linear algebra
CP_Matrix CP_Matrix_Set(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);
CP_Matrix CP_Matrix_Identity(void);
CP_Matrix CP_Matrix_FromVector(CP_Vector col1, CP_Vector col2, CP_Vector col3);
CP_Matrix CP_Matrix_Scale(CP_Vector scale);
CP_Matrix CP_Matrix_Translate(CP_Vector offset);
CP_Matrix CP_Matrix_Rotate(float degrees);
CP_Matrix CP_Matrix_RotateRadians(float radians);
CP_Matrix CP_Matrix_Transpose(CP_Matrix original);
CP_Matrix CP_Matrix_Inverse(CP_Matrix original);
 CP_Matrix CP_Matrix_Multiply(CP_Matrix a, CP_Matrix b);

//---------------------------------------------------------
// RANDOM:
//		Random number generation including Gaussian distribution and Perlin noise
CP_BOOL CP_Random_GetBool (void);
unsigned int CP_Random_GetInt(void);
unsigned int CP_Random_RangeInt(unsigned int lowerBound, unsigned int upperBound);
float CP_Random_GetFloat(void);
float CP_Random_RangeFloat(float lowerBound, float upperBound);
void CP_Random_Seed(int seed);
float CP_Random_Gaussian(void);
float CP_Random_Noise(float x, float y, float z);
void CP_Random_NoiseSeed(int seed);

 */
 
#ifdef __cplusplus
}
#endif
