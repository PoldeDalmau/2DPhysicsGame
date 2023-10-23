#include <SFML/Graphics.hpp>
#include "Circle.h"
#include "CircleManager.h"
#include "Car.h"
#include <iostream>

int main()
{
    // Variable initializations
    const float deltaTime = 0.01f;
    float screenHeight = 720;
    float screenWidth = 1280;
    float marginWidth = 280; // margin to display real time stats
    float wallxPosition = screenWidth - marginWidth;
    float wallxVelocity = 0;
    vector<std::string> stats;
    // Screen initialization
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "Physics SandBox");
    // Class initializations
    Car car(screenWidth, screenHeight, deltaTime, window, 0.1, 40);
    //CircleManager cman(screenWidth, screenHeight, deltaTime, window);

    sf::Font font;

    if (!font.loadFromFile(("C:/Users/polde/OneDrive/Desktop/Projects/2DPhysicsGame/sfml/VCR_OSD_MONO_1.001.ttf"))) { // C:/Users/polde/OneDrive/Desktop/Projects/2DPhysicsGame
        // Handle font loading error
        std::cout << "Error loading .ttf file for font" << std::endl;
        system("pause");
    }


    //window.setFramerateLimit(64);

    sf::Clock clock;
    sf::Time elapsed2 = clock.getElapsedTime();

    // rectangle that represents moving wall
    sf::RectangleShape rectangle(sf::Vector2f(1, screenHeight));
    rectangle.setFillColor(sf::Color::White);
    rectangle.setPosition(sf::Vector2f(wallxPosition, 0));
    int moveSpeed = 100;
    
    int numRowsMSS = 3;
    int numColsMSS = 3;
    float latticeConstantMSS = 50;
    float radiusMSS = 20;
    float massMSS = 20;
    //cman.initializeMassSpringSystem(numColsMSS, numRowsMSS, latticeConstantMSS, radiusMSS, massMSS);
    //cman.AddCirclesMesh(4, 41, 20);
    //cman.AddCircle(Circle(20, 100, 200, 0, 0, 0, 50));
    //cman.AddCircle(Circle(20, 180, 200, 0, 0, 1, 50,sf::Color::Blue));
    //cman.AddCircle(Circle(5, 290, 100, 100, -35, 10, 10, sf::Color::Red));
    //cman.AddCircle(Circle(10, 290, 290, 0, 0));
    //cman.AddCircle(Circle(10, 100, 290, 0, 0));

    while (window.isOpen())
    {
        sf::Time elapsed1 = clock.getElapsedTime();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                ////spin wheel
                if (event.key.code == sf::Keyboard::D)
                    car.turnWheel(-1);
                if (event.key.code == sf::Keyboard::A)
                    car.turnWheel(1);
                if (event.key.code == sf::Keyboard::Space)
                    car.jump();
                if (event.key.code == sf::Keyboard::V)
                    car.drawSprings();


            //    Allows to move wall
            //    if (event.key.code == sf::Keyboard::A) {
            //        // Move the rectangle left
            //        rectangle.move(-moveSpeed * deltaTime, 0.0f);
            //        wallxPosition -= moveSpeed * deltaTime;
            //        wallxVelocity = -moveSpeed;
            //    }
            //    else if (event.key.code == sf::Keyboard::D) {
            //        // Move the rectangle right
            //        rectangle.move(moveSpeed * deltaTime, 0.0f);
            //        wallxPosition += moveSpeed * deltaTime;
            //        wallxVelocity = moveSpeed;
            //    }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    window.close();
            }
        }

        window.clear();

        //cman.handleSpringSystem(numColsMSS, numRowsMSS, latticeConstantMSS);
        //wallxVelocity = 0;

        car.Gravity(10);
        //cman.SpringLink(0, 1, 200, 10);
        //cman.UpdateAll();
        car.updateCar();

        car.DrawAll();
        //cman.DrawAll();
        sf::Time elapsed2 = clock.getElapsedTime();



        // output stats to sf window
        //cman.makeVelocityHistogram(30, 25);

        //stats = cman.getStats();
        //sf::Text text;
        //text.setString("\nNumber of particles: " + stats[0] + 
        //    "\nInternal Energy:\n" + stats[1] + 
        //    "\nVelocity of red particle: \n" + stats[2] + 
        //    "\nFrame update time: " + std::to_string(elapsed2.asMilliseconds() - elapsed1.asMilliseconds()) + " ms");
        //text.setCharacterSize(16);
        //text.setFillColor(sf::Color::White);
        //text.setPosition(screenWidth - marginWidth + 25, 5.00f);
        //text.setFont(font);
        //window.draw(text);


        //window.draw(rectangle);
        window.display();
    }

    return 0;
}
