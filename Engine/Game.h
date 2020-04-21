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
#include "Score.h"
#include "Sprites.h"
#include "Ball.h"

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
    int p1y = gfx.ScreenHeight / 4;
    const int p1Width = 5;
    const int p1Height = 100;

    int p2x = gfx.ScreenWidth-30;
    int p2y =  gfx.ScreenWidth / 4;
    const int p2Width = 5;
    const int p2Height = 100;

        
    //Ball
    //int ballx = gfx.ScreenWidth/2;
    //int bally = gfx.ScreenHeight/2;
    //const int ballHeight = 5;
    //const int ballWidth = 5;
    //int ballVx = 5;
    //int ballVy = 5;  
    Ball ball;

    Score scoreP1;
    Score scoreP2;

    bool goalScored = false;
    bool collision = false;
    bool gameOver = false;
    bool ScoreMax = 50;
    const int  reward = 5;

    int goalScoredP1= gfx.ScreenWidth - 2;
    int goalScoredP2 = 1;

    Sprites GameOver;


	/********************************/
};