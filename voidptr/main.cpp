#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
 
 int main()
 {
     // Create the main window
     sf::RenderWindow App(sf::VideoMode(800, 600), "SFML window");
 
     // Load a sprite to display
     sf::Image Image;
     if (!Image.LoadFromFile("cute_image.jpg"))
         return EXIT_FAILURE;
     sf::Sprite Sprite(Image);
 
     // Create a graphical string to display
     sf::Font Arial;
     if (!Arial.LoadFromFile("arial.ttf"))
         return EXIT_FAILURE;
     sf::String Text("Hello SFML", Arial, 50);
 
     // Load a music to play
     sf::Music Music;
     if (!Music.OpenFromFile("nice_music.ogg"))
         return EXIT_FAILURE;

     // Play the music
     Music.Play();
 
     // Start the game loop
     while (App.IsOpened())
     {
         // Process events
         sf::Event Event;
         while (App.GetEvent(Event))
         {
             // Close window : exit
             if (Event.Type == sf::Event::Closed)
                 App.Close();
         }
 
         // Clear screen
         App.Clear();
 
         // Draw the sprite
         App.Draw(Sprite);
 
         // Draw the string
         App.Draw(Text);
 
         // Update the window
         App.Display();
     }
 
     return EXIT_SUCCESS;
 }