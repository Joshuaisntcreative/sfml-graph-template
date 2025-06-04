#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    sf::Font font;
    font.openFromFile(".../font/ARIAL.TTF");
    // Each vertex holds a position and a color
    std::vector<sf::Vertex> xAxis;
    std::vector<sf::Vertex> yAxis;

    

    for (float x = 100; x < 700; x += 100)
    {
        float y = 500;
        xAxis.push_back({sf::Vector2f(x, y), sf::Color::White});
    }

    for (float y = 500; y > 100; y-= 100){
        float x = 100;
        yAxis.push_back({sf::Vector2f(x,y), sf::Color::White});
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
        window.draw(&xAxis[0], xAxis.size(), sf::PrimitiveType::LineStrip);
        window.draw(&yAxis[0], yAxis.size(), sf::PrimitiveType::LineStrip);   
        window.display();
    }
}