#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <cstdlib>

void populate_Colors(std::vector<sf::Color> &colors){
    colors.push_back(sf::Color::White);
    colors.push_back(sf::Color::Red);
    colors.push_back(sf::Color::Blue);
    colors.push_back(sf::Color::Yellow);
}

int main()
{

    srand(time(0));
    auto window = sf::RenderWindow(sf::VideoMode({800u, 600u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    std::vector<sf::CircleShape> arrays;
    std::vector<sf::Color> colors;
    populate_Colors(colors);
    std::vector<sf::Vector2f> clusters;
    int clusterCount = 3;



    //creates the clusters that the data will clump around.
    for(int i = 0; i < clusterCount; i++){
        float xPosition = rand() % 401 + 100;
        float yPosition = rand() % 301 + 100;

        sf::Vector2 centroid = sf::Vector2(xPosition,yPosition);
        clusters.push_back(centroid);
    }

    for(int j = 0; j < 100; j++){
        //selects one of the random centroids in the vector clusters
        int cluster = rand() % clusters.size();
        float xPointPosition = clusters[cluster].x + static_cast<float>(rand() % 81 - 30);
        float yPointPosition = clusters[cluster].y + static_cast<float>(rand() % 81 - 30);
        
        sf::CircleShape p;
        p.setPosition({xPointPosition,yPointPosition});
        p.setFillColor(sf::Color::White);
        p.setOutlineColor(sf::Color::Black);
        p.setRadius(10);
        p.setOutlineThickness(.5);
        arrays.push_back(p);

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
        
        window.clear();
        for (auto circle : arrays){
            window.draw(circle);
        }
        window.display();
    }
}
