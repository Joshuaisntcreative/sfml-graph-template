#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u,600u}), "CMake SFML Project");
    window.setFramerateLimit(144);
//Each vertex holds a position and a color
std::vector<sf::Vertex> graphPoints;
    for (float x = 0; x < 800; x += 1) {
        float y = 300 + std::sin(x * 0.01f) * 100;  // sine wave centered at y = 300
        graphPoints.push_back({sf::Vector2f(x, y), sf::Color::Green});
    }
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(&graphPoints[0], graphPoints.size(), sf::PrimitiveType::LineStrip);   
        window.display();
    }
}