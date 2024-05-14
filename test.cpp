#include <SFML/Graphics.hpp>
#include <cmath>

class planet
{
    public:
        int x, y;
        double v_x, v_y, M;
};

sf::CircleShape setPlanet(planet obj)
{
    sf::CircleShape circle;

    circle.setRadius(50 / (1 + exp(-obj.M)) - 20);
    circle.setOrigin(circle.getRadius(), circle.getRadius());
    
    int r = std::rand(), g = std::rand(), b = std::rand();
    circle.setFillColor(sf::Color(r, g, b));
    circle.setOutlineColor(sf::Color(r, g, b));
    circle.setOutlineThickness(0);

    return circle;
}

void drawPlanet(planet obj, sf::CircleShape circle, sf::RenderWindow *window)
{
    sf::Vector2u size = (*window).getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;
    circle.setPosition((size.x / 2) + obj.x, (size.y / 2) - obj.y);

    (*window).draw(circle);
}

int main()
{
    std::srand(std::time(nullptr));

    sf::RenderWindow window(sf::VideoMode(1000, 500), "Test");
    window.setFramerateLimit(60);

    planet Earth;

    Earth.x = 0;
    Earth.y = 0;
    Earth.v_x = 0;
    Earth.v_y = 0;
    Earth.M = 10000;

    sf::CircleShape image = setPlanet(Earth);
    
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        window.clear();
        drawPlanet(Earth, image, &window);
        window.display();
    }

    return 0;
}
