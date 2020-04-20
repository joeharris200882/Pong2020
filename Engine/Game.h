/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */

    //Paddles
    int p1x = 20;
    int p1y = gfx.ScreenHeight / 2;
    const int p1Width = 10;
    const int p1Height = 70;

    int p2x = gfx.ScreenWidth - 40;
    int p2y = gfx.ScreenHeight / 2;
    const int p2Width = 10;
    const int p2Height = 70;

    //Goals
   const int goal1x = 1;
   const int goal1y = gfx.ScreenHeight/3;
   const int goal1Width = 5;
   const int goal1Height = 150;

    const int goal2x = gfx.ScreenWidth -7;
    const int goal2y = gfx.ScreenHeight / 3;
    const int goal2Width = 5;
    const int goal2Height = 150;
        
    //Ball
    int ballx = gfx.ScreenWidth/2;
    int bally = gfx.ScreenHeight/2;
    const int ballHeight = 5;
    const int ballWidth = 5;
    int ballVx = 4;
    int ballVy = 4;  

    //score meter
    int scorex = 10;
    int scorey = 10;
    int scoreWidth = 5;
    int scoreHeight = 10;
    int scoreTrack = 0;

    bool goalScored = false;
    bool collision = false;


	/********************************/
};