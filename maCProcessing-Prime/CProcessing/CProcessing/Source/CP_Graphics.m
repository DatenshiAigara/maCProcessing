//------------------------------------------------------------------------------
// file:	CP_Graphics.m
// author:	Hazel Benting
// brief:	Manipulate and draw basic vector shapes
//
// Copyright � 2026DigiPen, All rights reserved.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Include Files:
//------------------------------------------------------------------------------

#include "cprocessing.h"
#include "Internal_System.h"

//------------------------------------------------------------------------------
// Defines and Internal Variables:
//-----------------------------------------------------------------------------------------------------------------------------------------------------------


//static bool firstVertex = true;

//------------------------------------------------------------------------------
// Internal Functions:
//------------------------------------------------------------------------------

static void CP_Graphics_DrawRectInternal(float x, float y, float w, float h, float degrees, float cornerRadius)
{
	//Draw a rectangle
}

//------------------------------------------------------------------------------
// Library Functions:
//------------------------------------------------------------------------------

void CP_Graphics_ClearBackground(CP_Color c)
{
	//Wipes all color from screen
}

void CP_Graphics_DrawPoint(float x, float y)
{
	//draw a point
}

void CP_Graphics_DrawLine(float x1, float y1, float x2, float y2)
{
	//draw a line
}

void CP_Graphics_DrawLineAdvanced(float x1, float y1, float x2, float y2, float degrees)
{
	//better draw line
}

void CP_Graphics_DrawRect(float x, float y, float w, float h)
{
	CP_Graphics_DrawRectInternal(x, y, w, h, 0, 0);
}

void CP_Graphics_DrawRectAdvanced(float x, float y, float w, float h, float degrees, float cornerRadius)
{
	CP_Graphics_DrawRectInternal(x, y, w, h, degrees, cornerRadius);
}

void CP_Graphics_DrawCircle(float x, float y, float d)
{
	CP_Graphics_DrawEllipse(x, y, d, d);
}

void CP_Graphics_DrawEllipse(float x, float y, float w, float h)
{
	//Draw Ellipse
}

void CP_Graphics_DrawEllipseAdvanced(float x, float y, float w, float h, float degrees)
{
	//Better Draw Ellipse
}

void CP_Graphics_DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
	//Draw Triangle
}

void CP_Graphics_DrawTriangleAdvanced(float x1, float y1, float x2, float y2, float x3, float y3, float degrees)
{
	//Better Draw Triangle
}

//////////////////////////////////////////////////////////////////////////////////////
//  QUAD                                                                            //
//                                                                                  //
//  A quad is a quadrilateral, a four sided polygon. It is similar to a rectangle,  //
//  but the angles between its edges are not constrained to ninety degrees. The     //
//  first pair of parameters (x1,y1) sets the first vertex and the subsequent pairs //
//  should proceed clockwise or counter-clockwise around the defined shape.         //
//////////////////////////////////////////////////////////////////////////////////////
void CP_Graphics_DrawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	//Draw Quad
}

void CP_Graphics_DrawQuadAdvanced(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float degrees)
{
	//Better Draw Quad
}

void CP_Graphics_BeginShape(void)
{
	//Shape
}

void CP_Graphics_AddVertex(float x, float y)
{
	//Vertex
}

void CP_Graphics_EndShape(void)
{
	//End Shape
}
