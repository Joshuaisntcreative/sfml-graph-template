#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <iostream>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    sf::Font font;
    if(font.openFromFile(".../font/DejaVuSans.ttf")){
        std::cerr << "Font failed to load :(";
        return -1;
    }
    // Each vertex holds a position and a color
    std::vector<sf::Vertex> gridLines;
    std::vector<sf::Text> labels;



    for (float x = 100; x < 700; x += 100)
    {
        gridLines.push_back({sf::Vector2f(x, 100), sf::Color(100, 100, 100)});
        gridLines.push_back({sf::Vector2f(x, 500), sf::Color(100, 100, 100)});

        sf::Text label(font);
        label.setString(std::to_string(x));
        label.setCharacterSize(14);
        label.setFillColor(sf::Color::White);
        label.setPosition({x - 10, 510}); // adjust position under axis
        labels.push_back(label);
    }

    for (float y = 500; y > 100; y-= 100){
// Horizontal grid lines
        gridLines.push_back({sf::Vector2f(100, y), sf::Color(100, 100, 100)});
        gridLines.push_back({sf::Vector2f(700, y), sf::Color(100, 100, 100)});

        // Y labels
        sf::Text label(font);
        label.setString(std::to_string(y));
        label.setCharacterSize(14);
        label.setFillColor(sf::Color::White);
        label.setPosition({60, y - 10}); // adjust position left of axis
        labels.push_back(label);
    }

    std::vector<sf::Vertex> xAxis = {
        {sf::Vector2f(100, 500), sf::Color::White},
        {sf::Vector2f(700, 500), sf::Color::White}};
    std::vector<sf::Vertex> yAxis = {
        {sf::Vector2f(100, 500), sf::Color::White},
        {sf::Vector2f(100, 100), sf::Color::White}};




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
        window.draw(gridLines.data(), gridLines.size(), sf::PrimitiveType::Lines);

        // Draw axes
        window.draw(xAxis.data(), xAxis.size(), sf::PrimitiveType::Lines);
        window.draw(yAxis.data(), yAxis.size(), sf::PrimitiveType::Lines);

        // Draw labels
        for (const auto &label : labels)
        {
            window.draw(label);
        }
        window.display();
    }
}