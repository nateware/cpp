/* 
 * File:   main.cpp
 * Author: nwiger
 *
 * Created on May 7, 2012, 6:11 PM
 */


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
 
using namespace std;

 int main()
 {
     // Create the main window
     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
 
     // Load a sprite to display
     sf::Texture texture;
     if (!texture.loadFromFile("nmm_coaster_gray.jpg"))
         return EXIT_FAILURE;
     sf::Sprite sprite(texture);
 
     // Create a graphical text to display
     sf::Font font;
     if (!font.loadFromFile("/Library/Fonts/Arial.ttf"))
         return EXIT_FAILURE;
     sf::Text text("Hello SFML", font, 50);
 
     // Load a music to play
//     sf::Music music;
//     if (!music.openFromFile("nice_music.ogg"))
//         return EXIT_FAILURE;

     // Play the music
     //music.play();

     char str[80];
     int i=0;
     float sx=0.f, sy=0.f;  // sprite position
 
     // Start the game loop
     while (window.isOpen())
     {
         // Process events
         sf::Event event;
         while (window.pollEvent(event))
         {
             // Close window : exit
             switch(event.type)
             {
                 case sf::Event::Closed:
                     window.close();
                     break;
             }
         }

         // Move the sprite around
         // One offset == one pixel, but moves so fast, we need
         // to use a smaller value
         float x=0.f, y=0.f;
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
             x -= 0.5; // move left
         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
             x += 0.5; // move right
         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
             y -= 0.5; // move up
         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
             sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
             y += 0.5; // move down

         bool animate_guy = false;
         if (x != 0 || y != 0)
             animate_guy = true;
         
         // Clear screen
         window.clear();
 
         sprite.move(x, y);

         // animation
         if (animate_guy)
         {
            sprintf(str, "animate(%d)=%f,%f\n", i, x, y);
            sf::Text animtext(str, font, 20);
            sf::Vector2f vec(0.f, 100.f);
            animtext.move(vec);
            window.draw(animtext);
         }
 
         // Draw the sprite
         window.draw(sprite);

         sx, sy = sprite.getPosition().x, sprite.getPosition().y;

            sprintf(str, "sprite=%f,%f\n", sx, sy);
            sf::Text sptxt(str, font, 20);
            sptxt.move(300.f, 0.f);
            window.draw(sptxt);


         // counter
         sprintf(str, "i=%d\n", i++);
         sf::Text countext(str, font, 10);
         sf::Vector2f vec(100.f, 100.f);
         countext.move(vec);
         window.draw(countext);

         
         // Draw the string
         window.draw(text);
 
         // Update the window
         window.display();
     }
 
     return EXIT_SUCCESS;
}