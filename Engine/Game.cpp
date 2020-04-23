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

Game::Game(MainWindow& wnd)
    :
    wnd(wnd),
    gfx(wnd),
    player1(20, 300, Colors::Cyan, 20, 20, Colors::Yellow),
    player2(Graphics::ScreenWidth - 40, 300, Colors::Red, Graphics::ScreenWidth - 150, 20, Colors::Blue)


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
        //Goal Scored Logic

        int ballRight = ball.x + ball.width;

        if (ball.x <= goalLineP1)
        {
            goalScoredP2 = true;
        }
        else if (ballRight >= goalLineP2)
        {
            goalScoredP1 = true;
        }


        //If No Goal Has Been Scored:

        if (goalScoredP1 == false || goalScoredP2 == false)
        {

            //ball gets velocity

            ball.x += ball.vx;
            ball.y += ball.vy;




            //logic to move the paddles

                    //Player One Logic

            if (wnd.kbd.KeyIsPressed('S'))
            {
                player1.y += 7;
            }

            if (wnd.kbd.KeyIsPressed('W'))
            {
                player1.y -= 7;
            }



            //Player Two Logic

            if (wnd.kbd.KeyIsPressed(VK_UP))
            {
                player2.y -= 7;
            }

            if (wnd.kbd.KeyIsPressed(VK_DOWN))
            {
                player2.y += 7;
            }

            //Players clamp to screen

            player1.ClampScreenX();
            player2.ClampScreenX();



            //Collision and rebound for ball

            ball.ClampToScreen();


            if
                (ball.CollisionDetect(player1.x, player1.y, player1.width, player1.height))
            {
                ball.vx = -ball.vx;
            }

            if (ball.CollisionDetect(player2.x, player2.y, player2.width, player2.height))
            {
                ball.vx = -ball.vx;
            }

        }


        // If Player One Scores A Goal:
        if (goalScoredP1 == true && player1.meterWidth > player1.scoreMax)
        {
            player1.meterWidth = player1.scoreMax;
            goalScoredP1 = false;
            gameOver = true;
        }
        else if (goalScoredP1 == true)
        
        {
            player1.meterWidth = player1.meterWidth + reward;
            goalScoredP1 = false;
        }

       
        if (goalScoredP2 == true && player2.meterWidth > player2.scoreMax)

        {
            player2.meterWidth = player2.scoreMax;
            goalScoredP2 = false;
            gameOver = true;
        }
        else if (goalScoredP2 == true)
        {
            player2.meterWidth = player2.meterWidth + reward;
            goalScoredP2 = false;
        }


    }
    
    else if (gameOver == true)
    {

    ball.vx = 0;
    ball.vy = 0;
    ball.x = gfx.ScreenWidth / 2;
    ball.y = gfx.ScreenHeight / 2;

   
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

        

        for (int i = 0; i < gfx.ScreenHeight; i++)
        {
            gfx.PutPixel(gfx.ScreenWidth / 2, i, Colors::Blue);
        }
       
        ball.Draw(gfx);
        player1.Draw(gfx);
        player2.Draw(gfx);
        player1.DrawBar(gfx);
        player2.DrawBar(gfx);

        
    }
   
  
}
