/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
   
}


void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
    
    if (gameOver == false)
    {


        if (goalScored == false)
        {

            //ball gets velocity


            ballx += ballVx;
            bally += ballVy;

          


            //logic to move the paddles

                    //Player One Logic

                    if (wnd.kbd.KeyIsPressed('S'))
                    {
                        p1y += 5;
                    }

                    if (wnd.kbd.KeyIsPressed('W'))
                    {
                        p1y -= 5;
                    }

           

                      //Player Two Logic

                     if (wnd.kbd.KeyIsPressed(VK_UP))
                     {
                         p2y -= 5;
                     }

                     if (wnd.kbd.KeyIsPressed(VK_DOWN))
                     {
                         p2y += 5;
                     }

            


                        





                 //Clamps For Paddle One
                 if (p1y < 0)
                 {
                     p1y = 1;
                 }

                 if (p1y + p1Height > gfx.ScreenHeight)
                 {
                     p1y = (gfx.ScreenHeight - p1Height) - 1;
                 }

          

                  //Clamps For Paddle 2
                 if (p2y < 0)
                 {
                     p2y = 1;
                 }

                 if (p2y + p2Height > gfx.ScreenHeight)
                 {
                     p2y = (gfx.ScreenHeight - p2Height) - 1;

                 }


            



            //Collision and rebound for ball

                             const int ballright = ballx + ballWidth;
                             if (ballx < 0)
                             {
                                 ballx = 0;
                                 ballVx = -ballVx;
                             }
                             else if (ballright >= gfx.ScreenWidth)
                             {
                                 ballx = (gfx.ScreenWidth - 1) - ballWidth;
                                 ballVx = -ballVx;
                             }

                             const int ballbottom = bally + ballHeight;
                             if (bally < 0)
                             {
                                 bally = 0;
                                 ballVy = -ballVy;
                             }
                             else if (ballbottom >= gfx.ScreenHeight)
                             {
                                 bally = (gfx.ScreenHeight - 1) - ballHeight;
                                 ballVy = -ballVy;
                             }


            //collision of ball with paddles

            const int ballBottom = bally + ballHeight;
            const int p1right = p1x + p1Width;
            const int p1Bottom = p1y + p1Height;
            const int p2right = p2x + p2Width;
            const int p2Bottom = p2y + p2Height;

            if (ballx < p1right &&
                ballright > p1x&&
                bally < p1Bottom &&
                ballBottom > p1y

                ||

                ballright > p2x&&
                ballx < p2right &&
                bally < p2Bottom &&
                ballBottom > p2y)

            {
                collision = true;
                ballVx = -ballVx;
            }


            else
            {
                collision = false;
            }

            if (ballx + ballWidth >= goalScoredP1 || ballx < goalScoredP1)
            {

                goalScored = true;
            }
            else { goalScored == false; }

        }

     
        

        if (goalScored == true)
        {

            if (scoreP1.scoreP1Track > ScoreMax)
            {
                scoreP1.scoreP1BarEnd = ScoreMax;
                //goalScored = false;
                ballx = Graphics::ScreenWidth / 2;
                bally = Graphics::ScreenHeight / 2;
                ballVx = 0;
                ballVy = 0;
                gameOver = true;
            }
            else if (scoreP2.scoreP2Track > ScoreMax)
            {
                scoreP2.scoreP2BarEnd = ScoreMax;
                //goalScored = false;
                ballx = Graphics::ScreenWidth / 2;
                bally = Graphics::ScreenHeight / 2;
                ballVx = 0;
                ballVy = 0;
                gameOver = true;
            }

            else
            {
                scoreP1.scoreP1Track = scoreP1.scoreP1Track + reward;
                scoreP1.scoreP1BarEnd = scoreP1.scoreP1BarEnd + scoreP1.scoreP1Track;
                goalScored = false;
                gameOver = false;
            }
        }
    }
    else if (gameOver == true)
    {

    ballVx = 0;
    ballVy = 0;
    ballx = gfx.ScreenWidth / 2;
    bally = gfx.ScreenHeight / 2;

    //Clamps for GameOver

    if (GameOver.x <= 1)
    {
        GameOver.vx = -GameOver.vx;

    }

    if (GameOver.x + 40 >= gfx.ScreenWidth)
    {
        GameOver.vx = -GameOver.vx;
    }

    if (GameOver.y <= 0)
    {
        GameOver.vy = -GameOver.vy;

    }

    if (GameOver.y + 40 >= gfx.ScreenHeight)
    {
        GameOver.vy = -GameOver.vy;
    }
    
    
    //GameOver gets velocity
    GameOver.x += GameOver.vx;
    GameOver.y += GameOver.vy;
    

     }

 }

     
   
   


void Game::ComposeFrame()
{
    if (gameOver == true)
    {

        GameOver.GameOver(gfx);
    }

    else if (gameOver == false)
    {

        // Score Meter - Player One
        scoreP1.DrawP1(gfx);
        scoreP2.DrawP2(gfx);

        for (int i = 0; i < gfx.ScreenHeight; i++)
        {
            gfx.PutPixel(gfx.ScreenWidth / 2, i, Colors::Blue);
        }






        //paddles
        gfx.DrawRectDim(p1x, p1y, p1Width, p1Height, Colors::White);
        gfx.DrawRectDim(p2x, p2y, p2Width, p2Height, Colors::White);




        gfx.DrawRectDim(ballx, bally, ballWidth, ballHeight, Colors::Red);

        //GameOver
    }
   
  
}
